#include <Arduino.h>
#include "h_bridge.h"


void h_bridge_init(h_bridge *motor)
{
    pinMode(motor->enA, OUTPUT);
    pinMode(motor->frwd1, OUTPUT);
    pinMode(motor->bckwd2, OUTPUT);
}
void h_bridge_foward(h_bridge *motor)
{
    digitalWrite(motor->frwd1, HIGH);
    digitalWrite(motor->bckwd2, LOW);
}

void h_bridge_backward(h_bridge *motor)
{
    digitalWrite(motor->frwd1, LOW);
    digitalWrite(motor->bckwd2, HIGH);
}

void h_bridge_set_speed(h_bridge *motor, int motor_speed)
{
    int mapped_speed = map(motor_speed, 0, 100, 0, 255);
    analogWrite(motor->enA, mapped_speed);
}

void h_bridge_set_direction(h_bridge *motor, motor_direction direction)
{
    if (direction == FORWARD)
    {
        h_bridge_foward(motor);
    }
    else if (direction == BACKWARD)
    {
        h_bridge_backward(motor);
    }
}
