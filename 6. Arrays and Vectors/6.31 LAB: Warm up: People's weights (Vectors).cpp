/* Output each floating-point value with two digits after the decimal point, which can be achieved by executing
cout << fixed << setprecision(2); once before all other cout statements.

(1) Prompt the user to enter five numbers, being five people's weights. Store the numbers in a vector of doubles. 
Output the vector's numbers on one line, each number followed by one space. */


#include <iostream>
#include <iomanip>              // For setprecision
#include <vector>
using namespace std;

int main() {

{
//vector
vector<double> vec;
vector<double>::iterator st;
  
//variable declaration
double num, avg, sum = 0, max;
int count=0;
  
for(int i=0; i<5; i++)
{
//get user input
cout<<"Enter weight "<<(i+1)<<":"<<endl;
cin>>num;
  
//push value in vector
vec.push_back(num);
}
  
//display the weight in one row
cout << fixed << setprecision(2);
cout<<"You entered: ";
for (st = vec.begin(); st != vec.end(); ++st)
{
cout<<*st<<" ";
}
cout << endl;

max = vec.front();
  
//calcualte sum and maximum element
for (st = vec.begin(); st != vec.end(); ++st)
{
sum = sum + *st;
if(max<*st)
max = *st;
count++;
}
  
//calculate average
avg = sum / count;
  
//display the result
cout<< endl <<"Total weight: "<<sum;
cout<<endl << "Average weight: "<<avg;
cout<<endl<<"Max weight: "<<max;
}
cout <<endl;
   return 0;
}
