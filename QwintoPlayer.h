#pragma once
#include <iostream>
#include "Player.h"
#include "QwintoScoreSheet.h"
#include "RollOfDice.h"

using namespace std;

class QwintoPlayer : public Player {
public:

	// Constructors
	QwintoPlayer(string s);

	// Variables
	QwintoScoreSheet *sheet;
	string name;
	bool isActive;

	// Functions
	bool gameover();

	// Overridden Functions
	virtual void inputBeforeRoll(RollOfDice &roll);
	virtual void inputAfterRoll(RollOfDice &roll);

	// Destructor
	~QwintoPlayer();
	

};