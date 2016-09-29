/*
 * Callibration sketch for the accelerometer.
 *
 * Simply prints out the values from the x, y, and z axes to the serial monitor. These values can be
 * used to calibrate the sensor.
 *
 * To use this code with the tilt controlled robot, keep the accelerometer flat and then record the
 * readings for x and the y axes. The calibrated_x and calibrated_y in the tilt-robot sketch should
 * be set to these base values.
 *
 * Circuit:
 *     - Accelerometer VIN, GND connected to Arduino 5V, GND
 *     - Accelerometer x, y, z axes connected to A0, A1, A2.
 * Abhik Pal
 * (abhik@ardubotics.com)
 *
 * Released under The MIT License (MIT)
 */

//
// ACCELEROMETER PINS
// 
const int accel_x = A0;
const int accel_y = A1;
const int accel_z = A2;

void setup()
{
    // Set the serial port at 9600 bauds
    Serial.begin(9600);
}

void loop()
{
    // We simply print the values from the sensor to the serial monitor.
    Serial.print("x: ");
    Serial.print(analogRead(accel_x), DEC);
    Serial.print('\t');

    Serial.print("y: ");
    Serial.print(analogRead(accel_y), DEC);
    Serial.print('\t');

    Serial.print("z: ");
    Serial.print(analogRead(accel_z), DEC);
    Serial.print('\n');

    delay(100);
}
