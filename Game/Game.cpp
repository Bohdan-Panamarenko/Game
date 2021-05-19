#include "FieldWorker.h"

int main()
{
    //SetConsoleOutputCP(CP_UTF8); // для компіляції з допомогою G++
    system("chcp 1251>nul"); // для компіляції з допомогою VS
    system("color F0");
    char answ = 'y';
    do {
        FieldWorker A; // об'єкт поля
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
            else break; // якщо ввід вірний, виходимо з циклу
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

        while (answ == '1') { // налаштування можна провести декілька разів
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
                else break; // якщо ввід вірний, виходимо з циклу
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
        system("CLS"); // очистка консолі
    } while (answ == 'y');
}
