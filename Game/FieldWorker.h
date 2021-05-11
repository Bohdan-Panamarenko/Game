#include "Field.h"

#define SIZE 9

class FieldWorker : public Field {
	bool (Field::* typeOfSeek_)(int i, int j, bool bDebug, bool bIsFirst);
	void (FieldWorker::*typeOfTraverse_)();
	bool bDebug_;

	void traverseDownRight();
	void traverseDownLeft();
	void traverseUpRight();
	void traverseUpLeft();

	void traverseRightDown();
	void traverseLeftDown();
	void traverseRightUp();
	void traverseLeftUp();
public:
	FieldWorker() {
		typeOfSeek_ = &Field::seekDownRight;
		typeOfTraverse_ = &FieldWorker::traverseDownRight;
		bDebug_ = false;
	}
	void settings();

	void start() {
		(this->*typeOfTraverse_)();
	}
};