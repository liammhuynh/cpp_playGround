/* Write a program that reads a list of integers, and outputs those integers in reverse. 
The input begins with an integer indicating the number of integers that follow. For coding simplicity, follow each output integer by a comma, including the last one.
Ex: If the input is:
5 2 4 6 8 10
the output is:
10,8,6,4,2,
To achieve the above, first read the integers into a vector. Then output the vector in reverse. */




#include <iostream>

using namespace std;

int main(){
   int list[20];
   int size, i;
   cin >> size;
   for(i = 0; i < size; i++){
       cin >> list[i];
   }
   for(i = size - 1; i >= 0; i--){
       cout << list[i] << ",";
   }
   cout << endl;
  
   return 0;
}
