#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "Dice.h"

using namespace std;

class RollOfDice {

public:

	// Variables
	vector<Dice> dice;

	// Constructors
	RollOfDice(); // Default constructor contains no dice
	RollOfDice(vector<Dice>);

	// Functions
	void roll(); 
	RollOfDice pair(Dice, Dice);

	// Overloaded Operators
	operator int() const; // Conversion operator
	friend ostream& operator << (ostream &, const RollOfDice &); // Insertion operator

};