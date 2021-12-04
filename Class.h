#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student {

public:
	Student();
	bool AcquireData(istream& in);
	bool PrintData(ostream& out) const;
	string GetFirstName() const;
	string GetLastName() const;
	float CourseAverage() const;
	bool DisplayCourseAverage(ostream& out) const;
	string LetterGrade() const;

private:
	string firstName;
	string lastName;
	float quizScore[4];
	float examScore[2];
	float finalProject;
};

