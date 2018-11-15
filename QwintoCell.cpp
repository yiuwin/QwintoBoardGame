#include <sstream>
#include "QwintoCell.h"

// Helper Class for handling individual QwintoRow<Colour> cells in a score sheet

// Constructors
QwintoCell::QwintoCell() {
	value = 0;
}

QwintoCell::QwintoCell(int v) {
	value = v;
}


// Overloaded Operators
QwintoCell& QwintoCell:: operator = (RollOfDice roll) {
	value = roll; //conversion operator implicitly converts RollOfDice to an int of the sum
	return *this;
}

QwintoCell& QwintoCell:: operator = (int v) {
	value = v; //conversion operator implicitly converts RollOfDice to an int of the sum
	return *this;
}


// Functions
void QwintoCell:: setInvalid() {
	value = -1;
}

bool QwintoCell::isInvalid() {
	if (value == -1) {
		return true;
	}
	return false;
}

string QwintoCell::toString() {
	stringstream ss;
	ss << value;
	return ss.str();
}