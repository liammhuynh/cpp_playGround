/* Thuy M Huynh
   COMP-SCI 201R - Instructor May Zeineldin
   Program 1
   Created on 09/10/2021
   Due day 09/12/2021 */



   //---------------------------------------------------------------------

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