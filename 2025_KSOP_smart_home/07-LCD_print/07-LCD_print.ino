#include "LiquidCrystal_I2C.h"
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  // TODO: 예제 코드를 참고하여 디스플레이에 나만의 글씨를 출력해봅시다.
  lcd.setCursor(0, 0); // 
  lcd.print("KSOP");

  lcd.setCursor(0, 1);
  lcd.print("Example");

  delay (1000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("KSOP");

  lcd.setCursor(0, 1);
  lcd.print("Update");
  
  delay (1000);
}
