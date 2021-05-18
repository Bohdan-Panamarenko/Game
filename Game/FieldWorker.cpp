#include "FieldWorker.h"

void FieldWorker::traverseDownRight() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			build(i, j, bDebug_, true);
		}
	}
}

void FieldWorker::traverseDownLeft() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j >= 0; j--) {
			build(i, j, bDebug_, true);
		}
	}
}

void FieldWorker::traverseUpRight() {
	for (int i = SIZE - 1; i >= 0; i--) {
		for (int j = 0; j < SIZE; j++) {
			build(i, j, bDebug_, true);
		}
	}
}

void FieldWorker::traverseUpLeft() {
	for (int i = SIZE - 1; i >= 0; i--) {
		for (int j = SIZE - 1; j >= 0; j--) {
			build(i, j, bDebug_, true);
		}
	}
}

void FieldWorker::traverseRightDown() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			build(j, i, bDebug_, true);
		}
	}
}

void FieldWorker::traverseLeftDown() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j >= 0; j--) {
			build(j, i, bDebug_, true);
		}
	}
}

void FieldWorker::traverseRightUp() {
	for (int i = SIZE - 1; i >= 0; i--) {
		for (int j = 0; j < SIZE; j++) {
			build(j, i, bDebug_, true);
		}
	}
}

void FieldWorker::traverseLeftUp() {
	for (int i = SIZE - 1; i >= 0; i--) {
		for (int j = SIZE - 1; j >= 0; j--) {
			build(j, i, bDebug_, true);
		}
	}
}

void FieldWorker::settings() {
	char answ = '\0';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SETCOLOR(color::green);
	cout << "<---------- Налаштування ---------->" << endl;
	SETCOLOR(color::black);
	cout << "Виконувати обхід за:" << endl;
	cout << "1. Рядками" << endl;
	cout << "2. Стовпцями" << endl;
	char trav = '\0';
	do {
		cout << "Ваша відповідь: ";
		cin >> trav;
		while (cin.get() != '\n'); // очистка буфера
		if (trav != '1' && trav != '2') {
			cout << "**Некорректний ввід" << endl;
		}
		else break;
	} while (true);
	cout << "Виберіть спосіб обходу поля:" << endl;
	cout << "1. Згори вниз і зліва направо" << endl;
	cout << "2. Згори вниз і справа наліво" << endl;
	cout << "3. Знизу вгору і зліва направо" << endl;
	cout << "4. Знизу вгору і справа наліво" << endl;
	do {
		cout << "Ваша відповідь: ";
		cin >> answ;
		while (cin.get() != '\n'); // очистка буфера
		if (answ != '1' && answ != '2' && answ != '3' && answ != '4') {
			cout << "**Некорректний ввід" << endl;
		}
		else break;
	} while (true);
	if (trav == '1') {
		switch (answ) {
		case '2':
			typeOfTraverse_ = &FieldWorker::traverseDownLeft;
			break;
		case '3':
			typeOfTraverse_ = &FieldWorker::traverseUpRight;
			break;
		case '4':
			typeOfTraverse_ = &FieldWorker::traverseUpLeft;
			break;
		}
	}
	else {
		switch (answ) {
		case '1':
			typeOfTraverse_ = &FieldWorker::traverseRightDown;
			break;
		case '2':
			typeOfTraverse_ = &FieldWorker::traverseLeftDown;
			break;
		case '3':
			typeOfTraverse_ = &FieldWorker::traverseRightUp;
			break;
		case '4':
			typeOfTraverse_ = &FieldWorker::traverseLeftUp;
			break;
		}
	}
	cout << "\nВиберіть спосіб пошуку змійок:" << endl;
	SETCOLOR(color::red);
	cout << "Увага! Кількість та положення змійок залежить від комбінації" << endl;
	cout << "способу обходу та способу пошуку. Максимальна задокументована" << endl;
	cout << "кількість змійок - 5" << endl;
	SETCOLOR(color::black);
	cout << "1. Згори вниз і зліва направо" << endl;
	cout << "2. Згори вниз і справа наліво" << endl;
	cout << "3. Знизу вгору і зліва направо" << endl;
	cout << "4. Знизу вгору і справа наліво" << endl;
	do {
		cout << "Ваша відповідь: ";
		cin >> answ;
		while (cin.get() != '\n'); // очистка буфера
		if (answ != '1' && answ != '2' && answ != '3' && answ != '4') {
			cout << "**Некорректний ввід" << endl;
		}
		else break;
	} while (true);
	switch (answ) {
	case '2':
		traversFunc_ = &Field::traverseDownLeft;
		break;
	case '3':
		traversFunc_ = &Field::traverseUpRight;
		break;
	case '4':
		traversFunc_ = &Field::traverseUpLeft;
		break;
	}
	cout << "\nУвімкнути режим ретельного огляду? (y - так, n - ні)" << endl;
	cout << "У цьому режимі буде виводитись кожен крок алгоритму пошуку змійок." << endl;
	cout << "Після знаходження змійки пошук буде призупинено." << endl;
	do {
		cout << "Ваша відповідь: ";
		cin >> answ;
		while (cin.get() != '\n'); // очистка буфера
		if (answ != 'y' && answ != 'n') {
			cout << "**Некорректний ввід" << endl;
		}
		else break;
	} while (true);
	if (answ == 'y') bDebug_ = true;
	SETCOLOR(color::green);
	cout << "<----- Налаштування завершено ----->" << endl;
	SETCOLOR(color::black);
}