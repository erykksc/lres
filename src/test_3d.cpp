#include <FastLED.h>
#include "LRES_graphics.h"
#include "3D.h"

void setup()
{
  Serial.begin(9600);
  
  Serial.println("Building Screen...");
  Screen screen();
  Serial.println("Done.");

  Serial.println("Building Cube...");
  Cube cube(12);
  Serial.println("Done.");
}

void loop()
{
  while (1)
  {
    screen.clear(0, 0, 0);
    cube.rotateX(.1);
    cube.rotateY(.1);
    cube.rotateZ(.1);
    cube.draw(&screen, 7.5, 7.5, CRGB(0, 0, 255));
    screen.render();
    delay(100);
  }
}