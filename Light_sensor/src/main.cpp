#include <Arduino.h>
#include "drivers/light_sensor.h"

#define LED 4
#define LIGHT A0

int reading = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200); 
}

void loop()
{
  reading = analogRead(LIGHT);
  Serial.println(reading);
  
  int val = map_analog_to_val(reading);
  Serial.println(val);


  analogWrite(LED, val);
  delay(100);
}
