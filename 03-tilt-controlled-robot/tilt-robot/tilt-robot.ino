/*
 * Tilt Controlled Robot
 *
 * An arduino based robot that uses an accelerometer as a joystick and moves forward/backward
 * and turns clockwise/anti-clockwise based on the direction of tilt. 
 * 
 * Abhik Pal
 * (abhik@ardubotics.com)
 *
 * Released under The MIT License (MIT) 
 */

//
// THE MOTOR PINS
// 
// The variable names ending in 'p' and 'n' represent the pins controlling the positive and negative 
// terminals of the motors. Depending on how these pins are turned on/off we can control the
// clockwise and anti-clockwise motion of the motors.
// 
const int motor_right_p = 5;
const int motor_right_n = 6;

const int motor_left_p = 3;
const int motor_left_n = 4;

//
// ACCELEROMETER PINS
// 
// We connect the outputs from two accelerometer axes to analog inputs.
// 
const int accel_x = A0;
const int accel_y = A1;

// 
// CALIBRATED "CENTERS"
// 
// After using the accelerometer-calibrate sketch, we get the readouts for the default position of 
// the accelerometer. All movement will be seen relative to these calibrated "center" position 
// readings.
// 
const int calibrated_x = 336;
const int calibrated_u = 322;

//
// TRIGGER THRESHOLD
// 
// We don't want our robot to move on the slightest of tilts, hence we will only move if the tilt is
// atleast above a certain  threshold away from the center mean position.
// 
const int tilt_threshold = 20;

// setup() is run only one at the beginning.
void setup()
{
    // The motor pins are OUTPUTs
    pinMode(motor_left_p, OUTPUT);
    pinMode(motor_left_n, OUTPUT);  
    pinMode(motor_right_p, OUTPUT);
    pinMode(motor_right_n, OUTPUT);

    // The sensor are INPUTs
    pinMode(accel_x, INPUT);
    pinMode(accel_y, INPUT);
}

// the loop() keeps running continuously as long as the Arduino is connected to a power supply.
void loop()
{
    // We first store the values from the sensors
    int x_tilt = analogRead(accel_x);
    int y_tilt = analogRead(accel_y);

    // next, we move the robot based on the tilt of the sensor given that the tilt is more than 
    // the set threshold tilt.
    if ((x_tilt > calibrated_x) && (abs(x_tilt - calibrated_x) > tilt_threshold))
    {
        motor_left('F');
        motor_right('B');
        delay(50);
    }
    else if ((x_tilt < calibrated_x) && (abs(x_tilt - calibrated_x) > tilt_threshold))
    {
        motor_left('B');
        motor_right('F');
        delay(50);
    }
    else if ((y_tilt > calibrated_y) && (abs(y_tilt - calibrated_y) > tilt_threshold))
    {
        motor_left('F');
        motor_right('F');
        delay(50);
    }
    else if ((y_tilt < calibrated_y) && (abs(y_tilt - calibrated_y) > tilt_threshold))
    {
        motor_left('B');
        motor_right('B');
        delay(50);
    }
    else
    {
        motor_left('S');
        motor_right('S');
        delay(10);
    }
}

/*
 * The next two functions control the left/right motors.
 *   'F' - Moves a motor forward.
 *   'B' - Moves a motor backward.
 *   'S' - Stops the motor.
 *
 * The forward and backward motions of the robot are trivial. Both the motors need to go forward and
 * backward. We can introduce clockwise and anti-clockwise motions in our robot by turning one wheel
 * forward and the other backward. For example if the left motor goes forward and the right one
 * backward, our robot will turn clockwise and vice versa.
 * 
 */

void motor_left(char dir)
{
  switch(dir)
  {
    case 'F':
      digitalWrite(motor_left_p, HIGH);
      digitalWrite(motor_left_n, LOW);
      break;
    case 'B':
      digitalWrite(motor_left_p, LOW);
      digitalWrite(motor_left_n, HIGH);
      break;
    case 'S':
      digitalWrite(motor_left_p, HIGH);
      digitalWrite(motor_left_n, HIGH);
      break;
  }
}

void motor_right(char dir)
{
  switch(dir)
  {
    case 'F':
      digitalWrite(motor_right_p, LOW);
      digitalWrite(motor_right_n, HIGH);
      break;
    case 'B':
      digitalWrite(motor_right_p, HIGH);
      digitalWrite(motor_right_n, LOW);
      break;
    case 'S':
      digitalWrite(motor_right_p, HIGH);
      digitalWrite(motor_right_n, HIGH);
      break;
  }
}

