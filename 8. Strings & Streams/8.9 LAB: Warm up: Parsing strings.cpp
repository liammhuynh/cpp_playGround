/* (1) Prompt the user for a string that contains two strings separated by a comma. 
Examples of strings that can be accepted:
Jill, Allen
Jill , Allen
Jill,Allen
(2) Print an error message if the input string does not contain a comma. 
Continue to prompt until a valid string is entered. Note: If the input contains a comma, then assume that the input also contains two strings. 
(3) Extract the two words from the input string and remove any spaces. Store the strings in two separate variables and output the strings.
(4) Using a loop, extend the program to handle multiple lines of input. Continue until the user enters q to quit. */

#include <iostream>
#include <sstream>
using namespace std;

bool isComma(string input){
for(int i = 0; i < input.length(); i++)
if(input[i] == ',')
return true;
return false;
}
int main()
{
string input;
while(1){
cout << "Enter input string:\n";
getline(cin, input);
if(input != "q"){
if (isComma(input)){
string firstWord = "", secondWord = "";
int count = 0, i = 0;
for(i = 0; i < input.length(); i++)
if(input[i] != ' ' && input[i] != ',')
firstWord += input[i];
else
break;
for(i = i; i < input.length(); i++)
if(input[i] != ' ' && input[i] != ',')
secondWord += input[i];
cout << "First word: " << firstWord << endl;
cout << "Second word: " << secondWord << endl << endl;
}
else{
cout << "Error: No comma in string.\n\n";
}
}
else
break;
}
return 0;
}
