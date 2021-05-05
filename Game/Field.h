#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

enum class color { black = 0x0000, blue = 0x0001, green = 0x0002, red = 0x0004, yellow = 0x0006,  purple = 0x0005, white = 0x000f};

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
public:
    Field();
    void show();
    bool check(int i = 0, int j = 0, bool isFirst = true);
};
