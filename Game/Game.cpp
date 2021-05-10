#include "FieldWorker.h"

int main()
{
    system("chcp 1251>nul");
    system("color F0");
    char answ = 'y';
    do {
        FieldWorker A;
        cout << "Початкове поле:" << endl;
        A.show();
        cout << "\nВиберіть дію: " << endl;
        cout << "1. Налаштування обходу поля та алгоритму пошуку" << endl;
        cout << "2. Запустити вирішення головоломки зі стандартними налаштуваннями (4 змійки)" << endl;
        cout << "3. Вийти з програми" << endl;
        do {
            cout << "Ваша відповідь: ";
            cin >> answ;
            while (cin.get() != '\n'); // очистка буфера
            if (answ != '1' && answ != '2' && answ != '3') {
                cout << "**Некорректний ввід" << endl;
            }
            else break;
        } while (true);
        switch (answ) {
        case '1': 
            A.settings();
            break;
        case '2':
            A.start();
            break;
        case '3':
            return 0;
            break;
        }

        while (answ == '1') {
                    cout << "\nВиберіть дію: " << endl;
                    cout << "1. Налаштування обходу поля та алгоритму пошуку" << endl;
                    cout << "2. Запустити вирішення головоломки з поточними налаштуваннями" << endl;
                    cout << "3. Вийти з програми" << endl;
                    do {
                        cout << "Ваша відповідь: ";
                        cin >> answ;
                        while (cin.get() != '\n'); // очистка буфера
                        if (answ != '1' && answ != '2' && answ != '3') {
                            cout << "**Некорректний ввід" << endl;
                        }
                        else break;
                    } while (true);
                    switch (answ) {
                    case '1':
                        A.settings();
                        break;
                    case '2':
                        A.start();
                        break;
                    case '3':
                        return 0;
                        break;
                    }
        }

        cout << "Повторити сеанс? (y - так, n - ні)" << endl;
        cout << "Ваша відповідь: ";
        cin >> answ;
        while (cin.get() != '\n'); // очистка буфера
        system("CLS");
    } while (answ == 'y');
}
