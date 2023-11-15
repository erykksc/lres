#ifndef LRES_GRAPHICS
#define LRES_GRAPHICS

#include <FastLED.h>
#include "constants.h"
#include "utils.h"

class Screen 
{
    CRGB leds[NUM_LEDS];

public:
    void draw(int x, int y, CRGB c);
    void clear(unsigned int r, unsigned int g, unsigned int b)
    void render();
};

// Primitives
void drawLine(Screen* screen, int x0, int y0, int x1, int y1, CRGB color);

#endif
