#include <fstream>

using namespace std;
int GetLocationOfCoordsInLines() {
	//vars
	int colonCount = 0;
	char character;
	int index = 0;
	//objects
	ifstream calibratorFile;
	//open the file
	calibratorFile.open("Calibrator.txt", ios::in);

	//get the column number
	while (colonCount < 4) {
		//read each char
		character = calibratorFile.get();
		//if its a semi-colon +1 to the count
		if (character == ':') {
			colonCount += 1;
		}
		index += 1;
	}
	//take account of the empty space after which is before the coords
	index += 1;

	//close it at the end
	calibratorFile.close();

	return index;
}