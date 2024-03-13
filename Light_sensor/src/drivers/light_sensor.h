#ifndef DRIVERS_LIGHT_SENSORS_H
#define DRIVERS_LIGHT_SENSORS_H

/**
 * A function that maps a reading from the photoresistor to an 8-bit range (0-255). 
 * @param analog_reading - The variable storing analogRead value.
*/
int map_analog_to_val(int analog_reading);

#endif
