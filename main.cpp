#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Class.h"
using namespace std;

int main()
{
	ifstream fileIn;
	fileIn.open("Program4Data.txt");
	if (!fileIn.is_open())
	{
		cout << "Cannot open the file!" << endl;
		return 1;
	}
	
	vector<Student> vec;
	Student stu;

	string dummyLine;
	getline (fileIn, dummyLine);

	while (stu.AcquireData(fileIn))
	{
		vec.push_back(stu);
	}

	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[i].CourseAverage() < vec[j].CourseAverage() || 
				(vec[i].CourseAverage() == vec[j].CourseAverage() && 
					vec [i].GetFirstName() > vec[j].GetFirstName())) {
				swap(vec[i], vec[j]);
			}
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << left << setw(20) << vec[i].GetFirstName();
		cout << left << setw(20) << vec[i].GetLastName();
		vec[i].DisplayCourseAverage(cout);
		cout << vec[i].LetterGrade() << endl;
	}

	cout << endl << "More information can be found in Program4Data.txt file." << endl;
	fileIn.close();

	return 0;
}