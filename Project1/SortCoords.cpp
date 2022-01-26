#include <fstream>
#include <iostream>
#include <string>
#include "ExtractDataFromData.h"
#include "CheckIfSimilarCoords.h"
#include "Setup.h"
#include <vector>


using namespace std;

//this function will sort the coords into files
void SortCoords(string coordFileName) {
	//files
	ifstream coordFile;
	ofstream sortedFile;
	//vars
	string coordFileLine;
	const int LOCATION_LIST_SIZE = 25;
	int numberOfLocations = 0;
	int previousLocation = -1;
	string timeStamp;
	int coord_X = 0;
	int coord_Z = 0;
	bool similarityFound;
	vector<int> locationData;
	vector<vector<int>> locationsList; //x,z, number of nearby chunks 
	vector<string> fileNameList;
	//open the coord file
	coordFile.open(coordFileName, ios::in);

	//for every line in the file
	while (true) {
		//get the line
		//cout << "Getting line" << endl;
		getline(coordFile, coordFileLine);
		//cout << coordFileLine << endl;
		//if its not EOF, get the x & z coord of the line
		if (coordFileLine != "EOF") {
			//get the coords
			//cout << "Extracting coords" << endl;
			coord_X = ExtractCoord_X(coordFileLine);
			coord_Z = ExtractCoord_Z(coordFileLine);
			timeStamp = ExtractTime(coordFileLine);
			//cout << "X Chunk coord: " << coord_X << endl;
			//cout << "Z Chunk coord: " << coord_Z << endl;
			//get the time associated with the coord
			//cout << "Time: " << ExtractTime(coordFileLine) << endl;
			//now check if it is similar to an already descovered set of coords
			similarityFound = false;
			if (previousLocation != -1) {
				//they often come in blocks of similar coords
				similarityFound = CheckIfSimilarCoords(coord_X, coord_Z, locationsList[previousLocation][0], locationsList[previousLocation][1], locationsList[previousLocation][2]);
				if (similarityFound) {
					locationsList[previousLocation][2] += 1;

				}
			}
			if (!similarityFound) {
				for (int i = numberOfLocations - 1; i >= 0; i--) {
					similarityFound = CheckIfSimilarCoords(coord_X, coord_Z, locationsList[i][0], locationsList[i][1], locationsList[i][2]);
					if (similarityFound) {
						previousLocation = i;
						locationsList[previousLocation][2] += 1;
						break;
					}
				}
			}
			//if no similarities were found, new location detected
			if (!similarityFound) {
				locationData.clear();
				locationData.push_back(coord_X);
				locationData.push_back(coord_Z);
				locationData.push_back(1);
				locationsList.push_back(locationData);
				//one more location added
				numberOfLocations += 1;
				cout << "Similarity not found, location number " << numberOfLocations << " detected!" << endl;
			}
		}
		else {//end of file reached, stop repeating
			break;
		}
	}
	//close it after
	coordFile.close();
	/*
	for (int i = 0; i < numberOfLocations; i++) {
		for (int j = 0; j < 3; j++) {
			cout << locationsList[i][j] << " ";
		}
		cout << endl;
	}
	*/



	//open a summary file
	sortedFile.open("summary.txt", ios::trunc);
	for (int i = 0; i < numberOfLocations; i++) {
		//put all the data in
		sortedFile << "Coords: " << locationsList[i][0] * BLOCKS_PER_CHUNK << " , " << locationsList[i][1] * BLOCKS_PER_CHUNK;
		sortedFile << "  # of nearby chunks: " << locationsList[i][2] << endl;
	}
	sortedFile << "EOF";
	sortedFile.close();
}