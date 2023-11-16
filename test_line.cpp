#include <FastLED.h>
#include "LRES_graphics.h"

void setup()
{
  Serial.begin(9600);
  
  Serial.println("Building Screen...");
  Screen screen();
  Serial.println("Done.");
}

void loop()
{
  while (1)
  {
    screen.clear(0, 0, 0);
    drawLine(&screen, 0, 0, 15, 15, CRGB(255, 255, 255));
    screen.render();
    delay(100);
  }
}
