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
		traversFunc_ = &Field::traverseDownLeft;
		break;
	case '3':
		traversFunc_ = &Field::traverseUpRight;
		break;
	case '4':
		traversFunc_ = &Field::traverseUpLeft;
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
	if (answ == 'y') bDebug_ = true;
	SETCOLOR(color::green);
	cout << "<----- ������������ ��������� ----->" << endl;
	SETCOLOR(color::black);
}