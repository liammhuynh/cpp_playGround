/* Write a loop that subtracts 1 from each element in lowerScores. 
If the element was already 0 or negative, assign 0 to the element. 
Ex: lowerScores = {5, 0, 2, -3} becomes {4, 0, 1, 0}. */




#include <iostream>
using namespace std;

int main() {
   const int SCORES_SIZE = 4;
   int lowerScores[SCORES_SIZE];
   int i;

   for (i = 0; i < SCORES_SIZE; ++i) {
      cin >> lowerScores[i];
   }

   /* Your solution goes here  */
   
   for (i = 0; i < SCORES_SIZE; i++) {
      if (lowerScores[i] > 0) {
         lowerScores[i] = lowerScores[i]-1;
      }
      else if (lowerScores[i] <=0){
         lowerScores [i] = 0;
      }
}
   for (i = 0; i < SCORES_SIZE; ++i) {
      cout << lowerScores[i] << " ";
   }
   cout << endl;

   return 0;
}
