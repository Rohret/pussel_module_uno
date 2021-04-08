#include <Arduino.h>
#include <FastLed.h>
#include "global.h"
#include "cables.h"
#include "lamps.h"

int data_in[] = {0, 0, 0, 0, 0, 0};
int change_io = 2; // PL
int clock = 3;
int data_out = 4;
int value;
long int colors[] = {RED, BLUE, WHITE, YELLOW, PURPLE, BLACK}; //red,blue,white,yellow,purple,black
long int cable_color[AMOUNT_OF_CABLES];

byte cables = 0; // byte array som innehåller vilken sladd som är av och inte

void setup()
{

  FastLED.addLeds<WS2812, rgb_in, RGB>(leds, NUM_LEDS);

  pinMode(change_io, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data_out, INPUT);
  randomSeed(analogRead(0));
  random_color();

  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < AMOUNT_OF_CABLES; i++)
  {
    if (cable_color[i] == BLACK)
    {
      //Serial.print("Lampan är avstängd på position: ");
      //Serial.println(i);
    }
  }

  for (int j = 0; j < AMOUNT_OF_CABLES; j++)
  {
    // Serial.println(cable_color[j]);
    /*if (cable_color[j] == WHITE)
    {
      Serial.println("WHITE");
    }
    else if (cable_color[j] == RED)
    {
      Serial.println("RED");
    }
    else if (cable_color[j] == YELLOW)
    {
      Serial.println("YELLOW");
    }
    else if (cable_color[j] == BLUE)
    {
      Serial.println("BLUE");
    }
    else if (cable_color[j] == PURPLE)
    {
      Serial.println("PURPLE");
    }*/
  }

  digitalWrite(change_io, 0); //enablar parrallel input
  digitalWrite(clock, 0);
  digitalWrite(clock, 1);     //För att få data från alla inputs i shift registret
  digitalWrite(change_io, 1); //disablar parrallell input för att enable serial output

  cables_cut();
  cables_connected_lamp();
  delay(5000);
}