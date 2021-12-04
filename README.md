# cpp_playGround

For this program you’ll be doing a simple class hierarchy and demonstrating inheritance and polymorphism. The hierarchy is deliberately being kept simple; in an actual application the classes would be developed in much more elaborate detail. (A program big enough to show how inheritance and polymorphism can dramatically speed up development would be too big to give as an assignment for this course.)

An online site allows users to upload various media files that they have created. All files are of the parent type Media. This is an abstract class, defining those things that are common to all media files:
•	A unique identifier assigned by us. In practice this would be based on the file title, upload type, account, size, and other data, all digitally mashed together to produce a unique name. For our purposes, this is a string.
•	The name associated with the account. This is a string, and may contain spaces.
•	A running time in seconds.
•	Getters and setters for each of those. Getters should not modify the objects’ data, and will be the same in all child types.
•	virtual string getType() const = 0;  This will be left undefined for the parent type (as an abstract type we’ll never encounter it). Each of the child types should return a string corresponding to its type, as specified below.
•	Methods to read and write the objects’ data, called ReadData(istream&) and WriteData(ostream&). These are virtual functions, as they are going to be slightly different in each of the child types. Go ahead and implement them for the abstract Media class; it will make writing the child methods easier. The format will be a little different than the last program. Some of the string data will have spaces within it, but be the only thing on the line in the file. Thus, you should use getline() to read this data. Mixing the >> operator with getline() when dealing with the same file can be done but requires some extra care, as the two handle the end of line marker differently. Thus most programs use either one or the other for a given file, not both. The ReadData() method assumes the data will be in the following format:
◦	The identifier, which will be the only thing on the line
◦	The name associated with the account, on the line immediately following, and also the only thing on the line.
◦	The running time in seconds, an integer >= 0. This will be the only thing on the line; you may want to use a stringstream to handle the conversion (getline() will read it as a string).
•	The WriteData() method sends data to the output stream, each item on a line by itself followed by a newline (‘\n’ or endl).

There are 2 child classes. (There’s obviously room for further expansion, but again, this is mostly a demonstration.) Both the child classes use public inheritance.

An Audio clip is a Media object containing sound data. In addition to what’s inherited from Media, an Audio item also has a format descriptor (a string) and a quality specification (also a string). The Audio class needs the following:
•	A constructor that takes parameters for ALL items, including what’s needed for Media, and a default constructor. (As usual, this can be done by providing default values for all parameters.)
◦	The constructor should call Media’s constructor, then take care of what it has that’s different from its parent.
•	The ReadData() method should call the parent’s version, then read the format specifier and quality description, both as strings, each using getline() as with other data.
•	Likewise, the WriteData() method should call the parent’s version, then write the format and quality, each on a line by itself, as with other data.
•	The getType() method should return a string: “Audio”

A Video clip is a Media object containing video data as well as sound data. In addition to what’s inherited from Media, a Video item also has a resolution (string), format descriptor (a string) and a quality specification (also a string). The Video class needs the following:
•	A constructor that takes parameters for ALL items, including what’s needed for Media, and a default constructor. (As usual, this can be done by providing default values for all parameters.)
◦	The constructor should call Media’s constructor, then take care of what it has that’s different from its parent.
•	The ReadData() method should call the parent’s version, then read its own data, in the order specified, each using getline() as with other data.
•	Likewise, the WriteData() method should call the parent’s version, then write its own data, one item per line, as with other data.
•	The getType() method should return a string: “Video”

We won’t be deriving further classes from these, but leave all virtual functions virtual. We design class hierarchies with an eye toward future expansion or adaptation, so want to make them easy to extend.

The main program is very simple—pretty much data in, data out. You are given an input file with a collection of media objects. Each item is preceded by a 1-character flag, on a line by itself, indicating what the next item is-- ‘V’ for video, ‘A’ for Audio. This is then followed by the data for that item, in the correct format for that type. Your program should have an array of 200 pointers to Media. You may assume there is at least one item in the data file, and no more than 200. You should not make any assumptions about the distribution of how many of each type there are, or how they’re arranged.

Read through the data file. After reading the flag character indicating what the next item is, instantiate the next Media pointer as the correct child type for the next item, and then call ReadData() on the object just created. Do this until all items have been read and are in the array.

Your output will be two files—one of all the Video objects, the other of all the Audio objects. Do not try to sort or rearrange the pointers themselves—iterate through the list of pointers and select the appropriate type for each file. Put a one-line separator of some kind (a row of ****, or a line, or whatever you want, just something to make it clear where one item ends and the next begins).  Your program will be tested using a different data file with the same format.
