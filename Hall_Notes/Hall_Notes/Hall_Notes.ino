#include "pitches.h"

// FRS pin
int hallpin = A0;
int potentiometer = A1;
int button = 2;
int sensor;

// Buzzer pin
int buzzer = 3; 

// Min 10
// Medium 35
// Max 65

// Potentiometer goes from 0 to 1000
void setup() {

  pinMode(hallpin, OUTPUT);
  pinMode(button, INPUT);

  Serial.begin(9600);
}

// Pentatonic: {NOTE_E2, NOTE_G2, NOTE_A2, NOTE_AS2, NOTE_B2, NOTE_D3,  NOTE_E3, NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_D4, NOTE_E4,  NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_D6, NOTE_E6,  NOTE_G6, NOTE_A6, NOTE_AS6, NOTE_B6, NOTE_D7 };
// Lenght 30

unsigned long time;
unsigned long next_time;


bool can_play = false;


int notes[] = {NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4};

void loop() {

  time = millis();

  int pressed = digitalRead(button) == HIGH;

  int speed = analogRead(potentiometer);
  unsigned long note_delay = map(speed, 20, 1000, 50, 4000);
  //Serial.println("Note Delay:");
 // Serial.println(note_delay);

  sensor = analogRead(hallpin);
  Serial.println("Sensor:");
  Serial.println(sensor);

  int note = map(sensor, 10, 60, 0, 14);
  Serial.println(note);

  if (next_time <= time )
  {
    can_play = true;
  }

  if(pressed)
  {
    if(can_play)
    {
      Serial.println("Playing a note");
      tone(buzzer, notes[note], note_delay);
      next_time = note_delay + time;
      can_play = false;
    }
  }
  else
  {
    Serial.println("Button, not pressed.");
    noTone(buzzer);
    can_play = true;
  }
}
