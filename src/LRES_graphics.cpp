#include "LRES_graphics.h"

Screen::Screen() {
    FastLED.addLeds<WS2812B, BOARD_DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalSMD5050); // GRB ordering is typical
    FastLED.setBrightness(BRIGHTNESS);
}

void Screen::draw(int x, int y, CRGB c) {
    int index = XY(x, y);
    if (index != -1) leds[index];
}

void Screen::clear(unsigned int r, unsigned int g, unsigned int b) {
    for (int i = 0; i < NUM_LEDS; i++)
        leds[i] = CRGB(r, g, b);
}
void Screen::render() {
    FastLED.show();
}

void drawLine(Screen* screen, int x0, int y0, int x1, int y1, CRGB color)
{
    bool is_vertical = (x1 == x2);
    
    if (x2 < x1) {
        float tmp = x0;
        x0 = x1;
        x1 = tmp;
        float tmp = y0;
        y0 = y1;
        y1 = tmp;
    }

    if (x2 < x1) {
        float tmp = x0;
        x0 = x1;
        x1 = tmp;
        float tmp = y0;
        y0 = y1;
        y1 = tmp;
    }

    if (is_vertical) {
        for (y = y0; y < y1+1; y++)
            screen->draw(x0, y, color);
    } else {
        float slope = (y1 - y0) / (x1 - x0);
        float y = y0;
        for (int x = x0; x < x1+1; x++) {
            screen->draw(x, y, color);
            y += slope
        }
    }
}
