#ifndef Setup_H
#define Setup_H

#include "GetLocationOfCoordsInLines.h"

//global constants
const int BLOCKS_PER_CHUNK = 16;
const int MAX_LOG_FILE_NUMBER = 10;
const int MAX_DAY_NUMBER = 15;
const int ARRAY_SIZE = 100;
const int LOCATION_OF_COORDS_IN_LINE = GetLocationOfCoordsInLines();
const int TIME_LENGTH = 10;
const int MAX_PERCENTAGE_DIFFERENCE = 2;
const int MAX_DECIMAL_DIFFERENCE = MAX_PERCENTAGE_DIFFERENCE / 100;
const int MIN_DIFFERENCE = 15;

#endif
