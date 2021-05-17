#include <iostream>
#include <Windows.h>
using namespace std;

enum class color { black = 0x0000, blue = 0x0001, green = 0x0002, red = 0x0004, yellow = 0x0006,  purple = 0x0005, skyBlue = 0x0003, white = 0x000f};

#define SETCOLOR(COLOR) SetConsoleTextAttribute(hConsole, (WORD)(((int)(color::white) << 4) | (int)COLOR));

class Field {
    class Elem {
    public:
        int num_;
        color col_;
        Elem() {
            num_ = 0;
            col_ = color::black;
        }
        Elem(int num, color col) {
            this->num_ = num;
            this->col_ = col;
        }
    };
    color colList_[7] = { color::black, color::blue, color::green, color::red, color::yellow, color::purple, color::skyBlue };

    Elem els_[9][9];
    int steps_;
    int colNum_;
public:
    Field();
    void show();
    bool seekDownRight(int i = 0, int j = 0, bool bDebug = false, bool bIsFirst = true);
    bool seekDownLeft(int i = 0, int j = 0, bool bDebug = false, bool bIsFirst = true);
    bool seekUpRight(int i = 0, int j = 0, bool bDebug = false, bool bIsFirst = true);
    bool seekUpLeft(int i = 0, int j = 0, bool bDebug = false, bool bIsFirst = true);
};
  