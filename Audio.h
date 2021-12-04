#pragma once
#include "Media.h"
using namespace std;

class Audio : public Media {
private:
	string formatDescriptor;
	string qualitySpec;
	string type;

public:
	Audio();
	Audio(string uniqueID, string name, int runningTime, 
		string formatDescriptor, string qualitySpec);
	~Audio();
	bool ReadData(istream& in);
	bool WriteData(ostream& out);
	string getType() const;
};

