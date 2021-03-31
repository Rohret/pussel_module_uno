#include <Arduino.h>
#include <FastLed.h>

#ifndef GLOBAL_H
#define GLOBAL_H
#define NUM_LEDS 6
#define rgb_in 9
#define RED 0xFF0000
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define YELLOW 0xFFFF00
#define PURPLE 0x800080
#define BLACK 0x000000
#define AMOUNT_OF_CABLES 6

extern int data_in[AMOUNT_OF_CABLES];
extern int change_io;
extern int clock;
extern int data_out;
extern int value;
extern long int colors[AMOUNT_OF_CABLES];
extern long int cable_color[AMOUNT_OF_CABLES];
extern CRGB leds[NUM_LEDS];

extern byte cables; // byte array som innehåller vilken sladd som är av och inte
#endif