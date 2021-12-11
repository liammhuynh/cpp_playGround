#include "queue.h"
#include <iostream>	
using namespace std;


queue::queue()
{
	numPatients = 0;
}

int queue::addPatient(patient p)                                             // adds a normal patient to the end

{
	if (numPatients >= MAXPATIENTS)
	{
		return 0;
	}

	else
	List[numPatients] = p;
	numPatients++;
	return 1;
}

int queue::addemergencyPatient(patient p)                                       // adds a critically ill patient to the beginning
{
	int i;
	if (numPatients >= MAXPATIENTS)
	{
		return 0;
	}

	for (i = numPatients - 1; i >= 0; i--)
		{
			List[i + 1] = List[i];
		}

	List[0] = p;
	numPatients++;
	return 1;
}

patient queue::takePatient()
{
	int i; patient p;
	if (numPatients == 0)
	{
		strcpy_s(p.ID, "");
		return p;
	}

	p = List[0];
	numPatients--;

	for (i = 0; i < numPatients; i++)
	{
		List[i] = List[i + 1];
	}
	return p;
}

int queue::cancelPatient(patient* p)
{
	int i, j, found = 0;                                                                      // search for patient

	for (i = 0; i < numPatients; i++)
	{
		if (_stricmp(List[i].ID, p->ID) == 0)
		{
			*p = List[i]; found = 1;                                                          // move all following patients one position forward
			numPatients--;

			for (j = i; j < numPatients; j++)
			{
				List[j] = List[j + 1];
			}
		}
	}
	return found;
}

void queue::outputList()
{
	int i;
	if (numPatients == 0)
	{
		cout << "Queue is Empty" << endl;
	}

	else
	{
		cout << endl << "All current patients:" << endl;
		for (i = 0; i < numPatients; i++)
		{
			cout << "First name : " << List[i].FirstName << endl;
			cout << "Last name : " << List[i].LastName << endl;
			cout << "Social security number: " << List[i].ID << endl << endl;
		}
	}
}
