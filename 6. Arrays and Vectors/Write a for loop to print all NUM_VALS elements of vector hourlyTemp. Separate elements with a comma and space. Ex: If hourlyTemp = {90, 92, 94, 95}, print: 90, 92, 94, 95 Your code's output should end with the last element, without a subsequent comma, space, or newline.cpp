/* Write a for loop to print all NUM_VALS elements of vector hourlyTemp. Separate elements with a comma and space. Ex: If hourlyTemp = {90, 92, 94, 95}, print:
90, 92, 94, 95
Your code's output should end with the last element, without a subsequent comma, space, or newline. */


#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   unsigned int i;
   vector<int> hourlyTemp(NUM_VALS);

   for (i = 0; i < hourlyTemp.size(); ++i) {
      cin >> hourlyTemp.at(i);
   }

   /* Your solution goes here  */
   
  for(int i=0; i<NUM_VALS; i++)
   {
   if(i==0)
   cout << hourlyTemp[i];
   else cout <<", " << hourlyTemp[i];
   }

   cout << endl;

   return 0;
}
