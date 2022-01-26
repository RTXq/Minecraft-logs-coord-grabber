#include <iostream>
#include "AddOne.h"
#include "GetDataFromFile.h"
#include "ConstructFileName.h"
#include "GetLocationOfCoordsInLines.h"
#include "Setup.h"
#include "DeleteFile.h"
#include "SortCoords.h"

using namespace std;


//aim is to extract coords from a file and sort them
int main() {
	//local vars
	DeleteFile("ProcessedCoords.txt");

	int dayNumber = 1;
	int logFileNumber;

	system("pause");
	
	//get coords from all log files
	while (dayNumber <= MAX_DAY_NUMBER) {
		//get coords from every log file in that day
		//reset the log file number
		logFileNumber = 1;
		while (logFileNumber <= MAX_LOG_FILE_NUMBER) {
			//get the name of the file
			string fileName = ConstructFileName(dayNumber, logFileNumber, ".log");
			//get the coords from the file
			GetDataFromFile(fileName, "ProcessedCoords.txt", LOCATION_OF_COORDS_IN_LINE);
			logFileNumber += 1;

		}
		dayNumber = AddOne(dayNumber);
	}
	//now sort them
	SortCoords("ProcessedCoords.txt");


	//all good!
	system("pause");
	return 0;
};