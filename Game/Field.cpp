#include "Field.h"

Field::Field() {
    steps_ = 0;
    colNum_ = 1;
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
            els_[i][j].num_ = fld[i][j];
        }
    }
}  

void Field::show() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0, j = 0; i < 9; i++) {
        cout << ' ';
        for (j = 0; j < 9; j++) {
            SETCOLOR(els_[i][j].col_);
            cout << els_[i][j].num_ << ' ';
        }
        cout << endl;
    }
    cout << '<';
    for (int n = 0; n < 17; n++) cout << '-';
    cout << '>';
    cout << endl;
}

bool Field::seekDownRight(int i, int j, bool bDebug, bool bIsFirst) {
    if (bIsFirst && els_[i][j].num_ != 1 && els_[i][j].num_ != 0) return false;
    if (els_[i][j].col_ != color::black) { // �������� �� �����������
        return false;
    }
    if (els_[i][j].num_ == 9) { // ����� ������ ��������� �������
        els_[i][j].col_ = colList_[colNum_];
        return true;
    }
    if (els_[i][j].num_ == 0) { // ���� ��������� ������� ��������� ����, �� �������� ��� �� �������
        els_[i][j].num_ = 1;
        if (!seekDownRight(i, j, bDebug)) { // ���� ������� �� ���� ������������, ���������� ��� ����
            els_[i][j].num_ = 0;
            return false;
        }
        else return true;
    }
    int x = 0, y = 0, left, right, bottom, top;
    bool bIsZero = false;

    els_[i][j].col_ = colList_[colNum_];
    // ��������� ������� ��� ������ ���������� �������� � �������

    if (bDebug) show();

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

    // ����� ���������� �������� � ���������� �������
    for (y = top; y <= bottom; y++) {
        for (x = left; x <= right; x++) {

            if (els_[y][j].col_ == color::black || els_[i][x].col_ == color::black) { // �������� �� ���������������� �����������
                if (els_[y][x].col_ == color::black && (els_[y][x].num_ == els_[i][j].num_ + 1 || (bIsZero = (els_[y][x].num_ == 0)))) {
                    if (bIsZero) els_[y][x].num_ = els_[i][j].num_ + 1;
                    if (seekDownRight(y, x, bDebug, false)) {
                        if (!bIsFirst) return true;
                        else {    // ���� �� �������� ���� ������������ �������
                            show();
                            if (bDebug) system("pause>nul");
                            colNum_++;
                            return true;
                        }
                    }
                    else {
                        
                        if (bIsZero) {
                            els_[y][x].num_ = 0;
                        }
                    }
                }
            }


        }
    }
    els_[i][j].col_ = color::black;
    return false;
}

bool Field::seekDownLeft(int i, int j, bool bDebug, bool bIsFirst) {
    if (bIsFirst && els_[i][j].num_ != 1 && els_[i][j].num_ != 0) return false;
    if (els_[i][j].col_ != color::black) { // �������� �� �����������
        return false;
    }
    if (els_[i][j].num_ == 9) { // ����� ������ ��������� �������
        els_[i][j].col_ = colList_[colNum_];
        return true;
    }
    if (els_[i][j].num_ == 0) { // ���� ��������� ������� ��������� ����, �� �������� ��� �� �������
        els_[i][j].num_ = 1;
        if (!seekDownLeft(i, j, bDebug)) { // ���� ������� �� ���� ������������, ���������� ��� ����
            els_[i][j].num_ = 0;
            return false;
        }
        else return true;
    }
    int x = 0, y = 0, left, right, bottom, top;
    bool bIsZero = false;

    els_[i][j].col_ = colList_[colNum_];
    // ��������� ������� ��� ������ ���������� �������� � �������

    if (bDebug) show();

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

    // ����� ���������� �������� � ���������� �������
    for (y = top; y <= bottom; y++) {
        for (x = right; x >= left; x--) {

            if (els_[y][j].col_ == color::black || els_[i][x].col_ == color::black) { // �������� �� ���������������� �����������
                if (els_[y][x].col_ == color::black && (els_[y][x].num_ == els_[i][j].num_ + 1 || (bIsZero = (els_[y][x].num_ == 0)))) {
                    if (bIsZero) els_[y][x].num_ = els_[i][j].num_ + 1;
                    if (seekDownLeft(y, x, bDebug, false)) {
                        if (!bIsFirst) return true;
                        else {    // ���� �� �������� ���� ������������ �������
                            show();
                            if (bDebug) system("pause>nul");
                            colNum_++;
                            return true;
                        }
                    }
                    else {

                        if (bIsZero) {
                            els_[y][x].num_ = 0;
                        }
                    }
                }
            }


        }
    }
    els_[i][j].col_ = color::black;
    return false;
}

bool Field::seekUpRight(int i, int j, bool bDebug, bool bIsFirst) {
    if (bIsFirst && els_[i][j].num_ != 1 && els_[i][j].num_ != 0) return false;
    if (els_[i][j].col_ != color::black) { // �������� �� �����������
        return false;
    }
    if (els_[i][j].num_ == 9) { // ����� ������ ��������� �������
        els_[i][j].col_ = colList_[colNum_];
        return true;
    }
    if (els_[i][j].num_ == 0) { // ���� ��������� ������� ��������� ����, �� �������� ��� �� �������
        els_[i][j].num_ = 1;
        if (!seekUpRight(i, j, bDebug)) { // ���� ������� �� ���� ������������, ���������� ��� ����
            els_[i][j].num_ = 0;
            return false;
        }
        else return true;
    }
    int x = 0, y = 0, left, right, bottom, top;
    bool bIsZero = false;

    els_[i][j].col_ = colList_[colNum_];
    // ��������� ������� ��� ������ ���������� �������� � �������

    if (bDebug) show();

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

    // ����� ���������� �������� � ���������� �������
    for (y = bottom; y >= top; y--) {
        for (x = left; x <= right; x++) {

            if (els_[y][j].col_ == color::black || els_[i][x].col_ == color::black) { // �������� �� ���������������� �����������
                if (els_[y][x].col_ == color::black && (els_[y][x].num_ == els_[i][j].num_ + 1 || (bIsZero = (els_[y][x].num_ == 0)))) {
                    if (bIsZero) els_[y][x].num_ = els_[i][j].num_ + 1;
                    if (seekUpRight(y, x, bDebug, false)) {
                        if (!bIsFirst) return true;
                        else {    // ���� �� �������� ���� ������������ �������
                            show();
                            if (bDebug) system("pause>nul");
                            colNum_++;
                            return true;
                        }
                    }
                    else {

                        if (bIsZero) {
                            els_[y][x].num_ = 0;
                        }
                    }
                }
            }


        }
    }
    els_[i][j].col_ = color::black;
    return false;
}

bool Field::seekUpLeft(int i, int j, bool bDebug, bool bIsFirst) {
    if (bIsFirst && els_[i][j].num_ != 1 && els_[i][j].num_ != 0) return false;
    if (els_[i][j].col_ != color::black) { // �������� �� �����������
        return false;
    }
    if (els_[i][j].num_ == 9) { // ����� ������ ��������� �������
        els_[i][j].col_ = colList_[colNum_];
        return true;
    }
    if (els_[i][j].num_ == 0) { // ���� ��������� ������� ��������� ����, �� �������� ��� �� �������
        els_[i][j].num_ = 1;
        if (!seekUpLeft(i, j, bDebug)) { // ���� ������� �� ���� ������������, ���������� ��� ����
            els_[i][j].num_ = 0;
            return false;
        }
        else return true;
    }
    int x = 0, y = 0, left, right, bottom, top;
    bool bIsZero = false;

    els_[i][j].col_ = colList_[colNum_];
    // ��������� ������� ��� ������ ���������� �������� � �������

    if (bDebug) show();

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

    // ����� ���������� �������� � ���������� �������
    for (y = bottom; y >= top; y--) {
        for (x = right; x >= left; x--) {

            if (els_[y][j].col_ == color::black || els_[i][x].col_ == color::black) { // �������� �� ���������������� �����������
                if (els_[y][x].col_ == color::black && (els_[y][x].num_ == els_[i][j].num_ + 1 || (bIsZero = (els_[y][x].num_ == 0)))) {
                    if (bIsZero) els_[y][x].num_ = els_[i][j].num_ + 1;
                    if (seekUpLeft(y, x, bDebug, false)) {
                        if (!bIsFirst) return true;
                        else {    // ���� �� �������� ���� ������������ �������
                            show();
                            if (bDebug) system("pause>nul");
                            colNum_++;
                            return true;
                        }
                    }
                    else {

                        if (bIsZero) {
                            els_[y][x].num_ = 0;
                        }
                    }
                }
            }


        }
    }
    els_[i][j].col_ = color::black;
    return false;
}