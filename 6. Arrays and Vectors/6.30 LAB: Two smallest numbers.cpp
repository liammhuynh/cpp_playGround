/* Write a program that reads a list of integers, and outputs the two smallest integers in the list, in ascending order. 
The input begins with an integer indicating the number of integers that follow.
Ex: If the input is:
5 10 5 3 21 2
the output is:
2 and 3
You can assume that the list of integers will have at least 2 values.
To achieve the above, first read the integers into a vector. */

#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,i,x,first,second;
   //take input of number of elements
   cin>>n;
   //initialize vector as a
   vector <int> a;
   for(i=0;i<n;i++)
   {
   //take input of element
   cin>>x;
   //push the element into the vector
   a.push_back(x);
   }
   //initialize first to maximum limit of int
   first=INT_MAX;
   //run a loop to find the smallest element
   for(i=0;i<n;i++)
   {
   if (a[i]<first)
   first=a[i];
   }
   //initialize second to maximum limit of int
   second=INT_MAX;
   //run a loop to find the second smallest element
   for(i=0;i<n;i++)
   {
   if (a[i]<second && a[i]!=first)
   second=a[i];
   }
   cout<<first<<" and "<<second<<endl;
   return 0;
}
