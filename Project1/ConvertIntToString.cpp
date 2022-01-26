#include <iostream>
using namespace std;

//initialise funcs
string ConvertIntToString(int integer);
string ConvertDigitToString(int digit);

string ConvertIntToString(int integer) {
	//vars
	int remainder;
	string remainderString;
	string completeString = "";

	do {
		//get the remainder and convert it to a string
		remainder = integer % 10;
		remainderString = ConvertDigitToString(remainder);
		//now attach the remainder string to the left of the full string
		completeString = remainderString + completeString;
		//now divide the int by 10
		integer /= 10;	

	} while (integer > 0); //until the most significant digit has been converted, which will result in integer becomming 0

	return completeString;
}

string ConvertDigitToString(int digit) {
	//convert the digit to a string
	switch (digit) {
	case 1: {
		return "1";
		break;
	}
	case 2: {
		return "2";
		break;
	}
	case 3: {
		return "3";
		break;
	}
	case 4: {
		return "4";
		break;
	}
	case 5: {
		return "5";
		break;
	}
	case 6: {
		return "6";
		break;
	}
	case 7: {
		return "7";
		break;
	}
	case 8: {
		return "8";
		break;
	}
	case 9: {
		return "9";
		break;
	}
	case 0: {
		return "0";
		break;
	}
	default: {
		return "-";
	}
	}
}