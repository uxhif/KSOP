

#define C4 262 // 도 
#define D4 294 // 레 
#define E4 330 // 미 
#define F4 349 // 파 
#define G4 392 // 솔 
#define A4 440 // 라 
#define B4 494 // 시 
#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784
#define A5 880
#define B5 988

int piezo_pin = 2;

int notes_1[25] = {D5, G5, D5, C5, F5};
int duration_1[25] = {150, 150, 200, 200, 100};
//int tempo = 100;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++) {
    tone (piezo_pin, notes_1[i], duration_1[i] * 2);
    delay (duration_1[i] * 2.2);
  }

  delay(100000);

}
