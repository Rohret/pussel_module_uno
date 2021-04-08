#include <Arduino.h>

void success()
{

    Serial.println("You cut the RIGHT cable!");
    Serial.println("");
}
void fail()
{

    Serial.println("You cut the WRONG cable!");
    Serial.println("");
}