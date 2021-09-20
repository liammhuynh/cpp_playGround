/* Write a loop that sets newScores to oldScores shifted once left, with element 0 copied to the end. 
Ex: If oldScores = {10, 20, 30, 40}, then newScores = {20, 30, 40, 10}. */


#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SCORES_SIZE = 4;
   vector<int> oldScores(SCORES_SIZE);
   vector<int> newScores(SCORES_SIZE);
   unsigned int i;

   for (i = 0; i < oldScores.size(); ++i) {
      cin >> oldScores.at(i);
   }

   /* Your solution goes here  */
   
      int j = 0;
   for(i=0; i < SCORES_SIZE; i++){
       if(i == SCORES_SIZE - 1){
           j = 0;
       }
       else{
           j = i+1;
      }
       newScores[i] = oldScores[j];
   }

   for (i = 0; i < newScores.size(); ++i) {
      cout << newScores.at(i) << " ";
   }
   cout << endl;

   return 0;
}
