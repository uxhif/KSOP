#include <Wire.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C TV(0x27, 16, 2);  //I2C LCD를 TV이름으로 선언

int piezoPin = 2;          //피에조부저를 오렌지보드 D2번에 연결
int irPin = A1;            //적외선장애물센서를 오렌지보드 A1번에 연결

bool flag = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(piezoPin, OUTPUT);    //D2번핀을 출력핀으로 설정

  TV.init();
  TV.backlight();
  TV.setCursor(0, 0);
  TV.print("Looking TV....");
}

void loop()
{
  int IRval = analogRead(irPin);    //적외선장애물센서 측정

  if (IRval < 100) {          //TV가 켜져있고 거리가 가깝다면 TV를 끈다
    if (flag == 1) {
      flag = 0;
      TV.clear();
      TV.noBacklight();
    }
    tone(2, 1000, 300);       //거리가 가깝다면 피에조부저에서 0.3초 간격으로 알람이 울린다
    delay(600);
  }

  else if (IRval > 900 && flag == 0) {  //TV가 꺼져있고 거리가 멀어지면 TV를 켠다
    flag = 1;
    TV.backlight();
    TV.print("Looking TV....");
    noTone(2);
  }
  delay(100);
}