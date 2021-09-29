#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct Sorry {                                            //structure
	int p1, p2;
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Sorry twoPlayers(int card, int p1Position, int p2Position) {

	Sorry pawn;
	pawn.p1 = p1Position;
	pawn.p2 = p2Position;

	int pChoice;                                         // option the user wants after players draws 4
	unsigned int temp = 0;                               // hold a temporary value



	if (p1Position == 0) {
		if (card != 1 && card != 2) {
			std::cout << "You drew " << card << ", " << "Sorry! You did not get (1 or 2)" << endl;                       //Compiler error: cout & cin are ambiguous - so add std::
			std::cout << "You have to stand at Home." << endl;
			return pawn;
		}

		else if (card == 1 || card == 2) {
			std::cout << "You drew " << card << ". " << "Congratulations!" << endl;
			std::cout << "You can get out Home." << endl;
			p1Position += card;
			pawn.p1 = p1Position;
			return pawn;
		}
	}


	else {

		if (p1Position + card > 30) {

			std::cout << "Unfortunately, you drew " << card << "." << endl;
			std::cout << "You need to get exactly 30 steps to win." << endl;
			std::cout << "You have to skip this turn." << endl;
			return pawn;
		}

		else if (card != 4) {

			std::cout << "Your card is " << card << "." << endl;
			std::cout << "Move " << card << " steps foward." << endl;
			p1Position += card;
			pawn.p1 = p1Position;
			return pawn;
		}

		else if (card == 4) {

			std::cout << "Your card is 4. You got a special card!" << endl;
			std::cout << "You can take spot of the opponent's pawn, or move 4 steps." << endl;
			std::cout << "The choice is yours! What will it be? (1.Move 4 steps, 2.Take opponent's spot)" << endl;
			std::cin >> pChoice;

			while (pChoice != 1 && pChoice != 2) {
				std::cout << "Wrong input. Please try again:" << endl;
				std::cout << "Please choose: (1.Move 4 steps, 2.Take opponent's spot)" << endl;
				std::cin >> pChoice;
			}

			if (pChoice == 1 || pChoice == 2) {

				switch (pChoice) {

				case 1:

					std::cout << "You chose to move foward." << endl;
					std::cout << "Move 4 steps foward." << endl;
					p1Position += card;
					pawn.p1 = p1Position;
					return pawn;

				case 2:

					temp = 0;
					pawn.p1 = p2Position;
					pawn.p2 = temp;
					std::cout << "Brutal! You chose to take opponent's spot. T_T" << endl;
					std::cout << "You are now at opponent's spot. (o(..)o)" << endl;
					std::cout << "Sorry to the opponent. (_ _*) Too bad, you must go back Home." << endl;
					return pawn;
				}
			}
		}

	}
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void Round(int rounds) {
	int player1 = 0, player2 = 0; 	
	int value = 1;
	Sorry game;

	while (1) {
		
		std::cout << "-.-.-.-.-.-.-.-.- Round " << rounds++ << " .-.-.-.-.-.-.-.-.-" << endl;
		std::cout << endl;
		std::cout << "--------------------------------------------" << endl;
		std::cout << "             @.@ Player 1 @.@"                << endl;
		std::cout << "--------------------------------------------" << endl;

		std::cout << "Please press Enter to draw a card!" << endl;
		std::cin.get();

		value = (rand() % 12) + 1;
		game = twoPlayers(value, player1, player2);
		player1 = game.p1;
		player2 = game.p2;
		

		std::cout << "Total steps for Player 1: " << player1 << endl;
		std::cout << endl;

		if (player1 == 30)
		{
			std::cout << "Player 1 has reached the End point." << endl;
			std::cout << "Congratulations! Player 1 is the winner!!" << endl;
			break;
		}

		std::cout << "--------------------------------------------" << endl;
		std::cout << "             =.= Player 2 =.="                << endl;
		std::cout << "--------------------------------------------" << endl;
		std::cout << "Please press Enter to draw a card!" << endl;
		std::cin.get();

		value = (rand() % 12) + 1;
		game = twoPlayers(value, player2, player1);
		player2 = game.p1;
		player1 = game.p2;

		std::cout << "Total steps for Player 2: " << player2 << endl;
		std::cout << endl << endl;

		if (player2 == 30)
		{
			std::cout << "Player 2 has reached the End point." << endl;
			std::cout << "Congratulations! Player 2 is the winner!" << endl;
			break;
		}
	}

	std::cout << "That was fun!!" << endl;

	return;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


int main()
{
	int one = 0;
	char another;
	srand(time(0));
	
	std::cout << "-------------------------------------------------" << endl;
	std::cout << "       ***Welcome to Sorry Board Game***" << endl;
	std::cout << "**This game can only be played with 2 players**" << endl;
	std::cout << "-------------------------------------------------" << endl;
	std::cout << endl << endl;

	do {
		Round(1); 
			std::cout << "Would you like to play again? (Y/y for yes, or any other letters/numbers to exit)" << endl;
			std::cin >> another;
			if (another == 'Y' || another == 'y') {
				one = 1;
			}
			else {
				one = 0;
			}
	} while (one == 1);

	std::cout << "Goodbye. Thank you for playing the game." << endl << endl;

	return 1;
}
