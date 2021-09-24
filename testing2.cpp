/* Thuy M Huynh
   COMP-SCI 201R - Instructor May Zeineldin
   Program 2
   Created on 09/22/2021
   Deadline: 09/26/2021 */

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void twoPlayers() {

	srand(time(0));                                      // seed random
	unsigned int card = 0;                               // card draw
	unsigned int pChoice;                                // option the user wants after players draws 4
	unsigned int p1Position = 0;                         // Player 1's position 
	unsigned int p2Position = 0;                         // Player 2's position 
	unsigned int temp = 0;                               // hold a temporary value
	bool restart = false;                                // bypasses the remaining turn
	short int rounds = 1;                                // rounds
	

	while (p1Position <= 30 && p2Position <= 30) {

		while (p1Position <= 30) {
			
			card = (rand() % 11) + 1;
			cout << endl;

			if (p1Position == 0) {

				if (card != 1 && card != 2) {
					cout << "You drew " << card << ", " << "Sorry! You did not get (1 or 2)" << endl;
					cout << "You need to skip your turn." << endl;
					cout << "Total steps for Player 1: 0" << endl;
					break;
				}

				else if (card == 1 || card == 2) {
					cout << "You drew " << card << ", " << "Congratulations!" << endl;
					cout << "You can start your turn." << endl;
					p1Position = p1Position + card;
					cout << "Total steps for Player 1: " << p1Position << endl;
					break;
				}
			}


			if (p1Position > 0) {

				if (card != 4) {
					cout << "Your card is " << card << endl;
					cout << "Move " << card << " steps foward." << endl;
					p1Position = p1Position + card;
					cout << "Total steps for Player 1: " << p1Position << endl;
					break;
				}

				else if (card == 4) {
					cout << "Your card is 4. You got a special card!?" << endl;
					cout << "You can take spot of the opponent's pawn, or move 4 steps." << endl;
					cout << "The choice is yours? Please choose: (1. move 4 steps, 2. take opponent spot)" << endl;
					cin >> pChoice;

					while (pChoice != 1 || pChoice != 2) {
						cout << "Wrong input. Please try again:" << endl;
						cin >> pChoice;
					}

					if (pChoice == 1 || pChoice == 2) {

						switch (pChoice) {

						case 1:

							cout << "You chose to move foward." << endl;
							cout << "Move 4 steps foward." << endl;
							p1Position += 4;
							cout << "Total steps for Player 1: " << p1Position << endl;
							break;

						case 2:

							temp = 0;
							p1Position = p2Position;
							p2Position = temp;
							cout << "You chose to take opponent spot." << endl;
							cout << "Sorry! Player 2 must go back to Home." << endl;
							cout << "Total steps for Player 1: " << p1Position << endl;
							break;
						}
					}
				}
				pChoice = 0;

				if (p1Position == 30) {
					cout << "Player 1 has won the game!" << endl;
					restart = true;
					break;
				}
			}
		}
		rounds = rounds + 1;



		if (restart == false) {

			while (p2Position <= 30) {

				cout << setw(25) << "***** Round " << rounds << " *****" << endl;
				cout << setw(25) << "*** Player 2 ***" << endl;
				cout << "Please press Enter to draw a card!" << endl;
				cin.ignore();
				cin.get();

				card = (rand() % 11) + 1;
				cout << endl;

				if (p2Position == 0) {

					if (card != 1 && card != 2) {
						cout << "You drew " << card << ", " << "Sorry! You did not get (1 or 2)" << endl;
						cout << "You need to skip your turn." << endl;
						cout << "Total steps for Player 2: 0" << endl;
						break;
					}


					else if (card == 1 || card == 2) {
						cout << "You drew " << card << ", " << "Congratulations!" << endl;
						cout << "You can start your turn." << endl;
						p2Position = p2Position + card;
						cout << "Total steps for Player 2: " << p2Position << endl;
						break;
					}
				}



				if (p2Position > 0) {

					if (card != 4) {
						cout << "Your card is " << card << endl;
						cout << "Move " << card << " steps foward." << endl;
						p2Position = p2Position + card;
						cout << "Total steps for Player 2: " << p2Position << endl;
						break;
					}

					else if (card == 4) {
						cout << "Your card is 4. You got a special card!?" << endl;
						cout << "You can take spot of the opponent's pawn, or move 4 steps." << endl;
						cout << "The choice is yours? Please choose: (1. move 4 steps, 2. take opponent spot)" << endl;
						cin >> pChoice;

						while (pChoice != 1 || pChoice != 2) {
							cout << "Wrong input. Please try again:" << endl;
							cin >> pChoice;
						}

						if (pChoice == 1 || pChoice == 2) {

							switch (pChoice) {

							case 1:

								cout << "You chose to move foward." << endl;
								cout << "Move 4 steps foward." << endl;
								p2Position += 4;
								cout << "Total steps for Player 2: " << p2Position << endl;
								break;

							case 2:

								temp = 0;
								p2Position = p1Position;
								p1Position = temp;
								cout << "You chose to take opponent spot." << endl;
								cout << "Sorry! Player 1 must get back to Home." << endl;
								cout << "Total steps for Player 2: " << p2Position << endl;
								break;
							}
						}
					}
					pChoice = 0;
				}

				if (p2Position == 30) {
					cout << "Player 2 has won the game!" << endl;
					break;
				}
			}
		}
	}
	rounds = rounds + 1;

	p1Position = p1Position + card;
	p2Position = p2Position + card;

	if (p1Position > 30) {

		cout << "You need to get exactly 30 steps to win." << endl;
		cout << "You must have to skip this turn." << endl;
		cout << "Total steps for Player 1: " << p1Position << endl;
	}

	if (p2Position > 30) {

		cout << "You need to get exactly 30 steps to win." << endl;
		cout << "You must have to skip this turn." << endl;
		cout << "Total steps for Player 2: " << p2Position << endl;
	}

	cin.clear();
	cin.ignore();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Rounds(int round) {
	int player1 = 0, player2 = 0; 						 
	int value = 1;
	struct result;

	while (1) {
		cout << "-------------------------------" << endl;
		cout << "****Round " << round++ << " ****" << endl;
		cout << "-------------------------------" << endl;
		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "***Player 1***" << endl;
		cout << "-------------------------------" << endl;

		cout << "Please press Enter to draw a card!" << endl;
		cin.get();

		value = (rand() % 11) + 1;
		result = game(value, player1, player2);
		player1 = result.p1;
		player2 = result.p2;

		cout << "Total steps for Player 1 :" << player1 << endl;

		if (player1 == 30)
		{
			cout << "Player 1 has won the game!" << endl;
			break;
		}

		cout << "-------------------------------" << endl;
		cout << "***Player 2***" << endl;
		cout << "-------------------------------" << endl;

		cout << "Please press Enter to draw a card!" << endl;
		cin.get();

		value = (rand() % 11) + 1;
		result = game(value, player2, player1);
		player2 = result.p1;
		player1 = result.p2;

		cout << "Total steps for Player 2 :" << player2 << endl;
		if (player2 == 30)
		{
			cout << "Player 2 has won the game!" << endl;
			break;
		}
	}
	cout << "Goodbye! Thank you for playing the game." << endl;
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	char another;
	unsigned short int draw = 0;
	unsigned short int choice = 0;
	unsigned short int p1_Position = 0;
	unsigned short int p2_Position = 0;
	unsigned short int tempNum = 0;
	short int gameRounds = 1;

	cout << setfill('-') << setw(35);
	cout << "Welcome to Sorry Board Game" << endl;
	cout << "This game can only be played with 2 players" << endl;
	cout << setfill('-') << setw(35);
	cout << setfill('-') << setw(25);

	do {
		do {
			twoPlayers();
		} while (p1_Position <= 30 && p2_Position <= 30);
		cout << "Would you like to play again? (Y/y for yes, N/n for no)" << endl;
		cin >> another;

	} while (another == 'Y' || another == 'y');

	cout << "Goodbye! Thank you for playing the game." << endl;

	return 0;
}
