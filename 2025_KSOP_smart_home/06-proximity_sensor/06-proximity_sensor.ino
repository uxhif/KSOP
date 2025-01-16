int irPin = A1;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int IRval = analogRead(irPin);

  Serial.println(IRval);
  delay(1000);
}
