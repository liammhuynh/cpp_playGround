/* 
This program will store roster and rating information for a soccer team. Coaches rate players during tryouts to ensure a balanced team.

(1) Prompt the user to input five pairs of numbers: A player's jersey number (0 - 99) and the player's rating (1 - 9). 
Store the jersey numbers in one int vector and the ratings in another int vector. 
Output these vectors (i.e., output the roster). 
(2) Implement a menu of options for a user to modify the roster. Each option is represented by a single character. 
The program initially outputs the menu, and outputs the menu after a user chooses an option.
The program ends when the user chooses the option to Quit. For this step, the other options do nothing.
(3) Implement the "Output roster" menu option.
(4) Implement the "Add player" menu option. Prompt the user for a new player's jersey number and rating. Append the values to the two vectors.
(5) Implement the "Delete player" menu option. Prompt the user for a player's jersey number. Remove the player from the roster (delete the jersey number and rating).
(6) Implement the "Update player rating" menu option. Prompt the user for a player's jersey number. Prompt again for a new rating for the player, and then change that player's rating.
(7) Implement the "Output players above a rating" menu option. Prompt the user for a rating. Print the jersey number and rating for all players with ratings above the entered value. 
*/


#include <iostream>
#include <vector>
using namespace std;

int main()
{
   // below two lines create vectors of jerseyNumber and rating of type int
vector< int> jerseyNumber;
vector< int> rating;
int temp; //this temp variable is for storing user input temoporarily

for (int i = 1; i <= 5; i++) //this for loop iterates 5 times to stores user input of jersey number and rating in above declared vector
   {
cout << "Enter player " << i << "'s jersey number:" << endl; //prompts user to enter the jersey number
cin >> temp;
if ((temp >= 0) && (temp <= 99)) //checks if jerser number is from 0 to 99 then
       {
jerseyNumber.push_back(temp); // that jersey number is inserted into vector jerseyNumber
       }

cout << "Enter player " << i << "'s rating:" <<endl; //prompts user to enter the rating
cin >> temp;
if ((temp >= 0) && (temp <= 9)) //checks if players rating is from 0 to 9 then
       {
   rating.push_back(temp); // that players rating is inserted into vector rating
       }
cout << endl;
} 
  
cout << "ROSTER" << endl;
for (int i = 0; i < 5; i++) // as per question part (1) this for loop outputs these vectors i.e. jerseyNumber and rating
{
   cout << "Player " << i + 1 << " -- " << "Jersey number: " << jerseyNumber.at(i) << ", Rating: " << rating.at(i) << endl;
   }

char option;
while (true) //this while loop iterates until q i.e. Quit is not entered
   {
       // below are the part 2 menu of options that appears
cout << endl;
cout << "MENU" << endl;
cout << "a - Add player" << endl;
cout << "d - Remove player" << endl;
cout << "u - Update player rating" << endl;
cout << "r - Output players above a rating" << endl;
cout << "o - Output roster" << endl;
cout << "q - Quit" << endl << endl;

cout << "Choose an option:" <<endl; //prompts user to choose an option from above menu
cin >> option;

switch (option) //this switch statement makes the control jump to the case which user wants to operate
       {
case 'a':
case 'A': //this case is for adding the player
cout << "Enter another player's jersey number: "; //prompts user to enter the jersey number
cin >> temp;
if ((temp >= 0) && (temp <= 99)) //checks if jerser number is from 0 to 99 then
               {
jerseyNumber.push_back(temp); // that jersey number is inserted into vector jerseyNumber
               }
cout << "Enter another player's rating: "; //prompts user to enter the rating
cin >> temp;
if ((temp >= 0) && (temp <= 9)) //checks if players rating is from 0 to 9 then
               {
rating.push_back(temp); // that players rating is inserted into vector rating
               }
break;

case 'd':
case 'D': //this case is for deleting the player
cout << "Enter a jersey number: "; // prompts user to enter the jersey number
cin >> temp;
for (int i = 0; i < jerseyNumber.size(); i++) //this for loop iterates over vector jerseyNumber
               {
if (jerseyNumber.at(i) == temp) //checks if user input is equal to the vector element
                   {
jerseyNumber.erase(jerseyNumber.begin() + i); //as given in question using erase function to remove player jersey number
rating.erase(rating.begin() + i); //renove the players rating as well
break;
                   }
} break;

case 'u':
case 'U': //this case is for updating the player information
cout << "Enter a jersey number: "; //prompts user to enter the jersey number
cin >> temp;

for (int i = 0; i < jerseyNumber.size(); i++) //this for loop iterates through vector jerseyNumber
               {
if (jerseyNumber.at(i) == temp) //checks if user input is equal to the vector element then
                   {
cout << "Enter a new rating " << "for player: "; // re-promps user to enter a new rating
cin >> temp;
rating.at(i) = temp; //updates the user rating
break;
                   }
} break;

case 'r':
case 'R': //this case is for Output of players above a specified rating
cout << "Enter a rating: "; // promps user to enter rating
cin >> temp;
cout << "\nABOVE " << temp << endl;

for (int i = 0; i < jerseyNumber.size(); i++) // this for loop iterates through vector jerseyNumber
if (rating.at(i) > temp) //checks if user input rating is is less than than jerseyNumber then
cout << "Player " << i + 1 << " -- " << "Jersey number: " << jerseyNumber.at(i) // outputs the jerseyNumber with its rating
<< ", Rating: " << rating.at(i) << endl;
break;

case 'o':
case 'O': // this case is for printing the roster information
cout << "ROSTER" << endl;
for (int i = 0; i < jerseyNumber.size(); i++) //this for loop iterates over vector jerseyNumber
cout << "Player " << i + 1 << " -- " << "Jersey number: " << jerseyNumber.at(i)
<< ", Rating: " << rating.at(i) << endl;
break;

case 'q':
case 'Q': //this case is when user wants to quit
return 0;

default: cout << "Invalid option entered!!" << " Try again!!" << endl; //this is default option if user inputs incvalid option
}
}
}
  
