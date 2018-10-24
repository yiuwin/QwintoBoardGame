#pragma once
#include <iostream>
#include "RollOfDice.h"

using namespace std;

class Player { // Abstract Parent Class

public:
	// Variables
	string name;
	bool isActive;

	// Pure Virtual Functions
	virtual void inputBeforeRoll(RollOfDice &roll) = 0;
	virtual void inputAfterRoll(RollOfDice &roll) = 0;

};


