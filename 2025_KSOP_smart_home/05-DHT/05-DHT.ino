#include "DHT.h"

int dht_pin = 3;
DHT dht(dht_pin, DHT11);

int temperature;
int humidity;

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // TODO: 센서에서 온도 읽어들이기
  temperature = dht.readTemperature();

  // TODO: 센서에서 습도 읽어들이기
  humidity = dht.readHumidity();
  

  // 온도 갑시고 습도 값 시리얼 모니터로 출력하기
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(1000);
}
