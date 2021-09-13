#include <iostream>
#include <vector> 
#include <stdio.h>
using namespace std;


vector<int> GetUserValues(vector<int> &userValues, int numValues) {
    int num;
    for(int i = 0; i < numValues; ++i) {
        cin >> num;
        userValues.push_back(num);
    }
    return userValues;
}

void OutputIntsLessThanOrEqualToThreshold(vector<int> userValues, int upperThreshold) {
    for(int i = 0; i < userValues.size(); ++i) {
        if(userValues[i] <= upperThreshold) {
            cout << userValues[i] << " ";
        }
    }
    cout << endl;
}

int main() {
   vector<int> userValues; 
   int upperThreshold;
   int numValues;
   
   cin >> numValues;
   userValues = GetUserValues(userValues, numValues);

   cin >> upperThreshold;
   OutputIntsLessThanOrEqualToThreshold(userValues, upperThreshold);

   return 0;
}
