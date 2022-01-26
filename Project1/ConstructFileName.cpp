//construct the files name to be opened
#include <iostream>
#include "ConvertIntToString.h"
#include "AddZeroBefore.h"
using namespace std;

const string NAME_START = "2022-01-";

string ConstructFileName(int day, int logNumber, string fileType) {
	//convert day and logNumber to strings
	string stringDay = ConvertIntToString(day);
	string stringLogNumber = ConvertIntToString(logNumber);
	//add a 0 to day number if its below 10
	if (day < 10) stringDay = AddZeroBefore(stringDay);

	//construct it and return
	return NAME_START + stringDay + "-" + stringLogNumber + fileType;

}