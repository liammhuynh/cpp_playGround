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
