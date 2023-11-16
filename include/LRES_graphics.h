#ifndef LRES_GRAPHICS
#define LRES_GRAPHICS

#include <FastLED.h>
#include "constants.h"
#include "utils.h"

class Screen 
{
    CRGB leds[NUM_LEDS];

public:
    Screen();
    void draw(int x, int y, CRGB c);
    void clear(unsigned int r, unsigned int g, unsigned int b);
    void render();
};

// Primitives
void drawLine(Screen* screen, int x1, int y1, int x2, int y2, CRGB color);

#endif
