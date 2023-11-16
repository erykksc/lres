#include <FastLED.h>
#include "Screen.h"

// Implements DrawScreenFunc
void makeWaveThing(Screen &s)
{
    int middle_X = s.width / 2;
    int middle_Y = s.height / 2;

    for (int x = 0; x < s.width; x++)
    {
        for (int y = 0; y < s.height; y++)
        {
            float distance = sqrt(pow(x - middle_X, 2) + pow(y - middle_Y, 2));
            float max_distance = sqrt(pow(middle_X, 2) + pow(middle_Y, 2));

            int value = 255 - sin(distance / max_distance * PI / 2) * 255;
            // int value = distance / max_distance * 255.0f;
            s.set_unsafe(x, y, CRGB(value, value, value));
        }
    }
}

// implements DrawPixelFunc
CRGB randomColors(int x, int y, int width, int height)
{
    return CRGB(random8(), random8(), random8());
}
