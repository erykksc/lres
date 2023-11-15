#include "constants.h"
#include <FastLED.h>

int XY(int x, int y)
{
    if (x >= 0 && x < MATRIX_WIDTH && y >= 0 && y < MATRIX_HEIGHT)
        return y * MATRIX_WIDTH + x;
    else
        return -1;
}

CRGB getRandomColor()
{
    return CRGB(random(0, 255), random(0, 255), random(0, 255));
}