#include "FieldWorker.h"

void FieldWorker::traverseDownRight() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			(this->*typeOfSeek)(i, j, debug, true);
		}
	}
}

void FieldWorker::traverseDownLeft() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j > 0; j--) {
			(this->*typeOfSeek)(i, j, debug, true);
		}
	}
}

void FieldWorker::traverseUpRight() {
	for (int i = SIZE - 1; i > 0; i--) {
		for (int j = 0; j < SIZE; j++) {
			(this->*typeOfSeek)(i, j, debug, true);
		}
	}
}

void FieldWorker::traverseUpLeft() {
	for (int i = SIZE - 1; i > 0; i--) {
		for (int j = SIZE - 1; j > 0; j--) {
			(this->*typeOfSeek)(i, j, debug, true);
		}
	}
}

void FieldWorker::traverseRightDown() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			(this->*typeOfSeek)(j, i, debug, true);
		}
	}
}

void FieldWorker::traverseLeftDown() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j > 0; j--) {
			(this->*typeOfSeek)(j, i, debug, true);
		}
	}
}

void FieldWorker::traverseRightUp() {
	for (int i = SIZE - 1; i > 0; i--) {
		for (int j = 0; j < SIZE; j++) {
			(this->*typeOfSeek)(j, i, debug, true);
		}
	}
}

void FieldWorker::traverseLeftUp() {
	for (int i = SIZE - 1; i > 0; i--) {
		for (int j = SIZE - 1; j > 0; j--) {
			(this->*typeOfSeek)(j, i, debug, true);
		}
	}
}

void FieldWorker::settings() {
	char answ = '\0';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SETCOLOR(color::green);
	cout << "<---------- ������������ ---------->" << endl;
	SETCOLOR(color::black);
	cout << "���������� ����� ��:" << endl;
	cout << "1. �������" << endl;
	cout << "2. ���������" << endl;
	char trav = '\0';
	do {
		cout << "���� �������: ";
		cin >> trav;
		while (cin.get() != '\n'); // ������� ������
		if (trav != '1' && trav != '2') {
			cout << "**������������ ���" << endl;
		}
		else break;
	} while (true);
	cout << "������� ����� ������ ����:" << endl;
	cout << "1. ����� ���� � ���� �������" << endl;
	cout << "2. ����� ���� � ������ �����" << endl;
	cout << "3. ����� ����� � ���� �������" << endl;
	cout << "4. ����� ����� � ������ �����" << endl;
	do {
		cout << "���� �������: ";
		cin >> answ;
		while (cin.get() != '\n'); // ������� ������
		if (answ != '1' && answ != '2' && answ != '3' && answ != '4') {
			cout << "**������������ ���" << endl;
		}
		else break;
	} while (true);
	if (trav == '1') {
		switch (answ) {
		case '2':
			typeOfTraverse = &FieldWorker::traverseDownLeft;
			break;
		case '3':
			typeOfTraverse = &FieldWorker::traverseUpRight;
			break;
		case '4':
			typeOfTraverse = &FieldWorker::traverseUpLeft;
			break;
		}
	}
	else {
		switch (answ) {
		case '1':
			typeOfTraverse = &FieldWorker::traverseRightDown;
			break;
		case '2':
			typeOfTraverse = &FieldWorker::traverseLeftDown;
			break;
		case '3':
			typeOfTraverse = &FieldWorker::traverseRightUp;
			break;
		case '4':
			typeOfTraverse = &FieldWorker::traverseLeftUp;
			break;
		}
	}
	cout << "\n������� ����� ������ �����:" << endl;
	SETCOLOR(color::red);
	cout << "�����! ʳ������ �� ��������� ����� �������� �� ���������" << endl;
	cout << "������� ������ �� ������� ������. ����������� ���������������" << endl;
	cout << "������� ����� - 5" << endl;
	SETCOLOR(color::black);
	cout << "1. ����� ���� � ���� �������" << endl;
	cout << "2. ����� ���� � ������ �����" << endl;
	cout << "3. ����� ����� � ���� �������" << endl;
	cout << "4. ����� ����� � ������ �����" << endl;
	do {
		cout << "���� �������: ";
		cin >> answ;
		while (cin.get() != '\n'); // ������� ������
		if (answ != '1' && answ != '2' && answ != '3' && answ != '4') {
			cout << "**������������ ���" << endl;
		}
		else break;
	} while (true);
	switch (answ) {
	case '2':
		typeOfSeek = &Field::seekDownLeft;
		break;
	case '3':
		typeOfSeek = &Field::seekUpRight;
		break;
	case '4':
		typeOfSeek = &Field::seekUpLeft;
		break;
	}
	cout << "\n�������� ����� ���������� ������? (y - ���, n - �)" << endl;
	cout << "� ����� ����� ���� ���������� ����� ���� ��������� ������ �����." << endl;
	cout << "ϳ��� ����������� ����� ����� ���� �����������." << endl;
	do {
		cout << "���� �������: ";
		cin >> answ;
		while (cin.get() != '\n'); // ������� ������
		if (answ != 'y' && answ != 'n') {
			cout << "**������������ ���" << endl;
		}
		else break;
	} while (true);
	if (answ == 'y') debug = true;
	SETCOLOR(color::green);
	cout << "<----- ������������ ��������� ----->" << endl;
	SETCOLOR(color::black);
}