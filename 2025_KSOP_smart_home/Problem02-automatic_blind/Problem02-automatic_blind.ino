#include <Servo.h>

int CdS_pin = A0;


// LED pins
int ledR1 = 10;
int ledG1 = 9;
int ledB1 = 8;
int ledR2 = 13;
int ledG2 = 12;
int ledB2 = 11;


bool light_status = 0;
int threshold = 350;


int servo_pin = 6;

Servo my_servo;


void setup() {
  // put your setup code here, to run once:
  for(int i = 8; i < 14; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);

  my_servo.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:


  int CdS_value = analogRead(CdS_pin);
  Serial.print("CdS value: ");
  Serial.println(CdS_value);

  if (CdS_value < threshold && light_status) // bright
  {
    light_status = 0;
    digitalWrite(ledR1, LOW);
    digitalWrite(ledG1, LOW);
    digitalWrite(ledB1, LOW);

    digitalWrite(ledR2, LOW);
    digitalWrite(ledG2, LOW);
    digitalWrite(ledB2, LOW);

    my_servo.write(150);
    delay(1000);
  }

  else if (CdS_value >= threshold && !light_status) // bright
  {
    light_status = 1;
    digitalWrite(ledR1, HIGH);
    digitalWrite(ledG1, HIGH);
    digitalWrite(ledB1, HIGH);

    digitalWrite(ledR2, HIGH);
    digitalWrite(ledG2, HIGH);
    digitalWrite(ledB2, HIGH);

    my_servo.write(-30);
    delay(1000);
  }



  delay(500);




}
