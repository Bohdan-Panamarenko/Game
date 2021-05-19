#include "Field.h"

Field::Field() {
    colNum_ = 1; // починаємо з синього кольору
    traversFunc_ = &Field::traverseDownRight; // за замовчуванням використовується обхід згори-вниз і зліва-направо
    const int fld[9][9] = { // початкове поле у вигляді двомірного масиву цілих чисел
    {1, 0, 6, 0, 0, 2, 0, 7, 0},
    {0, 9, 6, 6, 0, 3, 0, 5, 0},
    {4, 6, 7, 0, 8, 4, 9, 0, 0},
    {0, 0, 8, 0, 0, 7, 4, 8, 1},
    {9, 0, 2, 5, 0, 4, 0, 8, 3},
    {3, 0, 7, 9, 0, 1, 8, 6, 0},
    {0, 2, 1, 7, 6, 0, 3, 4, 0},
    {6, 9, 0, 5, 2, 0, 1, 7, 2},
    {5, 4, 0, 3, 1, 5, 0, 5, 9}
    };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            els_[i][j].num_ = fld[i][j];
        }
    }
}  

void Field::show() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // отримуємо дескриптор вікна
    for (int i = 0, j = 0; i < 9; i++) {
        cout << ' ';
        for (j = 0; j < 9; j++) {
            SETCOLOR(els_[i][j].col_); // змінюємо колір перед виводом кожного символу
            cout << els_[i][j].num_ << ' ';
        }
        cout << endl;
    }
    SETCOLOR(color::black); // після завершення виводу змінюємо колір на чорний
    cout << '<';
    for (int n = 0; n < 17; n++) cout << '-'; // виводимо роздільну лінію
    cout << '>';
    cout << endl;
}

bool Field::checkElem(int i, int j, int x, int y, bool bDebug, bool bIsFirst)
{
    bool bIsZero = false; // чи був елемент нулем
    if (els_[y][j].col_ == color::black || els_[i][x].col_ == color::black) { // перевірка на перпендикулярний перетин
        if (els_[y][x].col_ == color::black && (els_[y][x].num_ == els_[i][j].num_ + 1 || (bIsZero = (els_[y][x].num_ == 0)))) { // перевірка кандидата
            if (bIsZero) els_[y][x].num_ = els_[i][j].num_ + 1; // якщо кандидат містить число 0, то змінюємо його на необхідне
            if (build(y, x, bDebug, false)) { // якщо знайдено наступний елемент
                if (!bIsFirst) return true; // і це не початковий елемент, то повертаємо true
                else {    // і це перший елемент, то послідовність побудовано
                    show();
                    if (bDebug) system("pause>nul"); // режим ретельного огляду
                    colNum_++;
                    return true;
                }
            }
            else {

                if (bIsZero) { // якщо послідовність не побудовано і елемент був нулем, то повертаємо йому значення
                    els_[y][x].num_ = 0;
                }
            }
        }
    }
    return false; // якщо наступний елемент не знайдено, повертаємо false
}

bool Field::build(int i, int j, bool bDebug, bool bIsFirst) {
    if (bIsFirst && els_[i][j].num_ != 1 && els_[i][j].num_ != 0) return false; // перевірка початкового елементу
    if (els_[i][j].num_ == 9) { // цифра дев'ять завершає послідовність
        els_[i][j].col_ = colList_[colNum_];
        return true;
    }
    if (bIsFirst && els_[i][j].num_ == 0) { // якщо початковий елемент дорівнює нулю, то змінюємо його на одиницю
        els_[i][j].num_ = 1;
        if (!build(i, j, bDebug)) { // якщо послідовність не було сформовано, повертаємо як було
            els_[i][j].num_ = 0;
            return false;
        }
        else return true;
    }
    int left, right, bottom, top;
    

    els_[i][j].col_ = colList_[colNum_]; // призначення кольору клітинці

    if (bDebug) show(); // режим ретельного огляду

    // розмітка границь дельта-поля
    if (i == 0) {
        top = 0;
        bottom = 1;
    }
    else if (i == 8) {
        top = 7;
        bottom = 8;
    }
    else {
        top = i - 1;
        bottom = i + 1;
    }

    if (j == 0) {
        left = 0;
        right = 1;
    }
    else if (j == 8) {
        left = 7;
        right = 8;
    }
    else {
        left = j - 1;
        right = j + 1;
    }

    // пошук наступного елементу в дельта-полі
    if ((this->*traversFunc_)(i, j, top, bottom, left, right, bDebug, bIsFirst)) return true; // обхід дельта-поля

    els_[i][j].col_ = color::black; // відміна кольорку, якщо не було побудовано послідовність
    return false; // повертаємо false, якщо не було побудовано послідовність
}

bool Field::traverseDownRight(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst)
{
    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {

            if (checkElem(i, j, x, y, bDebug, bIsFirst)) return true;

        }
    }
    return false;
}

bool Field::traverseDownLeft(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst)
{
    for (int y = top; y <= bottom; y++) {
        for (int x = right; x >= left; x--) {

            if (checkElem(i, j, x, y, bDebug, bIsFirst)) return true;

        }
    }
    return false;
}

bool Field::traverseUpRight(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst)
{
    for (int y = bottom; y >= top; y--) {
        for (int x = left; x <= right; x++) {

            if (checkElem(i, j, x, y, bDebug, bIsFirst)) return true;

        }
    }
    return false;
}

bool Field::traverseUpLeft(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst)
{
    for (int y = bottom; y >= top; y--) {
        for (int x = right; x >= left; x--) {

            if (checkElem(i, j, x, y, bDebug, bIsFirst)) return true;

        }
    }
    return false;
}