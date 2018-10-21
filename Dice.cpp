#include "Dice.h"
#include <stdlib.h>     /* srand, rand */
#include <random>

// Constructors

Dice::Dice(Colour c) : colour(c) {
	roll();
}

// Functions

void Dice::setFace(int f) {
	face = f;
}

int Dice::roll() {	
	// Generate random numbers
	std::random_device randd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(randd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 6);

	face = dis(gen);
	return face;
}

// Overloaded Operators

ostream& operator << (ostream & os, const Dice & d) { // Insertion Operator prints all dice
	os << colourToString(d.colour) << " dice: " << d.face << "\n";
	return os;
}