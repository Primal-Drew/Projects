#ifndef DRIVERS_led_H
#define DRIVERS_led_H

#include <stdint.h>

//define led struct

//functionalities
// - init
// - On
// - off

//led struct
typedef struct led{
    int pin; 
    int state; //on or off state
    uint8_t brightness;
} led_t;


/**
 * initializes led object
 * @param led - pointer to led struct
 * @param pin - physical pin number on arduino board
 * @param initial_state - initial state of led (1 - on , 0 - off)
*/
void led_init(led_t* led, int pin, int initial_state);

/**
 * turns led on
 * @param led - led object to turn on
*/
void led_on(led_t* led);

/**
 * turns led off
 * @param led - led object to turn off
*/
void led_off(led_t* led);


/**
 * set led brightness
 * @param led - led object to set brightness
 * @param brightness -  brightness level from 0 to 255
*/
void led_set_brightness(led_t* led, uint8_t brightness );


#endif