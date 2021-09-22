/* Write a program that reads the student information from a tab separated values (tsv) file. 
The program then creates a text file that records the course grades of the students. 
Each row of the tsv file contains the Last Name, First Name, Midterm1 score, Midterm2 score, and the Final score of a student.
A sample of the student information is provided in StudentInfo.tsv. Assume the number of students is at least 1 and at most 20.

The program performs the following tasks:

Read the file name of the tsv file from the user.
Open the tsv file and read the student information.
Compute the average exam score of each student.
Assign a letter grade to each student based on the average exam score in the following scale:
A: 90 =< x
B: 80 =< x < 90
C: 70 =< x < 80
D: 60 =< x < 70
F: x < 60
Compute the average of each exam.
Output the last names, first names, exam scores, and letter grades of the students into a text file named report.txt. 
Output one student per row and separate the values with a tab character.
Output the average of each exam, with two digits after the decimal point, at the end of report.txt. */


#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
 
int main(){
 
        /*Declare any necessary variables here.*/
        string lastName, firstName;
        int score1, score2, finalScore;
        ifstream inFile;
        ofstream outFile;
        int midTerm1Total = 0; 
        int midTerm2Total = 0; 
        int finalScoreTotal = 0;
        int count = 0;
        string filename;
        /*Read a file name from the user and read the tsv file here.*/
        cin>> filename;
        inFile.open(filename);
 
        //opening report.txt in write mode
        outFile.open("report.txt");
 
        while( inFile>> lastName >> firstName >> score1 >> score2 >> finalScore)
        {
                midTerm1Total += score1;
                midTerm2Total += score2;
                finalScoreTotal += finalScore;
                count++;
 
                /*Compute student grades and averages, then output results to a text file here.*/
                double averageScore = (double)(score1 + score2 + finalScore)/3;
                char grade;
 
                if(averageScore >= 90) 
                        grade = 'A';
                else if(averageScore >= 80) 
                        grade = 'B';
                else if(averageScore >= 70) 
                        grade = 'C';
                else if(averageScore >= 60) 
                        grade = 'D';
                else 
                        grade = 'F';
 
                outFile<< lastName << '\t' << firstName << '\t' << score1 << '\t' << score2 
                           << '\t' << finalScore << '\t' << grade << endl;                           
        }
 
        double averageMidTerm1 = (double) midTerm1Total/count; 
        double averageMidTerm2 = (double) midTerm2Total/count; 
        double averageFinalScore = (double) finalScoreTotal/count;
 
        outFile << "\nAverages: midterm1 " 
                        << fixed << setprecision(2) << averageMidTerm1
                        << ", midterm2 "
                        << fixed << setprecision(2) << averageMidTerm2
                        << ", final "
                        << fixed << setprecision(2) << averageFinalScore << endl;
 
 
        //closing both files
        inFile.close();
        outFile.close();                
        return 0;
}
