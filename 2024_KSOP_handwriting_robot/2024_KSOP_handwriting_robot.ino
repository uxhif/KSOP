


// Servo motor settings
//# define SERVO_PIN 6
//Servo pen_servo;


void forward(float distance)
{
  int steps; // TODO = distance_to_steps(distance);
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
  float distance; // TODO
  int steps; // TODO

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

/*
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
*/


// convert distance to step
int distance_to_steps(float distance)
{
  float revolution; // TODO
  int steps; // TODO

  return steps;
}




 
void setup() 
{
  
  stepper_l.setSpeed(14);
  stepper_r.setSpeed(14);


  // initialise robot
  delay(10000);
  
}


void loop() 
{

}


