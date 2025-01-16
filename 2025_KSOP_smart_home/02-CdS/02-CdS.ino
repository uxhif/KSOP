


// CdS sensor pin
int CdS_pin = A0;

// LED pin
int led_pin = 13;
// 더 많은 LED를 제어하려면??


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  // TODO: CdS 센서 값 읽어들이기
  int CdS_value = analogRead(CdS_pin);


  // CdS 센서 값 출력하기
  Serial.print("CdS value: ");
  Serial.println(CdS_value);

  // 0.5초 기다리기
  delay(500);

}
