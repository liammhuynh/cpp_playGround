/* For any element in keysList with a value greater than 100, print the corresponding value in itemsList, followed by a space. 
Ex: If keysList = {42, 105, 101, 100} and itemsList = {10, 20, 30, 40}, print:
20 30 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SIZE_LIST = 4;
   vector<int> keysList(SIZE_LIST);
   vector<int> itemsList(SIZE_LIST);
   unsigned int i;

   for (i = 0; i < keysList.size(); ++i) {
      cin >> keysList.at(i);
   }

   for (i = 0; i < itemsList.size(); ++i) {
      cin >> itemsList.at(i);
   }

   /* Your solution goes here  */
   
   for (i = 0; i < SIZE_LIST; i++){
		if (keysList.at(i) > 100){
			cout << itemsList.at(i) << " ";
		}
	}

   cout << endl;

   return 0;
}
