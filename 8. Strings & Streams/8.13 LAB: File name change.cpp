/* A photographer is organizing a photo collection about the national parks in the US and would like to annotate the information 
about each of the photos into a separate set of files. 
Write a program that reads the name of a text file containing a list of photo file names. 
The program then reads the photo file names from the text file, replaces the "_photo.jpg" portion of the file names with "_info.txt", 
and outputs the modified file names.
Assume the unchanged portion of the photo file names contains only letters and numbers, 
and the text file stores one photo file name per line. If the text file is empty, the program produces no output. */



#include<iostream>

#include<fstream>

#include<cstring>

using namespace std;

int main() {

string str;

char fileName[50], tempFile[] = "temp.txt";

// Getting user file name

cin >> fileName;

// Opening user file for reading

ifstream file(fileName);

// Opening temp file for writing

ofstream file1(tempFile);


  
// Reading line by line from user's file

while(getline (file, str)) {

// split the name by "_"

// get only the prefix of name

string name = str.substr(0, str.find("_"));

// concat the suffix with name's prefix

name = name + "_info.txt";

// write the resultant name into temp file

file1 << name << endl;

// Print the modified name

cout << name << endl;

}

  
// Removing the user's file

remove(fileName);

// Renaming the temp file as user's file

rename(tempFile, fileName);


// Closing the user's file (i.e. temp file)

file1.close();
  
return 0;

}
