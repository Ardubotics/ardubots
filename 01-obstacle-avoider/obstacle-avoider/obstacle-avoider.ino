/*
 * OBSTACLE AVOIDER ROBOT
 *
 * A simple Arduino based obstacle avoider robot that uses two infrared distance sensors to
 * "look for" obstacle and change its behavior accordingly. If the robot detects an obstacle to its
 * left, it turns clockwise; if the obstacle is on the right, it turns anti-clockwise; and moves
 * forward if no obstacle is found.
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
// INDICATOR LED.
// 
// When the robot detects an obstacle, this LED is turned on. We use the default LED on the Arduino
// and set this to pin 13.
// 
const int indicator_led = 13;

//
// OBSTACLE SENSORS
// 
// We define the pins on which the infrared proximity sensors are connected. Using an analog input
// for this sensor will allow us to decide on the "distance" at which the robot should stop and
// change its direction.
// 
const int obstacle_sensor_left = A0;
const int obstacle_sensor_right = A1;

//
// DISTANCE THRESHOLD
// 
// At what "distance" does our robot take a turn? We store that information in a variable.  If the
// robot detects an object that is farther away it will not change its direction.
// 
const int threshold = 650;

// setup() is run only one at the beginning.
void setup()
{
    // The motor pins are OUTPUTs
    pinMode(motor_left_p, OUTPUT);
    pinMode(motor_left_n, OUTPUT);  
    pinMode(motor_right_p, OUTPUT);
    pinMode(motor_right_n, OUTPUT);

    // The sensor are INPUTs
    pinMode(obstacle_sensor_left, INPUT);
    pinMode(obstacle_sensor_right, INPUT);
}


// the loop() keeps running continuously as long as the Arduino is connected to a power supply.
void loop()
{
    // We query the sensors to get the readings from the left and the right sensors. These readings
    // represent how far objects are from the sensor. A lower number represents an object that is 
    // farther away and a higher number an object that is closer.
    int distance_left = analogRead(obstacle_sensor_left);
    int distance_right = analogRead(obstacle_sensor_right);

    // If the obstacle is on the left, the robot turns clockwise.
    if (distance_left > threshold)
    {
        motor_left('B');
        motor_right('F');
        delay(100);
    }

    // If the obstacle is on the right, the robot turns anti-clockwise.
    else if (distance_right > threshold)
    {
        motor_left('F');
        motor_right('B');
        delay(100);
    }

    // If there is no obstacle, we continue moving forward.
    else
    {
        motor_left('F');
        motor_right('F');
        delay(50);
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
