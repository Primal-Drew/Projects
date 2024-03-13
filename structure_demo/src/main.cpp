#include <Arduino.h>
#include "drivers/led.h"

//bub pin
#define led_1_PIN 2

led_t led_1;


void setup() {
  led_init(&led_1, led_1_PIN, 0);
}

void loop() {
  led_on(&led_1);
  delay(500);
  led_off(&led_1);
  delay(500);
}
