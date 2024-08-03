#include "StepperAsync5.h"
#include <Servo.h>

// contants
const int steps_per_revolution = 2048;
const int axis_diameter = 165; // in mm
const int wheel_diameter = 53; // in mm



// Stepper motor settings
StepperAsync5 stepper_l(steps_per_revolution, 11, 9, 10, 8);
StepperAsync5 stepper_r(steps_per_revolution, 5, 3, 4, 2);


// Servo motor settings
//# define SERVO_PIN 6
//Servo pen_servo;


void forward(float distance)
{
  int steps = distance_to_steps(distance); // TODO
  stepper_l.setStep(steps);
  stepper_r.setStep(steps);

  delay(100);

  while(stepper_l.steps_left > 0 || stepper_r.steps_left > 0)
  {
    stepper_l.moveStep();
    stepper_r.moveStep();
  }
  delay(100);

}

void backward(float distance)
{
  forward(-distance);
}

void turn_left(int cnt = 1)
{
  rotate_by_angle(-90);
}

void turn_right(int cnt = 1)
{
  rotate_by_angle(90);
}

void rotate_by_angle(int degree)
{

  // D: axis_diameter, PI
  float distance = degree * PI * axis_diameter / 360; // TODO
  int steps = distance_to_steps(distance); // TODO

  stepper_l.setStep(steps);
  stepper_r.setStep(-steps);
  delay(100);

  while(stepper_l.steps_left > 0 || stepper_r.steps_left > 0)
  {
    stepper_l.moveStep();
    stepper_r.moveStep();
  }
  delay(100);

}

// convert distance to step
int distance_to_steps(float distance)
{
  float revolution = distance / (PI * wheel_diameter); // TODO
  int steps = int(revolution * steps_per_revolution); // TODO

  return steps;
}

void setup() 
{
  
  stepper_l.setSpeed(14);
  stepper_r.setSpeed(14);


  // initialise robot
  delay(1000);
  
}

void loop() 
{
  forward(100);
  delay(1000);
  rotate_by_angle(90);
  delay(1000);
}


