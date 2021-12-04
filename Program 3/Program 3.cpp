#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;


struct Inventory
{
    char type;
    string item;
    int quantity;
    double price;
};


int main() {

    int choice;
    cout << "Inventory menu:" << endl;
    cout << "1. Output Electronics Supplies to the screen" << endl;
    cout << "2. Output Office Supplies to the screen" << endl;
    cout << "3. Output Electronics and Office Supplies to \"Summary.txt\" file" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    vector<Inventory> input;
    string line;
    Inventory object;
    string price;
    double totalOE = 0;

    ifstream fileIn("Office.txt");
    
    if (fileIn.is_open()) {
        
        while (fileIn >> object.type >> object.quantity >> object.item >> price) {
            object.price = atof(price.c_str() + 1);
            input.push_back(object);
        }
        fileIn.close();
    }

    else {
        cout << "Error! Cannot open the file" << endl;
    }
        

    switch (choice) {

    case 1:
    {
        double total = 0;
        for (auto object : input) {

            if (object.type == 'O')
                continue;

            cout << object.type << " ";
            cout << right << setw(19) << object.item << " ";
            cout << "\t" << left << setw(10) << "Quantity: " << object.quantity << " ";
            cout << "\t" << left << setw(14) << "Price/piece: $" << object.price << " ";
            totalOE = object.price * object.quantity;
            cout << "\t" << setw(8) << "Total: $" << totalOE << endl;
            total += totalOE;
        }
        cout << "------------------------------------------------------------" << endl;
        cout << "Total price for Electronics in Inventory: $" << total << endl;
        cout << "------------------------------------------------------------" << endl;
        break;
    }

    case 2:
    {
        double total = 0;
        for (auto object : input) {

            if (object.type == 'E')
                continue;

            cout << object.type << " ";
            cout << right << setw(19) << object.item << " ";
            cout << "\t" << left << setw(10) << "Quantity: " << object.quantity << " ";
            cout << "\t" << left << setw(14) << "Price/piece: $" << object.price << " ";
            totalOE = object.price * object.quantity;
            cout << "\t" << setw(8) << "Total: $" << totalOE << endl;
            total += totalOE;
        }
        cout << "------------------------------------------------------------" << endl;
        cout << "Total price for Office Supplies in Inventory: $" << total << endl;
        cout << "------------------------------------------------------------" << endl;
        break;
    }

    case 3:
    {
        ofstream fileOut("Summary.txt");
        double total = 0;

        for (auto object : input) {
            if (object.type == 'O')
                continue;
            fileOut << object.type << " ";
            fileOut << right << setw(19) << object.item << " ";
            fileOut << "\t" << left << setw(10) << "Quantity: " << object.quantity << " ";
            fileOut << "\t" << left << setw(14) << "Price/piece: $" << object.price << " ";
            totalOE = object.quantity * object.price;
            fileOut << "\t" << setw(8) << "Total: $" << totalOE << endl;
            total += totalOE;
        }
        fileOut << "------------------------------------------------------------" << endl;
        fileOut << "Total price for Electronics in Inventory: $" << total << endl;
        fileOut << "------------------------------------------------------------" << endl << endl;
        total = 0;

        for (auto object : input) {
            if (object.type == 'E')
                continue;
            fileOut << object.type << " ";
            fileOut << right << setw(19) << object.item << " ";
            fileOut << "\t" << left << setw(10) << "Quantity: " << object.quantity << " ";
            fileOut << "\t" << left << setw(14) << "Price/piece: $" << object.price << " ";
            totalOE = object.price * object.quantity;
            fileOut << "\t" << setw(8) << "Total: $" << totalOE << endl;
            total += totalOE;
        }
        fileOut << "------------------------------------------------------------" << endl;
        fileOut << "Total price for Office Supplies in Inventory: $" << total << endl;
        fileOut << "------------------------------------------------------------" << endl;
        fileOut.close();
        cout << "Done. Please check file \"Summary.txt\"" << endl;
        break;
    }

    case 4:
    {
        cout << "Goodbye.";
        exit(0);
    }

    }
    
    return 0;
}
