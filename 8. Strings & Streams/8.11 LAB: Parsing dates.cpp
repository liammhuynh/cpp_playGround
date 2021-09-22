/* Complete main() to read dates from input, one date per line. Each date's format must be as follows: March 1, 1990. 
Any date not following that format is incorrect and should be ignored. Use the substr() function to parse the string and extract the date. The input ends with -1 on a line alone. Output each correct date as: 3/1/1990.

Ex: If the input is:

March 1, 1990
April 2 1995
7/15/20
December 13, 2003
-1
then the output is:

3/1/1990
12/13/2003 */



#include <iostream>
#include <string>
using namespace std;
// function to get the month number
int DateParser(string month) {
   int monthInt = 0;
   if (month == "January")
       monthInt = 1;
   else if (month == "February")
       monthInt = 2;
   else if (month == "March")
       monthInt = 3;
   else if (month == "April")
       monthInt = 4;
   else if (month == "May")
       monthInt = 5;
   else if (month == "June")
       monthInt = 6;
   else if (month == "July")
       monthInt = 7;
   else if (month == "August")
       monthInt = 8;
   else if (month == "September")
       monthInt = 9;
   else if (month == "October")
       monthInt = 10;
   else if (month == "November")
       monthInt = 11;
   else if (month == "December")
       monthInt = 12;
   return monthInt;
}

int main () {
   string input; // string for input
   // run an infinite loop until -1 is entered
   while(true) {
       getline(cin,input); // reading whole line. Here getline is used to read string with spaces
       if(input == "-1") // if -1 entered then break the infinite loop
           break;
       int firstSpace = 0, firstComma = 0; // variable to store the pos of first space and comma
       // to find first space in input date
       for(int i=0;i<input.length();i++) {
           if(input[i] == ' ') {
               firstSpace = i; // break when first space found
               break;
           }
       }
       // to find first comma in the input date
       for(int i=0;i<input.length();i++) {
           if(input[i] == ',') {
               firstComma = i; // break when found
               break;
           }
       }
       // if first space or comma not found or comma found before space then go to read next date
       if(firstSpace == 0 || firstComma == 0 || firstComma < firstSpace)
           continue;
       // getting month name, month name is from index 0 and upto the length firstspace
       string month = input.substr(0,firstSpace);
       // getting day, it starts after first sapce pos and of length (firstComma-firstSpace-1)
       string day = input.substr(firstSpace+1,firstComma-firstSpace-1);
       // getting year, it starts from pos (firscomma+2) and ends at last
       string year = input.substr(firstComma+2);
       // check whether day contains non-digit character
       bool flag = true;
       for(int i=0;i<day.length();i++)
           if(day[i] < '0' || day[i] > '9') // flag becomes false when non-digit character found
               flag = false;
       if(flag == false) // go to next date when day contains non-digit character
           continue;
       // check whether year contains non-digit character
       flag = true;
       for(int i=0;i<year.length();i++)
           if(year[i] < '0' || year[i] > '9') // flag becomes false when non-digit character found
               flag = false;
       if(flag == false) // go to next date when year contains non-digit character
           continue;
       int m = DateParser(month); // getting integer equivalent of month
       int d = stoi(day); // getting integer form of day
       int y = stoi(year); // getting integer form of year
       if(m == 0 || d <= 0 || d > 31 || y < 0) // go to next date if month, day or year is not valid
           continue;
       cout<<m<<"/"<<d<<"/"<<y<<"\n"; // print in required form
   }
}
