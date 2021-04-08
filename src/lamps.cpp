#include <Arduino.h>
#include <FastLed.h>
#include "global.h"
#include "lamps.h"
#include "bomb_manual.h"

CRGB leds[NUM_LEDS];
// FÅR INTE VARA MER ÄN 3 SLADDOR SOM ÄR AVSTÄNGDA
void random_color()
{
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        cable_color[i] = colors[random(0, AMOUNT_OF_CABLES)];
    }
}

void cables_connected_lamp()
{
    int counter = 0;

    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {

        if (data_in[i] == 1)
        {

            for (int j = 0; j < AMOUNT_OF_CABLES; j++)
            {
                if (cable_color[j] != BLACK)
                {
                    counter++;
                }
            }

            if (counter == 3)
            {

                three_cables();
            }
            else if (counter == 4)
            {
                four_cables();
            }
            else if (counter == 5)
            {
                five_cables();
            }
            else if (counter == 6)
            {
                six_cables();
            }

            leds[i] = BLACK;
        }
        else
        {
            leds[i] = cable_color[i];

            FastLED.show();
        }
    }
}