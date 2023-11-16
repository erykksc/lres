#include "LRES_graphics.h"

#include <iostream>
#include <cmath>

Screen::Screen() {
    FastLED.addLeds<WS2812B, BOARD_DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
    FastLED.setBrightness(BRIGHTNESS);
}

void Screen::draw(int x, int y, CRGB c) {
    int index = XY(x, y);
    if (index != -1) leds[index] = c;
}

void Screen::clear(unsigned int r, unsigned int g, unsigned int b) {
    for (int i = 0; i < NUM_LEDS; i++)
        leds[i] = CRGB(r, g, b);
}
void Screen::render() {
    FastLED.show();
}

void drawLine(Screen* screen, int x1, int y1, int x2, int y2, CRGB color)
{
    bool isVertical = false;
    if (x1 == x2) {
        isVertical = true;
    }
    
    if (x2 < x1) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    if (y2 < y1) {
        std::swap(y1, y2);
        std::swap(x1, x2);
    }

    if (isVertical) {
        for (int y = y1; y <= y2; ++y) {
            screen->draw(x1, y, color);
        }
    } else {
        float slope = static_cast<float>(y2 - y1) / (x2 - x1);
        int y = y1;
        for (int x = x1; x <= x2; ++x) {
            screen->draw(x, y, color);
            y += round(slope);
        }
    }
}
