#include <iostream>	
#include <cstdlib>
#include "patient.h"
#include "queue.h"
using namespace std;


patient InputPatient(void)
{
	patient p;
	cout << "Please enter data of the patient." << endl << "First name: " << endl;
	cin.getline(p.FirstName, sizeof(p.FirstName));
	cout << "Last name: " << endl;
	cin.getline(p.LastName, sizeof(p.LastName));
	cout << "Social security number: " << endl;
	cin.getline(p.ID, sizeof(p.ID));

	if (p.FirstName[0] == 0 || p.LastName[0] == 0 || p.ID[0] == 0)
	{
		strcpy_s(p.ID, "");
		cout << "Error! Data is not valid." << endl;
	}
	return p;
}

void OutputPatient(patient* p)
{
	system("pause");
	system("CLS");

	if (p == NULL || p->ID[0] == 0)
	{
		cout << "No data" << endl;
		return;
	}
	else
	cout << "Patient data: " << endl;
	cout << "First name: " << p->FirstName << endl;
	cout << "Last name: " << p->LastName << endl;
	cout << "Social security number: " << p->ID << endl;
	system("pause");
	system("CLS");
}

int readNumber()
{
	char buffer[20];
	cin.getline(buffer, sizeof(buffer));
	system("CLS");
	return atoi(buffer);
}

void departmentMenu(queue* q)
{
	int choice = 0, success;
	patient p;
	while (choice != 6)
	{
		cout << "Welcome to department: " << q->departmentName << endl;
		cout << "Please enter your choice: " << endl;
		cout << "1: Add patient" << endl;
		cout << "2: Add critically ill patient" << endl;
		cout << "3: Take out patient for operation" << endl;
		cout << "4: Cancel patient" << endl;
		cout << "5: List the queue of patients" << endl;
		cout << "6: Exit the department" << endl;

		choice = readNumber();

		switch (choice)
		{
		case 1:                                                                                           // Add normal patient

			p = InputPatient();
			if (p.ID[0])
			{
				success = q->addPatient(p);
				if (success)
				{
					cout << endl << "Patient added!" << endl;
				}

				else
				{
					cout << endl << "Error! The queue is full. Cannot add anymore patient." << endl;
				}
				OutputPatient(&p);
				cout << endl << endl;
			}
			break;

		case 2:                                                                                            // Add critically ill patient

			p = InputPatient();
			if (p.ID[0])
			{
				success = q->addemergencyPatient(p);
				if (success)
				{
					cout << endl << "Patient added!" << endl;
				}

				else
				{
					cout << endl << "Error! The queue is full. Cannot add anymore patient." << endl;
				}
				OutputPatient(&p);
				cout << endl << endl;
			}
			break;

		case 3:                                                                                              // Take out patient

			p = q->takePatient();

			if (p.ID[0])
			{
				cout << endl << "Patient moved to the operation room! " << endl;
				OutputPatient(&p);
			}

			else
			{
				cout << endl << "No more patients." << endl;
			}
			cout << endl << endl;
			break;

		case 4:                                                                                              // Cancel patient

			p = InputPatient();

			if (p.ID[0])
			{
				success = q->cancelPatient(&p);

				if (success)
				{
					cout << endl << "Patient removed!" << endl;
				}

				else
				{
					cout << endl << "Error! Patient does not exist" << endl;
				}

				OutputPatient(&p);

				cout << endl << endl;
			}
			break;

		case 5:                                                                                               // List queue

			q->outputList();
			cout << endl << endl;
			break;
		}
	}
}



int main()
{
	int i, MenuChoice = 0;
	queue departments[3];
	strcpy_s(departments[0].departmentName, "Heart Clinic \n");                             //https://en.cppreference.com/w/c/string/byte/strcpy
	strcpy_s(departments[1].departmentName, "Lung Clinic \n");
	strcpy_s(departments[2].departmentName, "Plastic Surgery \n"); 


	while (MenuChoice != 4)
	{
		cout << "Welcome to 201 Hospital" << endl;
		for (i = 0; i < 3; i++)
		{
			cout << (i + 1) << ": " << departments[i].departmentName;
		}
		cout << "4: Exit" << endl;
		cout << "Please enter your choice: " << endl;

		MenuChoice = readNumber();

		if (MenuChoice >= 1 && MenuChoice <= 3)
		{
			departmentMenu(departments + (MenuChoice - 1));
		}
	}
	return 0;
}