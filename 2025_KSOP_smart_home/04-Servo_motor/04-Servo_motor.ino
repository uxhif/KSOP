#include <Servo.h>

int servo_pin = 6;

Servo my_servo;

void setup() {
  // put your setup code here, to run once:
  my_servo.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:



  // TODO: 서보 모터 각도 theta1으로 움직이게 하기
  my_servo.write(150);

  // 1초 대기
  delay(1000);

  // TODO: 서보 모터 각도 theta2으로 움직이게 하기
  my_servo.write(-30);

  // 1초 대기
  delay(1000);

}
