#pragma once

#include "Field.h"

#define SIZE 9

class FieldWorker : public Field {
	bool (Field::* typeOfSeek)(int i, int j, bool debug, bool isFirst);
	void (FieldWorker::*typeOfTraverse)();
	bool debug;

	void traverseDownRight();
	void traverseDownLeft();
	void traverseUpRight();
	void traverseUpLeft();
public:
	FieldWorker() {
		typeOfSeek = &Field::seekDownRight;
		typeOfTraverse = &FieldWorker::traverseDownRight;
		debug = false;
	}
	void settings();

	void start() {
		(this->*typeOfTraverse)();
	}
};