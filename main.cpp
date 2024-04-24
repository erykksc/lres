#include <FastLED.h>
#include "Screen.h"
#include "3D.h"
#include "effects.h"

Screen screen;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing Screen...");
  screen.init();
  Serial.println("Done.");
}

void loop()
{
  Serial.println("Entering loop...");

  Serial.println("Building Cube...");
  Cube cube = Cube(6);
  Serial.println("Done.");

  // One can draw a function that takes in Screen
  screen.draw(makeWaveThing);
  delay(1500);

  // One can draw a function that takes in x, y, width, height
  // There are draw_and_show functions for all the draw functions to make it easier to use
  screen.draw_and_show(randomColors);
  delay(1500);

  while (1)
  {
    screen.clear();
    cube.rotateX(.1);
    cube.rotateY(.1);
    cube.rotateZ(.1);

    // One can draw a Renderer Object
    screen.draw(cube);
    screen.show();
    delay(100);
  }
}
