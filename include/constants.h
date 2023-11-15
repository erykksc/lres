#ifndef CONSTANTS_H
#define CONSTANTS_H

// How many leds in your strip?
#define NUM_LEDS 256

#define BOARD_DATA_PIN 12

// value in range 0-255
// each led has three lights, each takes max 20mA so all 3 together take 60mA
// approximation 1 led = 60mA
#define BRIGHTNESS 50

#define MATRIX_WIDTH 16
#define MATRIX_HEIGHT 18

#endif // CONSTANTS_H