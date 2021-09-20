/* Write a program that first gets a list of integers from input. The input begins with an integer indicating the number of integers that follow. 
That list is followed by two more integers representing lower and upper bounds of a range. Your program should output all integers from the list that are within that range (inclusive of the bounds). For coding simplicity, follow each output integer by a comma, even the last one. The output ends with a newline.
Ex: If the input is:
5 25 51 0 200 33
0 50
then the output is:
25,0,33,
(the bounds are 0-50, so 51 and 200 are out of range and thus not output).
To achieve the above, first read the list of integers into a vector. */


#include <iostream>
#include <vector>
using namespace std;

int main() {
int n, val;
cin>>n;

vector<int> arr;
for(int i = 0;i<n;i++){
cin>>val;
arr.push_back(val);
}

int min, max;
cin>>min;
cin>>max;

for(int i = 0;i<n;i++){
if(arr[i]>=min && arr[i]<=max){
cout<<arr[i]<<",";
}
}
cout << endl;
return 0;
}
