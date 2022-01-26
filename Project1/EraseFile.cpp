#include <iostream>
#include <fstream>

using namespace std;

//erase the file specified
void DeleteFile(string fileName) {
	//objects
	ofstream file;

	//open, erase, close
	file.open(fileName, ios::trunc);
	file.close();

}