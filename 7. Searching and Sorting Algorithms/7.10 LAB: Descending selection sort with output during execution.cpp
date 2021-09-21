/* Write a void function SelectionSortDescendTrace() that takes an integer array and sorts the array into descending order. 
The function should use nested loops and output the array after each iteration of the outer loop, thus outputting the array N-1 times (where N is the size). Complete main() to read in a list of up to 10 positive integers (ending in -1) and then call the SelectionSortDescendTrace() function.
If the input is:
20 10 30 40 -1
then the output is:
40 10 30 20
40 30 10 20
40 30 20 10 */



#include <iostream>

using namespace std;

void SelectionSortDescendTrace(int numbers[], int numElems) {
    int maxInd;
    for (int i = 0; i < numElems - 1; ++i) {
        maxInd = i;
        for (int j = i; j < numElems; ++j) {
            if (numbers[j] > numbers[maxInd]) {
                maxInd = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[maxInd];
        numbers[maxInd] = temp;
        for (int j = 0; j < numElems; j++) {
            cout << numbers[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numbers[10];
    int numElements = 0;
    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
        if (numbers[i] == -1)
            break;
        ++numElements;
    }
    SelectionSortDescendTrace(numbers, numElements);
    return 0;
}
