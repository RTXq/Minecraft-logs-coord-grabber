#include <iostream>
#include "ConvertCharToInt.h"
#include "AddOne.h"

using namespace std;

const int MIN_VALID_MAX_DATA_INDEX = 3; //one for x coord, one for comma, one for a space, one for y coord

bool CheckIfDataContainsCoords(string data) {
	int dataIndex = 1;
	const int MAX_DATA_INDEX = data.size() - 1;
	bool commaFound = false;

	//all coord sets should be atleast 4 chars long
	if (MAX_DATA_INDEX < MIN_VALID_MAX_DATA_INDEX) {
		return false;
	}
	//cout << "Is 4+ chars long" << endl;

	//coords should begin with either a negative and a number or a number
	if (ConvertCharToInt(data[0]) == -1 && (ConvertCharToInt(data[1]) == -1 || data[0] != '-')) {
		return false;
	}
	//cout << "Beginning of first co-ord is valid" << endl;


	//should find a comma at some point
	while (dataIndex < MAX_DATA_INDEX) {
		//if its not a comma or a number its invalid
		if (data[dataIndex] != ',') {
			if (ConvertCharToInt(data[dataIndex]) == -1) {
				return false;
			}
		}
		else { //comma found
			commaFound = true;
			break;
		}
		dataIndex = AddOne(dataIndex);
	}
	//if no comma was found its invalid
	if (commaFound == false) return false;

	//cout << "Found comma!" << endl;

	//the next data index should be a space
	dataIndex = AddOne(dataIndex);
	if (data[dataIndex] != ' ') return false;
	//cout << "Found Space!" << endl;

	dataIndex = AddOne(dataIndex);
	//cout << data[dataIndex] << data[AddOne(dataIndex)] << endl;
	//second coord should begin with either a negative and a number or a number
	if (ConvertCharToInt(data[dataIndex]) == -1 && (ConvertCharToInt(data[AddOne(dataIndex)]) == -1 || data[dataIndex] != '-')) {
		return false;
	}
	//cout << "beginning of second coord is valid!" << endl;

	dataIndex = AddOne(dataIndex);

	//the rest of the string should be numbers
	while (dataIndex <= MAX_DATA_INDEX) {
		//if its not a comma or a number its invalid
		if (ConvertCharToInt(data[dataIndex]) == -1) {
			return false;
		}
		//cout << "Index " << dataIndex << " is a number" << endl;
		dataIndex = AddOne(dataIndex);
	}
	//cout << data << " contains coords" << endl;
	return true;

}