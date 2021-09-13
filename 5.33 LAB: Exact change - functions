#include <iostream>
#include <vector> 
using namespace std;

void ExactChange(int userTotal, vector<int> &coinVals) {

   coinVals.reserve(5);

   coinVals[0] = userTotal / 100;

   userTotal %= 100;

   coinVals[1] = userTotal / 25;

   userTotal %= 25;

   coinVals[2] = userTotal / 10;

   userTotal %= 10;

   coinVals[3] = userTotal / 5;

   userTotal %= 5;

   coinVals[4] = userTotal;

}

int main() {

   vector<int> coins;

   int value;

   cin >> value;

   if (value <= 0) {

       cout << "no change" << endl;

   } else {

       ExactChange(value, coins);

       if (coins[0] != 0) cout << coins[0] << " " << (coins[0] == 1 ? "dollar" : "dollars") << endl;

       if (coins[1] != 0) cout << coins[1] << " " << (coins[1] == 1 ? "quarter" : "quarters") << endl;

       if (coins[2] != 0) cout << coins[2] << " " << (coins[2] == 1 ? "dime" : "dimes") << endl;

       if (coins[3] != 0) cout << coins[3] << " " << (coins[3] == 1 ? "nickel" : "nickels") << endl;

       if (coins[4] != 0) cout << coins[4] << " " << (coins[4] == 1 ? "penny" : "pennies") << endl;

   }

   return 0;

}
