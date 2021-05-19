#include <iostream>
#include <Windows.h>
using namespace std;

enum class color { black = 0x0000, blue = 0x0001, green = 0x0002, red = 0x0004, yellow = 0x0006,  purple = 0x0005, skyBlue = 0x0003, white = 0x000f};

#define SETCOLOR(COLOR) SetConsoleTextAttribute(hConsole, (WORD)(((int)(color::white) << 4) | (int)COLOR));

class Field {
    class Elem { // вкладерий клас
    public:
        int num_;
        color col_;
        Elem() {
            num_ = 0;
            col_ = color::black;
        }
    };
    const color colList_[7] = { color::black, color::blue, color::green, color::red, color::yellow, color::purple, color::skyBlue }; // список кольорів

    Elem els_[9][9]; // початкове поле
    int colNum_; // колір наступної послідовності
    bool checkElem(int i, int j, int x, int y, bool bDebug, bool bIsFirst); // перевірка потенціального наступного елемента
protected: 
    bool (Field::*traversFunc_)(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst); // вказівник на функцію обходу дельта-поля

public:
    Field();
    void show(); // показати поле
    bool build(int i = 0, int j = 0, bool bDebug = false, bool bIsFirst = true); // головна функція побудови послідовності

    // фукнціїї обходу
    bool traverseDownRight(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);
    bool traverseDownLeft(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);
    bool traverseUpRight(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);
    bool traverseUpLeft(int i, int j, int top, int bottom, int left, int right, bool bDebug, bool bIsFirst);
};
  