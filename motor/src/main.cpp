#include <Arduino.h>
#include "drivers/motor_control.h"

#define motor 4
#define pot 5

void setup()
{
  pinMode(motor,OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(115200);
}

void loop()
{
  pot_motor_ctrl(pot,motor);
  Serial.println(analogRead(5));
  delay(100);
}
