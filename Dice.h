#pragma once
#include <iostream>
#include "Colour.h"

struct Dice {

	// Variables
	const Colour colour;
	int face;
	
public:

	// Constructors
	Dice(Colour); // A dice must be given a colour when initialized

	// Functions
	void setFace(int);
	int roll();

	// Overloaded Operators
	friend ostream& operator << (ostream &, const Dice &);
};