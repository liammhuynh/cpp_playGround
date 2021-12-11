#pragma once
#include "patient.h"
#include <iostream>

class queue : public patient
{
public:
	queue();
	int addPatient(patient p);
	int addemergencyPatient(patient p);
	patient takePatient();
	int cancelPatient(patient* p);
	void outputList();
	char departmentName[50];

private:
	int numPatients;
	patient List[MAXPATIENTS];
};
