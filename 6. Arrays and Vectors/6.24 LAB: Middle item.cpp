/* Given a sorted list of integers, output the middle integer. 
A negative number indicates the end of the input (the negative number is not a part of the sorted list). Assume the number of integers is always odd.

Ex: If the input is:
2 3 4 8 11 -1 
the output is:
Middle item: 4
The maximum number of inputs for any test case should not exceed 9. If exceeded, output "Too many numbers". */


#include <iostream>
#include <vector>   // Must include vector library to use vectors
using namespace std;

int main() {

   /* Type your code here. */
   vector <int> userValue;
   int counter = 0;
   int value;
   cin >>value;
   int mid;
   
   while ((value >= 0) && (counter <= 9))
{
   userValue.push_back (value);
   cin >> value;
   counter ++;
}
if (counter > 9)
{
   cout << "Too many numbers" << endl;
}
else {
   mid = counter/2;
   cout << "Middle item: " << userValue.at(mid) << endl;
   
}

   return 0;
}
