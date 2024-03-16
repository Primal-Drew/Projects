#ifndef DRIVERS_H_BRIDGE_H
#define DRIVERS_H_BRIDGE_H
#include <Arduino.h>

typedef enum
{
    FORWARD,
    BACKWARD
} motor_direction;

typedef struct
{
    int8_t enA; 
    int8_t frwd1;
    int8_t bckwd2;
} h_bridge;

/**
 * A function initializes the pinModes of the H_bridge
 * @param motor - A pointer to a h_bridge struct.
 *
 */
void h_bridge_init(h_bridge *motor);

/**
 * A function that allows the user to enter a given speed.
 * @param motor - A pointer to a h_bridge struct.
 * @param motor_speed - An integer between 0-100 to control motor speed.
 */
void h_bridge_set_speed(h_bridge *motor, int motor_speed);

/**
 * A function that makes allows takes direction of movement of motor.
 * @param motor - A pointer to h_bridge struct.
 * @param direction - An enum option(FOWARD/BACKWARD).
 */
void h_bridge_set_direction(h_bridge *motor,motor_direction direction);

#endif