/* Given a main() that reads user IDs (until -1), complete the Quicksort() and Partition() functions to sort the IDs in ascending order using the Quicksort algorithm, and output the sorted IDs one per line.
Ex. If the input is:

kaylasimms
julia
myron1994
kaylajones
-1
the output is:

julia
kaylajones
kaylasimms
myron1994  */


#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Partition function to take pivot as middle element
// Rearrange elements which are lesser than the pivot go to the left part
// elements greater than the pivot, go to the right part.
// Vector may be divided in non-equal parts.
// Sort both parts. Apply quicksort algorithm recursively to the left and the right parts.
int Partition(vector<string>&userIDs, int low, int high) {
   int i = low, j = high;
         string tmp;
         string pivot = userIDs[(low + high)/2];
   while (i <= j) {
           while (userIDs[i] < pivot)
                     i++;
       while (userIDs[j] > pivot)
                     j--;
               if (i <= j){   // Swapping the IDs
                     tmp = userIDs[i];
                     userIDs[i] = userIDs[j];
                     userIDs[j] = tmp;
                     i++;
                     j--;
              }
      }
      return i;
}

//Quicksort function to make a partition and recursive calls to it.
void Quicksort(vector<string> &userIDs, int i, int k) {
   int index = Partition(userIDs, i, k);
         if (i < index - 1)
       Quicksort(userIDs, i, index - 1);
         if (index < k)
               Quicksort(userIDs, index, k);
}

int main(int argc, char* argv[])
{
   vector<string> userIDList;
   string userID;
   cin >> userID;
   // taking user input untill "-1"
   while (userID != "-1") {
       userIDList.push_back(userID);
       cin >> userID;
   }
   // Initial call to quicksort
   Quicksort(userIDList, 0, userIDList.size() - 1);
   // displaying the userIDs in ascending order
   for (size_t i = 0; i < userIDList.size(); ++i) {
       cout << userIDList.at(i) << endl;;
   }
   return 0;
}


/* Explanation -

In this code, first user input in form of UserIDs are taken as strings and stored in a vector of strings.
Quicksort is called in the main() to sort the UserIDs.
Quicksort() function first calls partition() in which the middle value is taken as the pivot, 
and all the UserIDs smaller then pivot are kept before and greater than pivot are kept after it.
After this it sort both parts and apply quicksort algorithm recursively 
to the left and the right parts repeating the same process of pivot selection and division of UserIDs in left part and right part.  */
