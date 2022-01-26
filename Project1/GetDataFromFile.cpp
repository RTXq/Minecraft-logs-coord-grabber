#include <string>
#include <fstream>
#include <iostream>
#include "CheckIfDataContainsCoords.h"
#include "Setup.h"

using namespace std;
//get the coords from the file


void GetDataFromFile(string dataFileName, string outputFileName, const int INDEX_OF_COORDS) {
	//vars
	int lineSize;
	bool lineContainsCoords;
	string readFileLine;
	string filteredReadFileLine = "";
	string timeOfCoords = "";
	//objects
	ifstream dataFile;
	ofstream outputFile;


	//open the file for reading
	dataFile.open(dataFileName, ios::in);
	//open the raw file for writing
	outputFile.open(outputFileName, ios::app);
	//read the entire file
	if (!dataFile.fail()) {
		//while its not at the end of the file
		while (!dataFile.eof()) {
			//get the line
			getline(dataFile, readFileLine);
			//get its size
			lineSize = (int)readFileLine.size();
			if (lineSize > INDEX_OF_COORDS) {
				//extract the coords from the line
				filteredReadFileLine = readFileLine.substr(INDEX_OF_COORDS);
				lineContainsCoords = CheckIfDataContainsCoords(filteredReadFileLine);
				//if it contains coords
				if (lineContainsCoords) {
					//get the time associated with the coords
					timeOfCoords = readFileLine.substr(0,TIME_LENGTH);
					//cout << filteredReadFileLine << endl;
					outputFile << timeOfCoords << " " << filteredReadFileLine << endl;
				}
			}
		}
		outputFile << "EOF";
	}
	//close both files after
	dataFile.close();
	outputFile.close();

	//state it was done
	cout << "Coords taken out of file: " << dataFileName << endl;

};