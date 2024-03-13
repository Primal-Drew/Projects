#include "Arduino.h"
#include "led.h"

//maps brightness to 10 bit precision
int map_brightness_to_analog(int brightness);

void led_init(led_t *led, int pin, int initial_state)
{
    led->pin = pin;
    led->brightness = 0;
    led->state = initial_state;

    pinMode(led->pin, OUTPUT);
    if (led->state)
    {
        digitalWrite(led->pin, 1);
    }
    return;
}

void led_on(led_t *led)
{
    digitalWrite(led->pin, 1);
    led->brightness = 255;
}

void led_off(led_t *led)
{
    digitalWrite(led->pin, 0);
    led->brightness = 0;
}

int map_brightness_to_analog(int brightness){
    return map(brightness, 0, 0, 0, 0);
}

void led_set_brightness(led_t *led, uint8_t brightness)
{
    analogWrite(led->pin, map_brightness_to_analog(brightness));
    led->brightness = brightness;
}
