int twoPlayers(int Position) {

	srand(time(0));                                      // seed random
	unsigned int p1Position = 0, p2Position = 0;                          // players positions
	unsigned int card = 0;                               // card draw
	unsigned int pChoice;                                // option the user wants after players draws 4
	unsigned int temp = 0;                               // hold a temporary value
	bool restart = false;                                // bypasses the remaining turn
	                          

	while (p1Position <= 30 && p2Position <= 30) {

		while (p1Position <= 30) {

			card = (rand() % 11) + 1;
			cout << endl;

			if (p1Position == 0) {

				if (card != 1 && card != 2) {
					cout << "You drew " << card << ", " << "Sorry! You did not get (1 or 2)" << endl;
					cout << "You need to skip your turn." << endl;
					return p1Position;
				}

				else if (card == 1 || card == 2) {
					cout << "You drew " << card << ", " << "Congratulations!" << endl;
					cout << "You can start your turn." << endl;
					p1Position = p1Position + card;
					return p1Position;
				}
			}


			if (p1Position > 0) {

				if (card != 4) {
					cout << "Your card is " << card << endl;
					cout << "Move " << card << " steps foward." << endl;
					p1Position = p1Position + card;
					return p1Position;
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
							return p1Position;

						case 2:

							temp = 0;
							p1Position = p2Position;
							p2Position = temp;
							cout << "You chose to take opponent spot." << endl;
							cout << "Sorry! Player 2 must go back to Home." << endl;
							return p1Position;
						}
					}
				}

				if (p1Position + card > 30) {

					cout << "You need to get exactly 30 steps to win." << endl;
					cout << "You must have to skip this turn." << endl;
					return p1Position;

				}

				if (p1Position == 30) {
					cout << "Player 1 has won the game!" << endl;
					restart = true;
				}
			}
		}
		



		if (restart == false) {

			while (p2Position <= 30) {

				card = (rand() % 11) + 1;
				cout << endl;

				if (p2Position == 0) {

					if (card != 1 && card != 2) {
						cout << "You drew " << card << ", " << "Sorry! You did not get (1 or 2)" << endl;
						cout << "You need to skip your turn." << endl;
						return p2Position;
					}


					else if (card == 1 || card == 2) {
						cout << "You drew " << card << ", " << "Congratulations!" << endl;
						cout << "You can start your turn." << endl;
						p2Position = p2Position + card;
						return p2Position;
					}
				}



				if (p2Position > 0) {

					if (card != 4) {
						cout << "Your card is " << card << endl;
						cout << "Move " << card << " steps foward." << endl;
						p2Position = p2Position + card;
						return p2Position;
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
								return p2Position;

							case 2:

								temp = 0;
								p2Position = p1Position;
								p1Position = temp;
								cout << "You chose to take opponent spot." << endl;
								cout << "Sorry! Player 1 must get back to Home." << endl;
								return p2Position;
							}

							if (p2Position > 30) {

								cout << "You need to get exactly 30 steps to win." << endl;
								cout << "You must have to skip this turn." << endl;
							}

							if (p2Position == 30) {
								cout << "Player 2 has won the game!" << endl;
							}
						}
					}
					
				}
			}
		}

	}
}
