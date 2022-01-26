#include <iostream>
#include "ConvertCharToInt.h"
#include "AddOne.h"
using namespace std;

//convert strings to int
int ConvertStringToInt(string string) {
	//vars
	int index = 0;
	int integer = 0;
	int maxIndex = string.length() - 1;
	int digit;
	bool isNegative = (string[0] == '-');

	//if negative, start at index 1
	if (isNegative) index = 1;

	//convert all indexes of the string into chars to be turned into ints
	while (index <= maxIndex) {
		//convert the char into an int
		digit = ConvertCharToInt(string[index]);
		if (digit != -1) { //add it to the complete integer if its not -1 (suggesting failure to convert)
			//x10 to add next number
			integer *= 10;
			//add it to the complete integer
			integer += digit;
		}
		else {
			break;
		}
		//add one to the index
		index = AddOne(index);
	}

	//if it was negative, make it negative now
	if (isNegative) integer *= -1;

	return integer;
}
