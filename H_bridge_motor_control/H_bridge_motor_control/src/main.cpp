#include <Arduino.h>
#include "drivers/h_bridge.h"

#define enA 5
#define in1 14
#define in2 13

h_bridge motor_A = {enA, in1, in2};

void setup()
{
  h_bridge_init(&motor_A);
  Serial.begin(115200);
}

void loop()
{
  h_bridge_set_direction(&motor_A, FOWARD);
  Serial.println("Foward");

  for (int i = 0; i < 100; i = i + 10)
  {
    Serial.println(i);
    h_bridge_set_speed(&motor_A, i);
    delay(1000);
  }

  delay(2000);

  for (int i = 100; i > 0; i = i - 10)
  {
    Serial.println(i);

    h_bridge_set_speed(&motor_A, i);
    delay(1000);
  }

  delay(3000);

  h_bridge_set_direction(&motor_A, BACKWARD);
  Serial.println("BACKWARD");

  for (int i = 0; i < 100; i = i + 10)
  {
    Serial.println(i);
    h_bridge_set_speed(&motor_A, i);
    delay(1000);
  }

  for (int i = 100; i > 0; i = i - 10)
  {
    Serial.println(i);
    h_bridge_set_speed(&motor_A, i);
    delay(1000);
  }
  delay(2000);
}