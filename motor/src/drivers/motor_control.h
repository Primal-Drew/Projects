#ifndef DRIVERS_MOTOR_CONTROL_H
#define DRIVERS_MOTOR_CONTROL_H

/**
 * A function that allow the user to use an analog sensor to control motor speed.
 * @param pot - The pin number for the potentiometer.
*/
void pot_motor_ctrl(int pot,int motor);

#endif