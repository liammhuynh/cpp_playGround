/* Assign numMatches with the number of elements in userValues that equal matchValue. userValues has NUM_VALS elements. 
Ex: If userValues is {2, 2, 1, 2} and matchValue is 2 , then numMatches should be 3. */
 

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   int matchValue;
   unsigned int i;
   int numMatches = -99; // Assign numMatches with 0 before your for loop
   vector<int> userValues(NUM_VALS);

   cin >> matchValue;

   for (i = 0; i < userValues.size(); ++i) {
      cin >> userValues.at(i);
   }

   /* Your solution goes here  */
    numMatches = 0;
        for (i = 0; i < NUM_VALS; ++i) {
                if(userValues[i] == matchValue) {
                        numMatches++;
                        }
        }

   cout << "matchValue: " << matchValue << ", numMatches: " << numMatches << endl;

   return 0;
}
