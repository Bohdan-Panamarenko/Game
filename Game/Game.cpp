#include "Field.h"

int main()
{
    system("chcp 1251>nul");
    system("color F0");
    Field A;
    for (int i = 8; i >= 0; i--) {
        for (int j = 8; j >= 0; j--) {
            A.checkD(j, i, true);
        }
    }
}
