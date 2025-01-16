int irPin = A1;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // TODO: 근접 센서 값 읽어들이기
  int IRval = analogRead(irPin);

  // 근접 센서 값 출력하기
  Serial.println(IRval);
  delay(1000);
}
