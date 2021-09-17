/* Write a loop that sets each array element to the sum of itself and the next element, except for the last element which stays the same. 
Be careful not to index beyond the last element. Ex:
Initial scores:        10, 20, 30, 40
Scores after the loop: 30, 50, 70, 40 */



#include <iostream>
using namespace std;

int main() {
   const int SCORES_SIZE = 4;
   int bonusScores[SCORES_SIZE];
   int i;

   for (i = 0; i < SCORES_SIZE; ++i) {
      cin >> bonusScores[i];
   }

   /* Your solution goes here  */
   for (i=0; i < SCORES_SIZE -1 ; i++) {
      bonusScores [i] = bonusScores [i] + bonusScores [i+1];
   }

   for (i = 0; i < SCORES_SIZE; ++i) {
      cout << bonusScores[i] << " ";
   }
   cout << endl;

   return 0;
}
