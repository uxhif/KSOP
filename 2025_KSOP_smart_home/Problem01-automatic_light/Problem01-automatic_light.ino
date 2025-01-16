

int CdS_pin = A0;


// LED pins
int ledR1 = 10;
int ledG1 = 9;
int ledB1 = 8;
int ledR2 = 13;
int ledG2 = 12;
int ledB2 = 11;


bool light_status = 0;
int threshold = 400;


void setup() {
  // put your setup code here, to run once:
  for(int i = 8; i < 14; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
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
  }



  delay(500);




}
