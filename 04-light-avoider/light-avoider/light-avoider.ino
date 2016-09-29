/*
 * LIGHT AVOIDER ROBOT
 *
 * A simple Arduino based obstacle avoider robot that uses two light dependent resistors to
 * measure the amount of light in its environment and then move to the area with less light.
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
const int motor_left_p = 5;
const int motor_left_n = 6;

const int motor_right_p = 3;
const int motor_right_n = 4;

//
// LIGHT SENSORS
// 
// We define the pins on which the infrared proximity sensors are connected. Using an analog input
// for this sensor will allow us to decide on the "distance" at which the robot should stop and
// change its direction.
// 
const int light_sensor_left = A0;
const int light_sensor_right = A1;

// setup() is run only one at the beginning.
void setup()
{
    // The motor pins are OUTPUTs
    pinMode(motor_left_p, OUTPUT);
    pinMode(motor_left_n, OUTPUT);  
    pinMode(motor_right_p, OUTPUT);
    pinMode(motor_right_n, OUTPUT);

    // The sensor are INPUTs
    pinMode(light_sensor_left, INPUT);
    pinMode(light_sensor_right, INPUT);
}


// the loop() keeps running continuously as long as the Arduino is connected to a power supply.
void loop()
{
    // We query the sensors and get the amount of light in the robot's environment.
    int light_value_left = analogRead(light_sensor_left);
    int light_value_right = analogRead(light_sensor_right);

    // If there is more light on the right, the robot turns clockwise.
    if (light_value_left > light_value_right)
    {
        motor_left('B');
        motor_right('F');
        delay(50);
    }
    // ..and if the left side of the robot is brighter, we turn anti-clockwise
    else if (light_value_right > light_value_left)
    {
        motor_left('F');
        motor_right('B');
        delay(50);
    }

    // we finally move forward for a while.
    motor_left('F');
    motor_right('F');
    delay(100);
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
