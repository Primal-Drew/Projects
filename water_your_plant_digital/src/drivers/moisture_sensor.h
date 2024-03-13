#ifndef DRIVERS_MOISTURE_SENSOR
#define DRIVERS_MOISTURE_SENSOR
#include <Arduino.h> 

/**
 * A function that initializes the  the physical pins.
 * @param moisture_sensor - The physical pin number for the moisture sensor.
 * @param LED - The physical pin number for the moisture sensor.
*/
void init_pins(int moisture_sensor,int LED);

/**
 * A function that test the condition whether the moisture is HIGH or LOW.
 * Then turns the LED on or Off
*/
void LED_switch(int moisture_sensor,int LED);
#endif