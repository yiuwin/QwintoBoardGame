#include "RollOfDice.h"

// Constructors

RollOfDice::RollOfDice() {}

RollOfDice::RollOfDice(vector<Dice> roll) {
	
	for (auto d : roll) {
		dice.push_back(d);
	}
	
}

// Functions

void RollOfDice::RollOfDice::roll() {
	for (auto d : dice) {
		d.setFace(d.roll());
		cout << d << endl;
	}
}

RollOfDice RollOfDice::pair(Dice d1, Dice d2) {
	vector<Dice> dice;
	dice.push_back(d1);
	dice.push_back(d2);
	return RollOfDice(dice);
}


// Overloaded Operators

ostream& operator << (ostream & os, const RollOfDice & roll) { // Insertion Operator prints all individual dice values and sum of dice values

	os << "**********************************\nPrinting this Roll Of Dice:\n";

	int sum = roll;
	
	for (auto d : roll.dice) {
		os << d;
	}
	os << "Sum: " << sum << "\n" << "**********************************" << endl;

	return os;
}

RollOfDice::operator int() const { // Conversion Operator to Int: adds up all faces in the roll and returns the sum
	auto sum = 0;
	for (auto d : dice) {
		sum = sum + d.face;
	}
	return sum;
}