#include <iostream>
#include "Setup.h"

using namespace std;

bool CheckIfSimilar(int number1, int number2, int maxDifference, string mode) {
	int biggerNumber;
	int smallerNumber;
	//make both numbers +
	if (number1 < 0) number1 *= -1;
	if (number2 < 0) number2 *= -1;
	
	if (number1 > number2) {
		biggerNumber = number1;
		smallerNumber = number2;
	}
	else {
		biggerNumber = number2;
		smallerNumber = number1;
	}

	//if its lower than the max percentage difference then is similar
	if (mode == "percentage") {
		float percentageDifference = 0.0f;
		percentageDifference = (((float)biggerNumber / (float)smallerNumber) - 1) * 100;
		//cout << "Percentage difference: " << endl;

		//if its between the bound set its similar
		if (percentageDifference <= maxDifference) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (mode == "flat") {
		//get the difference between them
		int flatDifference = 0;
		flatDifference = biggerNumber - smallerNumber;

		//if its within the max difference then its similar
		if (flatDifference <= maxDifference) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		cout << "Invalid mode" << endl;
		return false;
	}
}

bool CheckIfSimilarCoords(int coord_X, int coord_Z, int similarCoord_X, int similarCoord_Z, int currentNumberOfChunksInArea) {
	bool similarX;
	bool similarZ;

	if ((coord_X * MAX_DECIMAL_DIFFERENCE) < MIN_DIFFERENCE) {
		similarX = CheckIfSimilar(coord_X, similarCoord_X, MIN_DIFFERENCE + currentNumberOfChunksInArea/200, "flat");
	}
	else {
		similarX = CheckIfSimilar(coord_X, similarCoord_X, MAX_PERCENTAGE_DIFFERENCE + currentNumberOfChunksInArea / 200, "percentage");
	}
	if ((coord_Z * MAX_DECIMAL_DIFFERENCE) < MIN_DIFFERENCE) {
		similarZ = CheckIfSimilar(coord_Z, similarCoord_Z, MIN_DIFFERENCE + currentNumberOfChunksInArea / 200, "flat");
	}
	else {
		similarZ = CheckIfSimilar(coord_Z, similarCoord_Z, MAX_PERCENTAGE_DIFFERENCE + currentNumberOfChunksInArea / 200, "percentage");
	}
	//return if they are similar or not
	return(similarX && similarZ);

}