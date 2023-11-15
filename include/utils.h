#ifndef UTILS_H
#define UTILS_H

#include <FastLED.h>
#include "constants.h"

// Retrieve the x,y coordinates of a pixel in a 2D array, and -1 if it's out of bounds
int XY(int x, int y);

// Get a random color
CRGB getRandomColor();

#endif // UTILS_H