/*
 * BASIC ARDUBOT
 *
 * A simple Ardubot that demonstrates a basic set of movements.
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

// setup() is run only one at the beginning.
void setup()
{
    // The motor pins are OUTPUTs
    pinMode(motor_left_p, OUTPUT);
    pinMode(motor_left_n, OUTPUT);  
    pinMode(motor_right_p, OUTPUT);
    pinMode(motor_right_n, OUTPUT);
}


// the loop() keeps running continuously as long as the Arduino is connected to a power supply.
void loop()
{
    // We first move forward for a while
    motor_left('F');
    motor_right('F');
    delay(100);

    // We then turn clockwise
    motor_left('F');
    motor_right('B');
    delay(100);

    // Turn anti-clockwise
    motor_left('B');
    motor_right('F');
    delay(100);

    // ...and finally go backwards
    motor_left('B');
    motor_right('B');
    delay(100);

    // stop for quarter of a second.
    motor_left('S');
    motor_right('S');
    delay(250);
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
