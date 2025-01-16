
// LED pins
int ledR1 = 10;
int ledG1 = 9;
int ledB1 = 8;
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
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledR2, HIGH);
  digitalWrite(ledB2, HIGH);
  delay(500);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR2, LOW);
  digitalWrite(ledB2, LOW);
  delay(500);

}
