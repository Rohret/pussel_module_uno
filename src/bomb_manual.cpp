#include <Arduino.h>
#include "global.h"
#define threecables 3
#define second_cable 1
#define third_cable 2
#define fourth_cable 3
#define FOUR 4
#define TWO 2

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
                if (data_in[i] == 0 && cable_color[i] == WHITE)
                {
                    Serial.print("DEFEAT");
                    return;
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
    if (counter >= second_cable && data_in[temp] == 0)
    {
        Serial.print("DEFEAT");
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

void four_cables()
{
    int counter = 0;
    int counter_two = 0;
    int temp = 0;
    int check = 0;

    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            if (cable_color[i] == RED)
            {
                counter++;
                temp = i;
            }
        }
    }
    if (counter > second_cable && data_in[temp] == 1)
    {
        Serial.print("SUCCESS10");
        return;
    }
    if (counter > second_cable && data_in[temp] == 0)
    {
        Serial.print("Defeat!");
        return;
    }
    counter = 0;
    temp = 0;
    check = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] == RED)
        {
            break;
        }
        if (cable_color[i] != BLACK)
        {
            if (check == 0)
            {
                temp = i;
                check = 1;
            }

            if (counter == fourth_cable)
            {
                if (data_in[temp] == 1 && cable_color[i] == YELLOW)
                {
                    Serial.println("SUCCESS");
                    return;
                }
                if (data_in[temp] == 0 && cable_color[i] == YELLOW)
                {
                    Serial.print("Defeat!!");
                    return;
                }
            }

            counter++;
        }
    }
    counter = 0;
    temp = 0;
    check = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {

        if (cable_color[i] != BLACK)
        {
            if (check == 0)
            {

                temp = i;
                check = 1;
            }
            if (cable_color[i] == BLUE)
            {
                counter++;
            }
        }
    }

    if (counter == 1 && data_in[temp] == 1)
    {
        Serial.println("SUCCESS");
        return;
    }
    if (counter == 1 && data_in[temp] == 0)
    {
        Serial.print("DEefeat!!");
        return;
    }
    counter = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            counter_two++;
            if (cable_color[i] == YELLOW)
            {
                counter++;
            }

            if (counter > 1 && data_in[i] == 1 && counter_two == FOUR)
            {
                Serial.println("SUCCEesSS");
                return;
            }
            if (counter > 1 && data_in[i] == 0 && counter_two == FOUR)
            {
                Serial.println("DDEFEAT");
                return;
            }
        }
    }
    counter = 0;
    temp = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {

            if (counter == second_cable)
            {
                temp = i;
            }
            if (counter == fourth_cable && data_in[temp] == 1)
            {
                Serial.println("SUCCEssssSS");
                return;
            }
            if (counter == fourth_cable && data_in[temp] == 0)
            {
                Serial.println("DEF");
                return;
            }

            counter++;
        }
    }
}

void five_cables() {}

void six_cables() {}