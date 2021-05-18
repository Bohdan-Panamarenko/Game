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
    };
    const color colList_[7] = { color::black, color::blue, color::green, color::red, color::yellow, color::purple, color::skyBlue };

    Elem els_[9][9];
    int colNum_;
    bool checkElem(int i, int j, int x, int y, bool bDebug, bool bIsFirst);
protected: 
    bool (Field::*traversFunc_)(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);

public:
    Field();
    void show();
    bool build(int i = 0, int j = 0, bool bDebug = false, bool bIsFirst = true);

    bool traverseDownRight(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);
    bool traverseDownLeft(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);
    bool traverseUpRight(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);
    bool traverseUpLeft(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);
};
  