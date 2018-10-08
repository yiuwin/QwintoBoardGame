/*
 *
 * CSI 2372 Programming Concepts of C++
 * Name: Jasper Yiu
 * Student ID: 7565440
 * Date: December 9, 2017
 *
 * Final Project (Individual)
 *
 * You must implement one of the two version of the dice playing game completely. 
 * The other version does not need to be implemented but all the software design to add that version 
 * have to be there including all templates and abstract base classes.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include "QwintoPlayer.h"
#include "Colour.h"
#include "QwintoRow.h"
#include <iostream>
using namespace std;

int main() {

	bool gameOver = false;
	char version; // Version A: Qwinto; Version B: Qwixx
	int numPlayers;

	cout << "Enter A to play Version A: Qwinto. Enter B to play Version B: Qwixx.\n";
	cin >> version;
	
	// VERSION A: QWINTO
	if (version == 'A') {
		cout << "Enter number of players." << "\n";
		cin >> numPlayers;

		vector<QwintoPlayer*> players;
		for (int i = 1; i <= numPlayers; i++) {
			cout << "Enter name of player " << i << "\n";
			string tmp;
			cin >> tmp;
			QwintoPlayer *qp =  new QwintoPlayer(tmp);
			players.push_back(qp);
		}

		// Create Roll Of Dice
		vector<Dice> dice = {
			Dice(Colour::RED),
			Dice(Colour::YELLOW),
			Dice(Colour::BLUE)
		};
		RollOfDice rd(dice);

		while (!gameOver) {
			for (QwintoPlayer* activePlayer : players) {
				cout << "**********************************************************************\n";
				cout << "Current Player: " << (*activePlayer).name << "\n";
				cout << "**********************************************************************\n";

				(*activePlayer).isActive = true; // activate player

				// Prompt InputBeforeRoll
				(*activePlayer).inputBeforeRoll(rd);

				// Roll dice and show result
				rd.roll();
				cout << rd;

				// Print scoresheet of active player
				cout << *((*activePlayer).sheet);

				// Prompt InputAfterRoll and score
				(*activePlayer).inputAfterRoll(rd); 

				// Print scoresheet of active player
				cout << *((*activePlayer).sheet);

				// Check if game is over
				if ((*activePlayer).gameover()) {
					gameOver = true;
					break;
				}

				// loop over all inactive players
				cout << "Looping Over Inactive Players:\n";
				for (QwintoPlayer* inactivePlayer : players) {
					if (!(*inactivePlayer).isActive) {
						cout << "Score Sheet of Inactive Player: " << (*inactivePlayer).name << "\n";
						cout << *((*inactivePlayer)).sheet; // Print scoresheet of inactive player
						(*inactivePlayer).inputAfterRoll(rd); // Get input of inactive player and score
						cout << *((*inactivePlayer)).sheet; // Print scoresheet of inactive player

						// Check if game is over
						if ((*inactivePlayer).gameover()) {
							gameOver = true;
						}
					}
				}
				
				(*activePlayer).isActive = false; // deactivate player after their turn
			}
		}

		QwintoPlayer* winner = players[0];
		auto maxPoints = 0;

		// Loop over players and calculate points
		for (QwintoPlayer* player : players) {
			(*((*player)).sheet).setTotal();
			cout << *((*player)).sheet;
			if ((*((*player)).sheet).totalScore > maxPoints) { // update variable winner with the player holding maxPoints
				maxPoints = (*((*player)).sheet).totalScore;
				winner = player;
			}
		}

		// Announce winner
		cout << "Congratulations, " << (*winner).name << "! You won!" << endl;

	}

	// VERSION B: QWIXX
	else {
		cout << "Version B Qwixx not implemented.";
		cin.get();
	}
	

	cin.get();
	return 0;
}

