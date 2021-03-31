#include <Arduino.h>
#include "global.h"
#define threecables 3
#define second_cable 1
#define third_cable 2

// FÅR INTE VARA MER ÄN 3 SLADDOR SOM ÄR AVSTÄNGDA
void three_cables()
{
    int temp = 0;
    int counter = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] == RED)
        {
            break;
        }

        if (i == (AMOUNT_OF_CABLES - 1))
        {

            for (int j = 0; j < AMOUNT_OF_CABLES; j++)
            {

                if (cable_color[j] != BLACK)
                {

                    if (counter == second_cable)
                    {

                        if (data_in[j] == 1)
                        {
                            Serial.print("SUCCESS");
                            return;
                        }
                        else
                        {
                            Serial.print("DEFFFFEAT");
                            return;
                        }
                    }
                    counter++;
                }
            }
        }
    }
    counter = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            if (counter == third_cable)
            {
                if (data_in[i] == 1 && cable_color[i] == WHITE)
                {
                    Serial.print("SUCCESS");
                    return;
                }
                else
                {
                    break;
                }
            }

            counter++;
        }
    }
    counter = 0;

    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            if (cable_color[i] == BLUE)
            {
                counter++;
                temp = i;
            }
        }
    }
    if (counter >= second_cable && data_in[temp] == 1)
    {
        Serial.print("SUCCESS");
        return;
    }

    counter = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {

        Serial.println("counter::");
        Serial.println(counter);
        if (counter == third_cable && data_in[i] == 1 && cable_color[i] != BLACK)
        {
            Serial.print("SUCCESS");
            return;
        }
        if (cable_color[i] != BLACK)
        {
            counter++;
        }
    }
    Serial.print("DEFEAT");
    return;
}

void four_cables() {}

void five_cables() {}

void six_cables() {}