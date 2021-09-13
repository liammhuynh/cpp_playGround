#include <iostream>
using namespace std;

int LargestNumber(int num1, int num2, int num3)
{
   int list1[3] = {num1, num2, num3};
   int max = 0;

   for (int i = 0; i < 3; i++)
   {
      if (list1[i] > max)
         max = list1[i];
   }

   return max;
}

int SmallestNumber(int num1, int num2, int num3)
{
   int list1[3] = {num1, num2, num3};
   int min = list1[0];

   for (int i = 1; i < 3; i++)
   {
      if (list1[i] < min)
         min = list1[i];
   }

   return min;
}

int main() {
   /* Type your code here. Your code must call the functions.  */
   int num1;
   int num2;
   int num3;
   cin >> num1;
   cin >> num2;
   cin >> num3;

   cout << "largest: " << LargestNumber(num1, num2, num3) << endl;
   cout << "smallest: " << SmallestNumber(num1, num2, num3) << endl;

   return 0;
}
