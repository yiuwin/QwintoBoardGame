#pragma once
#include "Dice.h"
#include "RollOfDice.h"

// Helper Class for handling individual QwintoRow<Colour> cells in a score sheet
class QwintoCell {
public:

	// Variables
	int value;

	// Constructors
	QwintoCell();
	QwintoCell(int);

	// Overloaded Operators
	QwintoCell& operator= (RollOfDice); // A cell can be assigned a value using RollOfDice
	QwintoCell& operator= (int); // or primitive int value

	// Functions
	string toString();
	void setInvalid();
	bool isInvalid(); // Returns true if the cell is invalid
};