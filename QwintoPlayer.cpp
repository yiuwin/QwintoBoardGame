#include "QwintoPlayer.h"

using namespace std; 

// Constructors

QwintoPlayer::QwintoPlayer(string s) {
	sheet = new QwintoScoreSheet(s);
	name = s;
	isActive = false;
}

// Destructors

QwintoPlayer::~QwintoPlayer() {
	delete sheet;
}

// Class Functions

bool QwintoPlayer::gameover() { // Returns true if game is over (i.e. two complete rows or 4 failed throws
	if ( (*sheet).won() || (*sheet).failed == 3 ) { // failed ==3 because count starts at 0
		return true;
	}
	return false;
}

// Overridden Functions

void QwintoPlayer::inputBeforeRoll(RollOfDice & roll) { // Asks user to choose which of the dice they wish to include in this Roll Of Dice
	char tmp;
	vector<Dice> dice;
	cout << "Would you like to roll the RED dice? Enter Y/N.\n";
	cin >> tmp;
	if (tmp == 'Y') {
		dice.push_back(Dice(Colour::RED));
	}
	cout << "Would you like to roll the YELLOW dice? Enter Y/N.\n";
	cin >> tmp;
	if (tmp == 'Y') {
		dice.push_back(Dice(Colour::YELLOW));
	}
	cout << "Would you like to roll the BLUE dice? Enter Y/N.\n";
	cin >> tmp;
	if (tmp == 'Y') {
		dice.push_back(Dice(Colour::BLUE));
	}

	roll = dice;
}

void QwintoPlayer::inputAfterRoll(RollOfDice & roll) { // Asks user where they'd like to score their dice and then calls score from QwintoScoreSheet to verify
	auto colour = '-';
	int pos = -1;
	
	// Valid colour check
	while (!(colour == 'R' || colour == 'Y' || colour == 'B')) {
		cout << "Enter the colour of the row you'd like to score. (R/Y/B)\n";
		cin >> colour;
	}

	// Valid cell check
	while (pos < 0 && pos > 9) {
		cout << "Enter the position of the row you'd like to score. Row positions go from 0 to 9.\n";
		cin >> pos;
	}

	// Check if cell is valid using the the user-entered position + row offset
	if (colour == 'R') {
		sheet->score(roll, Colour::RED, pos + 2);
	}
	else if (colour == 'Y') {
		sheet->score(roll, Colour::YELLOW, pos + 1);
	}
	else if (colour == 'B') {
		sheet->score(roll, Colour::BLUE, pos);
	}
	
}