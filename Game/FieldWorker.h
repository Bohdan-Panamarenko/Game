#include "Field.h"

#define SIZE 9

class FieldWorker : public Field { 
	void (FieldWorker::*typeOfTraverse_)(); // вказівник на функцію обходу початкового поля
	bool bDebug_; // режим розширеного огляду

	// Функці обходу

	// перша груп
	void traverseDownRight();
	void traverseDownLeft();
	void traverseUpRight();
	void traverseUpLeft();
	// друга група
	void traverseRightDown();
	void traverseLeftDown();
	void traverseRightUp();
	void traverseLeftUp();
public:
	FieldWorker() {
		typeOfTraverse_ = &FieldWorker::traverseDownRight;
		bDebug_ = false;
	}
	void settings(); // функція вводу налаштувань

	void start() { // почати обхід за поточними налаштуваннями
		(this->*typeOfTraverse_)();
	}
};