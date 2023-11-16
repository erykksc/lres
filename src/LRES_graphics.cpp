#include "Screen.h"

#include <iostream>
#include <cmath>

void drawLine(Screen &screen, int x1, int y1, int x2, int y2, CRGB color)
{
    bool isVertical = false;
    if (x1 == x2)
    {
        isVertical = true;
    }

    if (x2 < x1)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    if (y2 < y1)
    {
        std::swap(y1, y2);
        std::swap(x1, x2);
    }

    if (isVertical)
    {
        for (int y = y1; y <= y2; ++y)
        {
            screen.set_unsafe(x1, y, color);
        }
    }
    else
    {
        float slope = static_cast<float>(y2 - y1) / (x2 - x1);
        int y = y1;
        for (int x = x1; x <= x2; ++x)
        {
            screen.set_unsafe(x, y, color);
            y += round(slope);
        }
    }
}
