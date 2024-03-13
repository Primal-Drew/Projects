#include <Arduino.h>

#define LED 4

void setup()
{
    Serial.begin(115200);
    pinMode(LED,OUTPUT);
}

void loop()
{
    digitalWrite(LED,HIGH);
    Serial.print("LED ON!");
    delay(1000);
    digitalWrite(LED,LOW);
    Serial.print("LED OFF!");
    delay(1000);
}








