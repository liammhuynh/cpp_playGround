#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   int userNum;
   int divNum;
   int result;
   cin.exceptions(ios::failbit);       // Allow cin to throw exceptions

   /* Type your code here. */
   try {
    cin >> userNum;
    cin >> divNum;
    
   if (divNum < 0 || divNum >0) {
    result = userNum/divNum;
    cout << result << endl;
    }
   else {
     throw result;
     }
}

catch (int result) {
cout << "Runtime Exception:  Divide by zero!" << endl;
}
catch (...){
cout << "Input Exception: basic_ios::clear: iostream error" << endl;
}
   return 0;
}
