#pragma once
#include <iostream>
#include <string>

#include "RollOfDice.h"

using namespace std;

class ScoreSheet { // Abstract Parent Class
public:

	// Variables

	std::string player;
	int failed;
	int totalScore;

	// Pure Virtual Functions
	virtual bool score(RollOfDice roll, Colour color, int pos = -1) = 0;

	virtual int setTotal() = 0;

	virtual int calcTotal() = 0;

};