#include "QwintoScoreSheet.h"

using namespace std;

// Constructors

QwintoScoreSheet::QwintoScoreSheet() {}

QwintoScoreSheet::QwintoScoreSheet(string name) { // Sets up a standard Qwinto Score Sheet with appropriate invalid cells
	player = name;
	failed = 0;
	totalScore = 0;
	qwintoBoard[0] = QwintoRow<Colour>(Colour::RED);
	qwintoBoard[0].setInvalid(0);
	qwintoBoard[0].setInvalid(1);
	qwintoBoard[0].setInvalid(5);
	qwintoBoard[1] = QwintoRow<Colour>(Colour::YELLOW);
	qwintoBoard[1].setInvalid(0);
	qwintoBoard[1].setInvalid(6);
	qwintoBoard[1].setInvalid(11);
	qwintoBoard[2] = QwintoRow<Colour>(Colour::BLUE);
	qwintoBoard[2].setInvalid(4);
	qwintoBoard[2].setInvalid(10);
	qwintoBoard[2].setInvalid(11);
}

// Overridden Functions

bool QwintoScoreSheet::score(RollOfDice roll, Colour color, int pos = -1) {

	if (color == Colour::RED) {
		if (qwintoBoard[0].validate(roll, pos)) {
			(qwintoBoard[0])[pos] = roll;
			cout << "valid score\n";
			return true;
		}
	}
	else if (color == Colour::YELLOW) {
		if (qwintoBoard[1].validate(roll, pos)) {
			(qwintoBoard[1])[pos] = roll;
			cout << "valid score\n";
			return true;
		}
	}
	else if (color == Colour::BLUE) {
		if (qwintoBoard[2].validate(roll, pos)) {
			(qwintoBoard[2])[pos] = roll;
			cout << "valid score\n";
			return true;
		}
	}

	cout << "invalid score\n";
	failed++; // Update failed throws for an invalid entry
	return false;
}

int QwintoScoreSheet::setTotal() {
	totalScore = calcTotal();
	return totalScore;
}

int QwintoScoreSheet::calcTotal() {
	auto sum = 0;

	// loop over each QwintoRow
	for (int i = 0; i < 3; i++) {
		int entryCount = 0; // Number of entries is used as a score for an incomplete row
		for (QwintoCell cell : qwintoBoard[i].cells) {
			if (cell.value > 0) {
				entryCount++;
			}
		}
		if (entryCount == 9) { // row complete: score = last score in row
			if (qwintoBoard[i].colour == Colour::RED) {
				sum = sum + (qwintoBoard[i].cells[11]).value;
			}
			else if (qwintoBoard[i].colour == Colour::YELLOW) {
				sum = sum + (qwintoBoard[i].cells[10]).value;
			}
			if (qwintoBoard[i].colour == Colour::RED) {
				sum = sum + (qwintoBoard[i].cells[9]).value;
			}
		}
		else { // row incomplete: score = number of entries
			sum = sum + entryCount;
		}
	}

	// Add bonus points
	if ((qwintoBoard[0])[2].value > 0 && (qwintoBoard[1])[2].value > 0 && (qwintoBoard[2])[2].value > 0) {
		sum = sum + (qwintoBoard[2])[2].value;
	}
	if ((qwintoBoard[0])[3].value > 0 && (qwintoBoard[1])[3].value > 0 && (qwintoBoard[2])[3].value > 0) {
		sum = sum + (qwintoBoard[0])[3].value;
	}
	if ((qwintoBoard[0])[7].value > 0 && (qwintoBoard[1])[7].value > 0 && (qwintoBoard[2])[7].value > 0) {
		sum = sum + (qwintoBoard[0])[7].value;
	}
	if ((qwintoBoard[0])[8].value > 0 && (qwintoBoard[1])[8].value > 0 && (qwintoBoard[2])[8].value > 0) {
		sum = sum + (qwintoBoard[1])[8].value;
	}
	if ((qwintoBoard[0])[9].value > 0 && (qwintoBoard[1])[9].value > 0 && (qwintoBoard[2])[9].value > 0) {
		sum = sum + (qwintoBoard[2])[9].value;
	}

	// Minus failed throws
	sum = sum + (-5 * failed);
	return sum;
}


// Class Functions

bool QwintoScoreSheet::won() {
	if ((qwintoBoard[0].isComplete() && qwintoBoard[1].isComplete())
		|| (qwintoBoard[0].isComplete() && qwintoBoard[2].isComplete())
		|| (qwintoBoard[1].isComplete() && qwintoBoard[2].isComplete())

		) {
		return true;
	}
	return false;
}

// Overloaded Operators

ostream& operator << (ostream & os, const QwintoScoreSheet & qss) { // Insertion Operator
	
	stringstream ss;
	ss << "\n";
	ss << "Player name: " << qss.player << "                    Points: " << qss.totalScore << "\n";
	ss << "----------------------------------------------------------------------\n";

	for (QwintoRow<Colour> qr : qss.qwintoBoard) {
		ss << qr;
		ss << "----------------------------------------------------------------------\n";
	}

	ss << "Failed throws: ";
	for (int i = 0; i <= qss.failed; i++) {
		ss << i << " ";
	}


	ss << "\n";
	ss << endl;

	os << ss.str();
	return os;
}

