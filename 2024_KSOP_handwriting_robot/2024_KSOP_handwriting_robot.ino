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
# define SERVO_PIN 6
Servo pen_servo;


void forward(int distance)
{
  int steps = distance_to_steps(distance);
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

void backward(int distance)
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
  // TODO
  // (pi * axis_diameter) / 4;
  int distance = int(PI * axis_diameter / 4);
  int steps = distance_to_steps(distance);

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

void pen_up()
{
  // TODO
  pen_servo.write(0); // fix
}

void pen_down()
{
  // TODO
  pen_servo.write(30); // fix
}


// convert distance to step
int distance_to_steps(int distance)
{
  float revolution = distance / (PI * wheel_diameter);
  int steps = int(revolution * steps_per_revolution);

  return steps;
}




 
void setup() 
{
  Serial.begin(9600);
  
  stepper_l.setSpeed(14);
  stepper_r.setSpeed(14);

  pen_servo.attach(SERVO_PIN);



  // initialise robot
  pen_up();
  delay(2000);
  pen_down();

  delay(10000);
  
}


void loop() 
{


  /*
  pen_up();
  delay(2000);
  pen_down();
  delay(2000);
  // draw a rectangle
  */
  for (int i = 0; i < 4; i++)
  {
    forward(50);
    turn_right();
  }

  delay(15000);
  
  





  /*
  int length = 0;
  if (Serial.available())
  {
    length = Serial.parseInt();
    
    int steps = int(length /3.141592*2/53 * 1024);

    Serial.print("Length: ");
    Serial.println(length);


    //forward(length);
    
    if(steps != 0)
    {
      stepper_l.setStep(steps);
      stepper_r.setStep(steps);
 
      Serial.print("steps : ");
      Serial.println(steps); 
      delay(100);
    }
  }

  
  stepper_l.moveStep();
  stepper_r.moveStep();

  //Serial.println(stepper_l.MoveOnIs);


  
  
  //Serial.print("Is Move - stepper : ");
  //Serial.print(stepper.MoveOnIs);
  //Serial.print(", stepper2 : ");
  //Serial.println(stepper2.MoveOnIs);

  */

}


