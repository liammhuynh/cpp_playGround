#include <iostream>
#include <iomanip>
using namespace std;

/* Define your function here */

double StepsToMiles (double userSteps)
{
   double miles = userSteps / 2000;
   return miles;
}

int main() {
   /* Type your code here */
   
   double userInput;
   cin >> userInput;
   cout << fixed << setprecision(2) << StepsToMiles (userInput) << endl;
 

   return 0;
}
