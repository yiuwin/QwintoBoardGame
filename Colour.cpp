
#include "Colour.h"

string colourToString(Colour colour) {
	switch (colour) {
	case Colour::RED:
		return "Red";
	case Colour::YELLOW:
		return "Yellow";
	case Colour::BLUE:
		return "Blue";
	default:
		return "?";
	}
}