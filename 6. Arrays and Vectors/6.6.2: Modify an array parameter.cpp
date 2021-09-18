/* Write a function SwapArrayEnds() that swaps the first and last elements of the function's array parameter. 
Ex: sortArray = {10, 20, 30, 40} becomes {40, 20, 30, 10}. */



#include <iostream>
using namespace std;

void SwapArrayEnds(int sortArray[],int size){
   int temp = sortArray[0];
   sortArray[0] = sortArray[size-1];
   sortArray[size-1] = temp;
}
/* Your solution goes here  */

int main() {
   const int SORT_ARR_SIZE = 4;
   int sortArray[SORT_ARR_SIZE];
   int i;
   int userNum;

   for (i = 0; i < SORT_ARR_SIZE; ++i) {
      cin >> userNum;
      sortArray[i] = userNum;
   }

   SwapArrayEnds(sortArray, SORT_ARR_SIZE);

   for (i = 0; i < SORT_ARR_SIZE; ++i) {
      cout <<  sortArray[i] << " ";
   }
   cout << endl;

   return 0;
}
