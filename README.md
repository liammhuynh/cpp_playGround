# cpp_playGround

For this program you’ll write a simple class and use it in a vector.

Start the program by writing a Student class whose public section has the following methods:

Student::Student()
Constructor. Initializes all data elements: name to empty string(s), numeric variables to 0.

bool Student::AcquireData(istream& in)
Data input. The istream should already be open. Reads the following data, in this order:
• First name (a string, 1 word)
• Last name (also a string, also 1 word)
• 4 quiz scores (float, range 0-10)
• 2 exam scores (float, range 0-100)
• 1 Final Project (float, range 0-100)

Assumes that all data is separated by whitespace. The method returns true if reading all data was
successful, otherwise returns false. Does not need to validate or range-check data; if one of the quiz or
exam scores is out of range, just keep going.

bool Student::PrintData(ostream& out) const
Output function. Writes data in the following format. Each student’s data is on one line.
• First name (left justified, 20 characters)
• Last name (left justified, 20 characters)
• 4 quiz scores (each right justified in a field 4 characters wide)
• 2 exam scores (each right justified in a field 5 characters wide)
• 1 Final Project score (right justified in a field 5 characters wide)
• new-line character ‘\n’ or use of endl in output function
Note that this is a const method; it should not modify any of the object’s data. Returns true if the
attempt to send the data to the stream was successful, false otherwise.

string Student::GetFirstName() const;
string Student::GetLastName() const;
Accessor methods, also known as ‘getters.’ Returns data from inside the function.

float Student::CourseAverage() const
Returns the student’s weighted average as a percentage (float in range 0-100). The quiz scores are
averaged together (10-point scale) and are 35% of the course grade. The exams are averaged together
and are 35% of the course grade. The Final Project is worth 30% of the grade. This does not modify
any of the object’s data.

bool Student::DisplayCourseAverage(ostream& out) const
Prints the student’s course average to the provided output stream, rounded to 1 decimal places. Returns
true if the attempt was successful, false otherwise.

string Student::LetterGrade() const
Returns a string with the student’s letter grade, using the same grading scale as this course.

The class should assume that any input or output streams passed to public methods are already open.

The main program is quite simple. You are provided a data file with data for some number of students.
Read the data into a vector. (Hint: Declare one student. Read that student’s data, then add it to the
vector. Repeat.) It should then print a roster, showing the name, course average to 1 decimal places, and
letter grade for each student in the course. This list should be sorted by course average from highest
to lowest. (break ties using first name)
