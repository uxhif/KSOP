
// LED1 pins
int ledR1 = 10;
int ledG1 = 9;
int ledB1 = 8;

// LED2 pins
int ledR2 = 13;
int ledG2 = 12;
int ledB2 = 11;



void setup() {
  // put your setup code here, to run once:
  for (int i = 8; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  // TODO: LED 1번을 켜 봅시다.
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledR2, HIGH);
  digitalWrite(ledB2, HIGH);

  // 0.5초 (500 밀리초) 동안 상태를 지속합니다.
  delay(500);

  // TODO: LED 1번을 꺼 봅시다.
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR2, LOW);
  digitalWrite(ledB2, LOW);

  // 0.5초 (500 밀리초) 동안 상태를 지속합니다.
  delay(500);

}
