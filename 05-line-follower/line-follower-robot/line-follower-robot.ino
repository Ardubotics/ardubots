/*
 * LINE FOLLOWER ROBOT
 *
 * An Arduino based robot that uses an infrared sensor array to follow a line.
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
// LINE FOLLOWER ARRAY SENSORS
// 
// We define the pins on which the infrared proximity sensors are connected. 
// 
const int line_sensor_left = A0;
const int line_sensor_middle = A1;
const int line_sensor_right = A1;

//
// DETECTION THRESHOLD
// 
// What output of the sensor corresponds to a "line"? The exact value should be obtained by
// experimenting with the sensor and the serial monitor.
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
    pinMode(line_sensor_left, INPUT);
    pinMode(line_sensor_middle, INPUT);
    pinMode(line_sensor_right, INPUT);
}


// the loop() keeps running continuously as long as the Arduino is connected to a power supply.
void loop()
{
    // We first get the readins from the sensors
    int reading_left = analogRead(line_sensor_left);
    int reading_left = analogRead(line_sensor_left);
    int reading_right = analogRead(line_sensor_right);

    // Depedning on how the sensors are activated, we move forward and turn left/right. 
    //      
    //      [ ] [ ] [ ] - No line detected. Stop robot.
    //      [*] [ ] [ ] - Line to the left, turn left.
    //      [ ] [*] [ ] - Line is in the middle, continue forward.
    //      [ ] [ ] [*] - Line to the right, turn right.
    //      
    //      (The [ ] above represents a sensor and [*] shows that it is activated.)
    if (reading_left > threshold)
    {
        motor_right('F');
        motor_left('B');
    }
    else if (reading_right > threshold)
    {
        motor_right('B');
        motor_left('F');
    }
    else if (reading_middle > threshold)
    {
        motor_right('F');
        motor_left('F');
    }
    else 
    {
        motor_right('S');
        motor_left('S');
    }

    delay(50);
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
