/* Write a program that first gets a list of integers from input. The input begins with an integer indicating the number of integers that follow. 
Then, get the last value from the input, which indicates a threshold. Output all integers less than or equal to that last threshold value. 
Ex: If the input is:
5 50 60 140 200 75 100
the output is:
50,60,75,
For coding simplicity, follow every output value by a comma, including the last one.
Such functionality is common on sites like Amazon, where a user can filter results. */





#include <iostream>
#include <vector>

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
            cout << userValues[i] << ",";
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
