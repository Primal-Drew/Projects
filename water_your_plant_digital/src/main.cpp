#include <Arduino.h>
#include "drivers/moisture_sensor.h"

#define LED 5
#define moisture_sensor A0

void setup()
{
  init_pins(moisture_sensor,LED);
  Serial.begin(115200);
}

void loop()
{
  LED_switch(moisture_sensor,LED);
  int reading = analogRead(moisture_sensor);
  Serial.println(reading);
  delay(100);
}
