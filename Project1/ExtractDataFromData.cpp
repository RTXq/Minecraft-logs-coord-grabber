#include <iostream>
#include <fstream>
#include <string>
#include "Setup.h"
#include "GetIndexOfChar.h"
#include "ConvertStringToInt.h"

using namespace std;


//extract both the x and y coord from the string
string ExtractTime(string data) {
	return data.substr(0, TIME_LENGTH);
}

int ExtractCoord_X(string data) {
	//vars
	const int START_INDEX = TIME_LENGTH + 1; //where the first digit/the minus sign is of the x coord
	int endIndex;
	string coord_X;

	//find where the comma is
	endIndex = GetIndexOfChar(data, ',', START_INDEX);
	//now return the string between the start and the endIndex
	if (endIndex != -1) {
		coord_X = data.substr(START_INDEX, endIndex);
	}
	return ConvertStringToInt(coord_X);
}

int ExtractCoord_Z(string data) {
	//vars
	const int START_INDEX = TIME_LENGTH + 1; //where the first digit/the minus sign is of the x coord
	int zCoordStartIndex;
	string coord_Z;

	//find where the comma is
	zCoordStartIndex = GetIndexOfChar(data, ',', START_INDEX);
	//add two because of the space
	zCoordStartIndex += 2;
	//now return the string between the start and the endIndex
	if (zCoordStartIndex != -1) {
		coord_Z = data.substr(zCoordStartIndex, data.size() - 1);
	}
	return ConvertStringToInt(coord_Z);
}
