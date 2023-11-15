#include <FastLED.h>
#include <math.h>
#include "constants.h"
#include "utils.h"

void makeWaveThing(CRGB *leds, int num_leds)
{
    int middle_X = MATRIX_WIDTH / 2;
    int middle_Y = MATRIX_HEIGHT / 2;

    for (int x = 0; x < MATRIX_WIDTH; x++)
    {
        for (int y = 0; y < MATRIX_HEIGHT; y++)
        {
            float distance = sqrt(pow(x - middle_X, 2) + pow(y - middle_Y, 2));
            float max_distance = sqrt(pow(middle_X, 2) + pow(middle_Y, 2));

            int value = 255 - sin(distance / max_distance * PI / 2) * 255;
            // int value = distance / max_distance * 255.0f;
            leds[XY(x, y)] = CRGB(value, value, value);
        }
    }
}

void randomColors(CRGB *leds, int num_leds)
{
    for (int i = 0; i < num_leds; i++)
    {
        leds[i] = getRandomColor();
    }
}
