#include "Field.h"

Field::Field() {
    steps = 0;
    colNum = 1;
    int fld[9][9] = {
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
            els[i][j].num = fld[i][j];
        }
    }
}

void Field::show() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0, j = 0; i < 9; i++) {
        cout << ' ';
        for (j = 0; j < 9; j++) {
            SETCOLOR(els[i][j].col);
            cout << els[i][j].num << ' ';
        }
        cout << endl;
    }
    cout << '<';
    for (int n = 0; n < 17; n++) cout << '-';
    cout << '>';
    cout << endl;
}

bool Field::seekDownRight(int i, int j, bool debug, bool isFirst) {
    if (isFirst && els[i][j].num != 1 && els[i][j].num != 0) return false;
    if (els[i][j].col != color::black) { // проверка на пересечение
        return false;
    }
    if (els[i][j].num == 9) { // цифра девять завершает цепочку
        els[i][j].col = colList[colNum];
        return true;
    }
    if (els[i][j].num == 0) { // если начальный элемент равняется нулю, то изменяем его на единицу
        els[i][j].num = 1;
        if (!seekDownRight(i, j, debug)) { // если цепочка не была сформирована, возвращаем как было
            els[i][j].num = 0;
            return false;
        }
        else return true;
    }
    int x = 0, y = 0, left, right, bottom, top;
    bool isZero = false;

    els[i][j].col = colList[colNum];
    // размечаем границы для поиска следующего элемента в цепочке

    if (debug) show();

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

    // поиск следующего элемента в выделенной области
    for (y = top; y <= bottom; y++) {
        for (x = left; x <= right; x++) {

            if (els[y][j].col == color::black || els[i][x].col == color::black) { // проверка на перпендикулярное пересечение
                if (els[y][x].col == color::black && (els[y][x].num == els[i][j].num + 1 || (isZero = (els[y][x].num == 0)))) {
                    if (isZero) els[y][x].num = els[i][j].num + 1;
                    if (seekDownRight(y, x, debug, false)) {
                        if (!isFirst) return true;
                        else {    // если по элементу было сформировано цепочку
                            show();
                            if (debug) system("pause>nul");
                            colNum++;
                            return true;
                        }
                    }
                    else {
                        
                        if (isZero) {
                            els[y][x].num = 0;
                        }
                    }
                }
            }


        }
    }
    els[i][j].col = color::black;
    return false;
}

bool Field::seekDownLeft(int i, int j, bool debug, bool isFirst) {
    if (isFirst && els[i][j].num != 1 && els[i][j].num != 0) return false;
    if (els[i][j].col != color::black) { // проверка на пересечение
        return false;
    }
    if (els[i][j].num == 9) { // цифра девять завершает цепочку
        els[i][j].col = colList[colNum];
        return true;
    }
    if (els[i][j].num == 0) { // если начальный элемент равняется нулю, то изменяем его на единицу
        els[i][j].num = 1;
        if (!seekDownLeft(i, j, debug)) { // если цепочка не была сформирована, возвращаем как было
            els[i][j].num = 0;
            return false;
        }
        else return true;
    }
    int x = 0, y = 0, left, right, bottom, top;
    bool isZero = false;

    els[i][j].col = colList[colNum];
    // размечаем границы для поиска следующего элемента в цепочке

    if (debug) show();

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

    // поиск следующего элемента в выделенной области
    for (y = top; y <= bottom; y++) {
        for (x = right; x >= left; x--) {

            if (els[y][j].col == color::black || els[i][x].col == color::black) { // проверка на перпендикулярное пересечение
                if (els[y][x].col == color::black && (els[y][x].num == els[i][j].num + 1 || (isZero = (els[y][x].num == 0)))) {
                    if (isZero) els[y][x].num = els[i][j].num + 1;
                    if (seekDownLeft(y, x, debug, false)) {
                        if (!isFirst) return true;
                        else {    // если по элементу было сформировано цепочку
                            show();
                            if (debug) system("pause>nul");
                            colNum++;
                            return true;
                        }
                    }
                    else {

                        if (isZero) {
                            els[y][x].num = 0;
                        }
                    }
                }
            }


        }
    }
    els[i][j].col = color::black;
    return false;
}

bool Field::seekUpRight(int i, int j, bool debug, bool isFirst) {
    if (isFirst && els[i][j].num != 1 && els[i][j].num != 0) return false;
    if (els[i][j].col != color::black) { // проверка на пересечение
        return false;
    }
    if (els[i][j].num == 9) { // цифра девять завершает цепочку
        els[i][j].col = colList[colNum];
        return true;
    }
    if (els[i][j].num == 0) { // если начальный элемент равняется нулю, то изменяем его на единицу
        els[i][j].num = 1;
        if (!seekUpRight(i, j, debug)) { // если цепочка не была сформирована, возвращаем как было
            els[i][j].num = 0;
            return false;
        }
        else return true;
    }
    int x = 0, y = 0, left, right, bottom, top;
    bool isZero = false;

    els[i][j].col = colList[colNum];
    // размечаем границы для поиска следующего элемента в цепочке

    if (debug) show();

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

    // поиск следующего элемента в выделенной области
    for (y = bottom; y >= top; y--) {
        for (x = left; x <= right; x++) {

            if (els[y][j].col == color::black || els[i][x].col == color::black) { // проверка на перпендикулярное пересечение
                if (els[y][x].col == color::black && (els[y][x].num == els[i][j].num + 1 || (isZero = (els[y][x].num == 0)))) {
                    if (isZero) els[y][x].num = els[i][j].num + 1;
                    if (seekUpRight(y, x, debug, false)) {
                        if (!isFirst) return true;
                        else {    // если по элементу было сформировано цепочку
                            show();
                            if (debug) system("pause>nul");
                            colNum++;
                            return true;
                        }
                    }
                    else {

                        if (isZero) {
                            els[y][x].num = 0;
                        }
                    }
                }
            }


        }
    }
    els[i][j].col = color::black;
    return false;
}

bool Field::seekUpLeft(int i, int j, bool debug, bool isFirst) {
    if (isFirst && els[i][j].num != 1 && els[i][j].num != 0) return false;
    if (els[i][j].col != color::black) { // проверка на пересечение
        return false;
    }
    if (els[i][j].num == 9) { // цифра девять завершает цепочку
        els[i][j].col = colList[colNum];
        return true;
    }
    if (els[i][j].num == 0) { // если начальный элемент равняется нулю, то изменяем его на единицу
        els[i][j].num = 1;
        if (!seekUpLeft(i, j, debug)) { // если цепочка не была сформирована, возвращаем как было
            els[i][j].num = 0;
            return false;
        }
        else return true;
    }
    int x = 0, y = 0, left, right, bottom, top;
    bool isZero = false;

    els[i][j].col = colList[colNum];
    // размечаем границы для поиска следующего элемента в цепочке

    if (debug) show();

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

    // поиск следующего элемента в выделенной области
    for (y = bottom; y >= top; y--) {
        for (x = right; x >= left; x--) {

            if (els[y][j].col == color::black || els[i][x].col == color::black) { // проверка на перпендикулярное пересечение
                if (els[y][x].col == color::black && (els[y][x].num == els[i][j].num + 1 || (isZero = (els[y][x].num == 0)))) {
                    if (isZero) els[y][x].num = els[i][j].num + 1;
                    if (seekUpLeft(y, x, debug, false)) {
                        if (!isFirst) return true;
                        else {    // если по элементу было сформировано цепочку
                            show();
                            if (debug) system("pause>nul");
                            colNum++;
                            return true;
                        }
                    }
                    else {

                        if (isZero) {
                            els[y][x].num = 0;
                        }
                    }
                }
            }


        }
    }
    els[i][j].col = color::black;
    return false;
}