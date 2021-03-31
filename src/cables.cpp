#include <Arduino.h>
#include "cables.h"
#include "global.h"
void cables_cut()
{
    //byte data_in = 0;

    for (int j = 0; j < AMOUNT_OF_CABLES; j++)
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