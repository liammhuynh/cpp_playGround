#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    int a = 0, b = 1, c, i;
    
    if( n == 0){
        return a;
        }
        
    else if (n <0){
    return -1;
    }
    for(i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;}
    
    
int main() {
   int startNum;
      
   cin >> startNum;
   cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;

   return 0;
}
