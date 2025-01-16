#include <Servo.h>

int servo_pin = 6;

Servo my_servo;

void setup() {
  // put your setup code here, to run once:
  my_servo.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:

  my_servo.write(150);
  delay(1000);
  my_servo.write(-30);
  delay(1000);

}
