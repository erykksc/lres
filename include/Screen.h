#ifndef MY_SCREEN_H
#define MY_SCREEN_H

// Declare class so that all includes can use it
class Screen;

#include <FastLED.h>
#include "Renderer.h"

// How many leds in your strip?
#define NUM_LEDS 256

#define BOARD_DATA_PIN 12

// value in range 0-255
// each led has three lights, each takes max 20mA so all 3 together take 60mA
// approximation 1 led = 60mA
#define BRIGHTNESS 50

#define SCREEN_WIDTH 16
#define SCREEN_HEIGHT 18

// A function that takes in x, y, width, height and returns a CRGB
typedef CRGB (*DrawPixelFunc)(int, int, int, int);

// A function that draws directly on a 1D CRGB matrix, width, height and draws something
typedef void (*DrawMatrixFunc)(CRGB *, int, int);

// A function that takes in a Screen and draws something on it
typedef void (*DrawScreenFunc)(Screen &);

class Screen
{
    CRGB leds[NUM_LEDS];

private:
    int XY_unsafe(int x, int y)
    {
        if (y % 2 == 0)
        {
            return y * SCREEN_WIDTH + x;
        }
        else
        {
            return (y + 1) * SCREEN_WIDTH - x - 1;
        }
    }

    int XY(int x, int y)
    {
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
            return -1;

        XY_unsafe(x, y);
    }

public:
    // Other functions should use these constants
    const int width = SCREEN_WIDTH;
    const int height = SCREEN_HEIGHT;
    const int size = NUM_LEDS;

    void init()
    {
        FastLED.addLeds<WS2812B, BOARD_DATA_PIN, GRB>(leds, NUM_LEDS);
        FastLED.setBrightness(BRIGHTNESS);
    }
    // Set the brightness of the pixels
    // value in range 0-255
    void setBrightness(uint8_t scale)
    {
        FastLED.setBrightness(scale);
    }

    // return -1 if out of bounds, else return index
    int set(int x, int y, CRGB c)
    {
        int idx = XY(x, y);
        if (idx == -1)
            return -1;

        leds[idx] = c;
        return idx;
    }

    // Sets the pixel at x, y to the given color without checking bounds
    // returns index
    int set_unsafe(int x, int y, CRGB c)
    {
        int idx = XY_unsafe(x, y);
        leds[idx] = c;
        return idx;
    }

    // Copies the array of CRGBs to the leds array
    // The array must be of size NUM_LEDS or Screen.size()
    void set_unsafe(CRGB *c)
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            leds[i] = c[i];
        }
    }

    // Display changes to the leds
    void show()
    {
        FastLED.show();
    }

    // Clear the entire screen
    void clear()
    {
        fill(CRGB::Black);
    }

    // Fill the entire screen with the given color
    void fill(CRGB c)
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            leds[i] = c;
        }
    }

    // Takes a function that return CRGB based on x, y and draws every pixel on screen using it
    void draw(DrawPixelFunc func)
    {
        for (int y = 0; y < SCREEN_HEIGHT; y++)
            for (int x = 0; x < SCREEN_WIDTH; x++)
                leds[XY_unsafe(x, y)] = func(x, y, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    void draw_and_show(DrawPixelFunc func)
    {
        draw(func);
        show();
    }

    // Takes a function that draws on a 1D CRGB matrix
    void draw(DrawMatrixFunc func)
    {
        func(leds, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    void draw_and_show(DrawMatrixFunc func)
    {
        draw(func);
        show();
    }

    // Takes a function that draws on Screen
    void draw(DrawScreenFunc func)
    {
        func(*this);
    }

    void draw_and_show(DrawScreenFunc func)
    {
        draw(func);
        show();
    }

    void draw(Renderer &renderer)
    {
        renderer.render(*this);
    }

    void draw_and_show(Renderer &renderer)
    {
        draw(renderer);
        show();
    }
};

#endif