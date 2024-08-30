#include "pitches.h"

int melody[] = {
  NOTE_E3, NOTE_FS3, NOTE_G3, NOTE_FS3, NOTE_E3, NOTE_DS3, NOTE_E3, NOTE_FS3, NOTE_B2, NOTE_CS3, NOTE_DS3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_B2, NOTE_A2, NOTE_G2, NOTE_FS2, NOTE_G2, NOTE_A2, NOTE_B2, NOTE_A2, NOTE_G2, NOTE_FS2, NOTE_E2,
  NOTE_E3, NOTE_FS3, NOTE_G3, NOTE_FS3, NOTE_E3, NOTE_DS3, NOTE_E3, NOTE_FS3, NOTE_B2, NOTE_CS3, NOTE_DS3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_B2, NOTE_A2, NOTE_G2, NOTE_FS2, NOTE_G2, NOTE_G2, NOTE_FS2, NOTE_G2, NOTE_FS2, NOTE_G2, NOTE_FS2, NOTE_G2, NOTE_FS2, NOTE_G2, NOTE_G2
};

int noteDurations[] = {
  8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 1
};

void setup() {
  for (int thisNote = 0; thisNote < 51; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(12, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

void loop() {
}
