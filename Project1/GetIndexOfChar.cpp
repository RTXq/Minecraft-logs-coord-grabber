#include <iostream>

using namespace std;

//data to search, character to find, starting position to search from - returns -1 if nothing found
int GetIndexOfChar(string data, char character, const int startIndex) {
	//constants
	const int MAX_INDEX = data.size() - 1;
	//vars
	int index = startIndex;
	//until a comma is found or the end of the string is found
	while (data[index] != ',') {
		index += 1;
		if (index > MAX_INDEX) {
			//reached the end of the string, invalid
			return -1;
		}
	}

	return index;


}