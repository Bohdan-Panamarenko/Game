#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

enum class color { black = 0x0000, blue = 0x0001, green = 0x0002, red = 0x0004, yellow = 0x0006,  purple = 0x0005, skyBlue = 0x0003, white = 0x000f};

#define SETCOLOR(COLOR) SetConsoleTextAttribute(hConsole, (WORD)(((int)(color::white) << 4) | (int)COLOR));

class Field {
    class elem {
    public:
        int num;
        color col;
        elem() {
            num = 0;
            col = color::black;
        }
        elem(int num, color col) {
            this->num = num;
            this->col = col;
        }
    };
    elem els[9][9];
    int steps;
    int colNum;
public:
    Field();
    void show();
    bool checkA(int i = 0, int j = 0, bool debug = false, bool isFirst = true);
    bool checkB(int i = 0, int j = 0, bool debug = false, bool isFirst = true);
    bool checkC(int i = 0, int j = 0, bool debug = false, bool isFirst = true);
    bool checkD(int i = 0, int j = 0, bool debug = false, bool isFirst = true);
};
