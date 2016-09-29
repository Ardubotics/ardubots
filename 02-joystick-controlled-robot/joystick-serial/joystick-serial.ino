/*
 * Joystick and the serial monitor.
 *
 * This sketch outputs data from the joystick at 9600 baud to the 'Serial Monitor' (the serial 
 * monitor needs to be opened to view this data).
 *
 * CIRCUIT:
 *     - Joystick VCC to Arduino 5V, joystick GND to Arduino GND
 *     - Joystick vertical axis to A0, horizontal to A1
 *     - Joystick pushbutton connected to digital pin 2 using a pull-up resistor
 * 
 * Himanshu Bablani
 * (himanshu@ardubotics.com)
 *
 * Released under The MIT License (MIT)
 */

const int VERT  = A0;    // the vertical axis (analog)
const int HORIZ = A1;    // the horizontal axis (analog)
const int SEL   = 2;     // pushbutton on the joystick (digital)

void setup()
{
    // Make the SEL line an input
    pinMode(SEL, INPUT);

    // Turn on the pull-up resistor for the SEL line
    // (see http://arduino.cc/en/Tutorial/DigitalPins)
    digitalWrite(SEL,HIGH);

    // Set up serial port for output
    Serial.begin(9600);
}

void loop()
{
    int vertical, horizontal, select;

    // Read all values from the joystick
    vertical    = analogRead(VERT);     // will be 0-1023
    horizontal  = analogRead(HORIZ);    // will be 0 - 1023

    // will be HIGH (1) if not pressed, and LOW (0) if pressed
    select = digitalRead(SEL);

    // print out the values
    Serial.print("Vertical: ");
    Serial.print(vertical, DEC);
    Serial.print(" Horizontal: ");
    Serial.print(horizontal, DEC);
    Serial.print(" Select: ");

    if(select == HIGH)
       Serial.println("NOT PRESSED");
    else
        Serial.println("PRESSED");

    delay(100);
}
