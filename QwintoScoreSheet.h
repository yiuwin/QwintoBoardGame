#pragma once
#include <iostream>
#include <sstream>
#include "ScoreSheet.h"
#include "QwintoRow.h"
#include "Colour.h"

class QwintoScoreSheet : public ScoreSheet {
public:

	// Variables
	QwintoRow<Colour> qwintoBoard[3]; // Holds 3 QwintoRows: Row 0 is RED, Row 1 is YELLOW, Row 2 is BLUE
	std::string player;
	int failed;
	int totalScore;

	// Constructors
	QwintoScoreSheet();
	QwintoScoreSheet(string);

	// Overridden Functions
	bool score(RollOfDice, Colour, int); 
	int calcTotal();
	int setTotal();

	// Class Functions
	bool won(); // Returns true if two rows of the scoresheet are completed

	// Overloaded Operators
	friend ostream& operator << (ostream &, const QwintoScoreSheet &); // Insertion operator


};