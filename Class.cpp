#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Class.h"
using namespace std;

Student::Student() {
	firstName = firstName.empty();                      //https://stackoverflow.com/questions/11556394/initializing-strings-as-null-vs-empty-string
	lastName = lastName.empty();
	for (int i = 0; i < 4; i++)
		quizScore[i] = 0;
	for (int i = 0; i < 2; i++)
		examScore[i] = 0;
	finalProject = 0;
}

bool Student::AcquireData(istream& in)
{
	in >> firstName;
	if (in.fail())
		return false;

	in >> lastName;
	if (in.fail())
		return false;

	for (int i = 0; i < 4; i++) {
		in >> quizScore[i];
		if (in.fail())
			return false;
	}

	for (int i = 0; i < 2; i++) {
		in >> examScore[i];
		if (in.fail())
			return false;
	}

	in >> finalProject;
	if (in.fail())
		return false;

	return true;
}

bool Student::PrintData(ostream& out) const
{
	out << left << setw(20) << firstName;
	if (out.fail())
		return false;

	out << left << setw(20) << lastName;
	if (out.fail())
		return false;

	for (int i = 0; i < 4; i++) {
		out << right << setw(4) << quizScore[i];
		if (out.fail())
			return false;
	}

	for (int i = 0; i < 2; i++) {
		out << right << setw(5) << examScore[i];
		if (out.fail())
			return false;
	}

	out << right << setw(5) << finalProject;
	if (out.fail())
		return false;

	out << endl;

	return true;
}

string Student::GetFirstName() const
{
	return firstName;
}

string Student::GetLastName() const
{
	return lastName;
}

float Student::CourseAverage() const 
{
	float avgQuiz, avgExam, prj, sum = 0;

	for (int i = 0; i < 4; i++)
		sum += quizScore[i];
	avgQuiz = sum / 4;

	sum = 0;
	for (int i = 0; i < 2; i++)
		sum += examScore[i];
	avgExam = sum / 2;

	prj = finalProject;

	return ((avgQuiz * 35/10) + (avgExam * 35/100) + (prj * 30/100));
}

bool Student::DisplayCourseAverage(ostream& out) const
{
	out << fixed << setprecision(1);
	out << left << setw(20) << CourseAverage();
	if (out.fail())
		return false;
	return true;
}

string Student::LetterGrade() const
{
	float G = CourseAverage();
	if (G >= 93 && G <= 100) return "A";
	if (G >= 90) return "A-";
	if (G >= 87) return "B+";
	if (G >= 83) return "B";
	if (G >= 80) return "B-";
	if (G >= 77) return "C+";
	if (G >= 73) return "C";
	if (G >= 70) return "C-";
	if (G >= 67) return "D+";
	if (G >= 63) return "D";
	if (G >= 60) return "D-";
	return "F";
}