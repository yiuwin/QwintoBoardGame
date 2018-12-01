#pragma once
#include <iostream>
#include <sstream>
#include "Colour.h"
#include "RollOfDice.h"
#include "QwintoCell.h"

template <typename T>
class QwintoRow {

public:
	// Variables
	T colour;
	QwintoCell cells[12];

	// Constructors
	QwintoRow<T>();
	QwintoRow<T>(T c);

	// Functions
	void setInvalid(int n);
	bool isComplete(); // Returns true if there are no empty cells in the row
	string toString(); // Helper function used by insertion operator
	bool validate(RollOfDice rd, int index); // Check if RollOfDice can be added to the row at a certain index

	// Overloaded Operators
	QwintoCell & operator[](int index) { // Subscript/Indexing Oeprator
		return cells[index]; // Sets an individual QwintoCell value in a QwintoRow<Colour>
	}

};



// Constructors

template <typename T>
QwintoRow<T>::QwintoRow() {}

template <typename T>
QwintoRow<T>::QwintoRow(T c) {
	colour = c;
	for (auto i = 0; i < 10; i++) {
		cells[i] = 0;
	}
}

// Functions

template <typename T>
void QwintoRow<T>::setInvalid(int n) {
	cells[n].setInvalid();
}

template <typename T>
// Check if RollOfDice can be added to the row at a certain index
bool QwintoRow<T>::validate(RollOfDice rd, int index) {

	// check if color of QwintoRow is in rd
	auto colourValid = false;
	for (Dice d : rd.dice) {
		if (d.colour == colour) {
			colourValid = true;
		}
	}
	if (!colourValid) {
		return false;
	}

	// Check if cell is invalid
	if (cells[index].isInvalid() || cells[index].value>0) {
		return false;
	}

	// check if all scores less than index is less than sum of rd
	for (int i = 0; i < index; i++) {
		if (cells[i].value > rd) {
			return false;
		}
	}
	// check if number has already been used
	for (int i = index; i < 12; i++) {
		if (cells[i].value == rd) {
			return false;
		}
	}

	return true;
}

template <typename T>
bool QwintoRow<T>::isComplete() {
	for (QwintoCell c : cells) {
		if (c.value == 0) {
			return false;
		}
	}
	return true;
}

// Overloaded Operators

template <typename T>
ostream& operator << (ostream & os, QwintoRow<T> & qr) {
	os << qr.toString();
	return os;
}

template <typename T>
string QwintoRow<T>::toString() {
	stringstream ss;
	if (colour == Colour::RED) {
		ss << colourToString(colour) << "                | ";

		for (int i = 2; i < 12; i++) {

			if (i == 2 || i == 3 || i == 6 || i == 7) {
				if (cells[i].value == 0) {
					ss << "   % ";
				}
				else {
					ss << cells[i].toString() << " % ";
				}
			}

			else if (cells[i].isInvalid()) {
				ss << "XX | ";
			}
			else if (cells[i].value == 0) {
				ss << "   | ";
			}
			else {
				ss << cells[i].toString() << " | ";
			}
		}
	}
	else if (colour == Colour::YELLOW) {
		ss << colourToString(colour) << "        | ";


		for (int i = 1; i < 11; i++) {
			if (i == 7 || i == 8) {
				if (cells[i].value == 0) {
					ss << "   % ";
				}
				else {
					ss << cells[i].toString() << " % ";
				}
			}
			else if (cells[i].isInvalid()) {
				ss << "XX | ";
			}
			else if (cells[i].value == 0) {
				ss << "   | ";
			}
			else {
				ss << cells[i].toString() << " | ";
			}
		}
	}
	else if (colour == Colour::BLUE) {
		ss << colourToString(colour) << "     | ";

		for (auto i = 0; i < 10; i++) {
			if (i == 1 || i == 2 || i == 8 || i == 9) {
				if (cells[i].value == 0) {
					ss << "   % ";
				}
				else {
					ss << cells[i].toString() << " % ";
				}
			}
			else if (cells[i].isInvalid()) {
				ss << "XX | ";
			}
			else if (cells[i].value == 0) {
				ss << "   | ";
			}
			else {
				ss << cells[i].toString() << " | ";
			}
		}
	}
	ss << endl;
	return ss.str();
}