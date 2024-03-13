#include "light_sensor.h"
#include <Arduino.h>

int map_analog_to_val(int analog_reading)
{
    int mapped_val = map(analog_reading,20,30,255,0);
    int constrained_val = constrain(mapped_val,0,255);
    return constrained_val;
}
