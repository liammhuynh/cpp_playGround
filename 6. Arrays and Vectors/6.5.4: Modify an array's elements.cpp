/* Double any element's value that is less than controlValue. 
Ex: If controlValue = 10, then dataPoints = {2, 12, 9, 20} becomes {4, 12, 18, 20}. */


#include <iostream>
using namespace std;

int main() {
   const int NUM_POINTS = 4;
   int dataPoints[NUM_POINTS];
   int controlValue;
   int i;

   cin >> controlValue;

   for (i = 0; i < NUM_POINTS; ++i) {
      cin >> dataPoints[i];
   }

   /* Your solution goes here  */
   for (i=0; i<NUM_POINTS; i++) {
      if (dataPoints [i] < controlValue) {
         dataPoints [i] = dataPoints [i] *2;
         }
   }

   for (i = 0; i < NUM_POINTS; ++i) {
      cout << dataPoints[i] << " " ;
   }
   cout << endl;

   return 0;
}
