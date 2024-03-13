#include "motor_control.h"
#include <Arduino.h>

void pot_motor_ctrl(int pot,int motor)
{
    int val = analogRead(pot);
    int mapped_val = map(val,0,1023,0,255);
    int constrained_val = constrain(mapped_val,0,255);
    analogWrite(motor,constrained_val);
    delay(10);
}