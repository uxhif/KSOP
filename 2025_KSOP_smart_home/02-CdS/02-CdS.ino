

int CdS_pin = A0;
int led_pin = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int CdS_value = analogRead(CdS_pin);

  Serial.print("CdS value: ");
  Serial.println(CdS_value);

  delay(500);

}
