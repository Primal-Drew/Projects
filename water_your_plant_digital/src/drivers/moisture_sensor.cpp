#include "moisture_sensor.h"
#include <Arduino.h>

int moisture_sensor;
int LED;

void init_pins(int moisture_sensor,int LED)
{
    pinMode(LED,OUTPUT);
    pinMode(moisture_sensor,INPUT);
}

void LED_switch(int moisture_sensor,int LED)
{
    int reading = analogRead(moisture_sensor);
    int mapped_value = map(reading,0,25,0,255);
    int constrained_val = constrain(mapped_value,0,255);
    if(constrained_val>177 && constrained_val<256)
    {
        digitalWrite(LED,LOW);
        Serial.println("Water you plant");
    }
    else
    {
        Serial.println("Satisfied!!!");
        digitalWrite(LED,HIGH);
    }
    Serial.println(constrained_val);
}
