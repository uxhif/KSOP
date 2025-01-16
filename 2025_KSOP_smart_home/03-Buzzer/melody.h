/*"melody.h"
   스마트홈에 들어가는 경고음, 멜로디를 설정하는 헤더파일입니다.
*/


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

int notes[] = {523, 1046, 2093};
int notes_1[25] = { G4, G4, A4, A4, G4, G4, E4, G4, G4, E4, E4, D4, G4, G4, A4, A4, G4, G4, E4, G4, E4, D4, E4, C4 };
int tempo = 200;

void ascMelody() {                   //상승음
  for (int i = 0; i < 3; i++) {
    tone(piezoPin, notes[i], tempo);
    delay(200);
  }
}

void dscMelody() {                   //하강음
  for (int i = 3; i >= 0; i--) {
    tone(piezoPin, notes[i], tempo);
    delay(200);
  }
}

//학교종이 땡땡땡//
void melody() {
  for (int i = 0; i < 12; i++) {
    tone (piezoPin, notes_1[i], tempo);
    delay (300);
  }
  delay(100);
  for (int i = 12; i < 25; i++) {
    tone (piezoPin, notes_1[i], tempo);
    delay(300);
  }
}
