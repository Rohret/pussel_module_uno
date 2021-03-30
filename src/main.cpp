#include <Arduino.h>
#include <FastLed.h>

#define NUM_LEDS 6
#define rgb_in 9
#define RED 0xFF0000
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define YELLOW 0xFFFF00
#define PURPLE 0x800080
#define BLACK 0x000000
#define AMOUNT_OF_CABLES 6

int data_in[] = {0, 0, 0, 0, 0, 0};
int change_io = 2; // PL
int clock = 3;
int data_out = 4;
int j;
int value;
long int colors[] = {RED, BLUE, WHITE, YELLOW, PURPLE, BLACK}; //red,blue,white,yellow,purple,black
long int cable_color[AMOUNT_OF_CABLES];

CRGB leds[NUM_LEDS];

byte cables = 0; // byte array som innehåller vilken sladd som är av och inte

void random_color()
{
  for (int i = 0; i < AMOUNT_OF_CABLES; i++)
  {
    cable_color[i] = colors[random(0, AMOUNT_OF_CABLES)];
  }
}

void cables_cut()
{
  //byte data_in = 0;

  for (j = 0; j < AMOUNT_OF_CABLES; j++)
  {
    value = digitalRead(data_out);
    Serial.print(" Sladd på position: ");
    Serial.print(j);
    Serial.print(" avklippt: ");
    Serial.print(value);
    Serial.println(" ");
    if (value)
    {
      data_in[j] = 1;
    }
    else
    {
      data_in[j] = 0;
    }

    digitalWrite(clock, LOW);
    digitalWrite(clock, HIGH);
  }

  Serial.print(" Vilka sladdar som klipptes:");

  for (int k = 0; k < AMOUNT_OF_CABLES; k++)
  {
    Serial.print(data_in[k]);
    Serial.print(", ");
  }
  Serial.println(" ");
}

void cables_connected_lamp()
{

  for (int i = 0; i < AMOUNT_OF_CABLES; i++)
  {

    if (data_in[i] == 1)
    {
      leds[i] = BLACK;
    }
    else
    {
      leds[i] = cable_color[i];
      FastLED.show();
    }
  }
}

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
      Serial.print("Lampan är avstängd på position: ");
      Serial.println(i);
    }
  }

  for (int j = 0; j < AMOUNT_OF_CABLES; j++)
  {
    Serial.println(cable_color[j]);
  }

  digitalWrite(change_io, 0); //enablar parrallel input
  digitalWrite(clock, 0);
  digitalWrite(clock, 1);     //För att få data från alla inputs i shift registret
  digitalWrite(change_io, 1); //disablar parrallell input för att enable serial output

  cables_cut();
  cables_connected_lamp();
  delay(5000);
}