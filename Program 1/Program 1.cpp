// write C++ program to roll a six-sided dice once and then we roll a second dice as many times as is necessary to obtain the same face as the one obtained in the first dice.

/* Rules of the Game:
1- Randomly roll the first dice once (six-sided dice).
2- Randomly roll the second dice.
3- Compare first and second dice:
a. If they are equal in less than 3 rounds, announce that you got a match and that
computer won.
b. If they are not equal in less than 3 rounds, keep checking for a match and then
announce that you got a match in “X” rounds and that the computer lost this turn.
c. Note: First dice only roll randomly once and with each round the second dice will
roll randomly until you get a match.
4- After you announce either the computer won or lost, you will ask the user if they want to
have another turn.
a. If the user wanted to have another turn, then you will repeat all previous steps.
b. If user decided to end the game, then output a message to the user “Have a
great day” and terminate the program. */


#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <string>
using namespace std;

//-----------------------------------------------------------------------

int Dice (int roll)
{
	roll = rand() % 6 + 1;
	return roll;
}

//----------------------------------------------------------------------

int main()
{
	srand(time(NULL));
	int roll_1 = 0, roll_2 = 0;
	int dice_1, dice_2;
	string again;
	
	do
	{
	int rounds = 1;
	dice_1 = Dice(roll_1);
	dice_2 = Dice(roll_2);

	cout << endl;   //looks easier on eyes when user play another turn

		while (rounds <= 3)
		{
			cout << "Round " << rounds << ":" << endl;
			cout << "First dice: " << dice_1 << endl;
			cout << "Second dice: " << dice_2 << endl << endl;

			if (dice_1 == dice_2)
			{
				cout << "COMPUTER WON!!" << endl << endl;
				break;
			}
			else if (dice_1 != dice_2)
			{
				dice_2 = Dice(roll_2);
			}
			rounds = rounds + 1;
		}

		while (rounds > 3)
		{
			cout << "Round " << rounds << ":" << endl;
			cout << "First dice: " << dice_1 << endl;
			cout << "Second dice: " << dice_2 << endl << endl;

			if (dice_1 == dice_2)
			{
				cout << "First dice equal Second dice after " << rounds << " rounds" << endl << endl;
				cout << "Computer lost this turn." << endl << endl;
				break;
			}
			else if (dice_1 != dice_2)
			{
				dice_2 = Dice(roll_2);
			}
			rounds = rounds + 1;

		}

		cout << "Do you want to play again? (Yes/No)" << endl;
		cin >> again;

		if (again == "No" || again == "no" || again == "NO")
		{
			cout << "Have a great day" << endl;
			break;
		}
	} 
	while (again == "Yes" || again == "yes" || again == "YES");
	

	return 0;
}
