#include "pitches.h"

// FRS pin
int frs = A5;

// Buzzer pin
int buzzer = 10;

// Leds pins
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;

int leds[] = {2,3,4,5,6,7,8,9};


void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

 // noTone(8);
}

// Pentatonic: {NOTE_E2, NOTE_G2, NOTE_A2, NOTE_AS2, NOTE_B2, NOTE_D3,  NOTE_E3, NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_D4, NOTE_E4,  NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_D6, NOTE_E6,  NOTE_G6, NOTE_A6, NOTE_AS6, NOTE_B6, NOTE_D7 };
// Lenght 30


int notes[] = {NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3};
bool can_play_note = true;
unsigned long note_delay = 400;
int frecuency_values[400] = {};
int frecuency_amount = 0;
unsigned long time;
unsigned long next_time;
int cached_note = -1;

void loop() {

  time = millis();
  Serial.println(time);
  Serial.println(next_time);

  if (time >= next_time)
  {
    can_play_note = true;
  }
  
  if(!can_play_note)
  {
    int force_amount = analogRead(frs);
    Serial.println(force_amount);
    frecuency_values[frecuency_amount] = force_amount;
    frecuency_amount++;

      if(cached_note != -1)
      {
        for(int i = 0; i <= cached_note; i++)
        {
          digitalWrite(leds[i], HIGH);
        }

        for(int j = cached_note + 1; j <= 7; j++)
        {
          digitalWrite(leds[j], LOW);
        }
      }
      else
      {
        for(int i = 0; i <= 7; i++)
        {
          digitalWrite(leds[i], LOW);
        }
      }
  }
  else
  {
    int force = 0;
    for (int j = 0; j < frecuency_amount; j++)
    {
      force += frecuency_values[j];
    }
    
    force = force / frecuency_amount;
    Serial.print("Force: ");
    Serial.print(force);
    frecuency_amount = 0;

    int frecuency_force = map(force, 0, 230, -1, 7);
    int final_note = -1;
     cached_note = frecuency_force;
    
    if(frecuency_force >= 0)
    {
      final_note = notes[frecuency_force];
    }

   
    Serial.println(final_note);

    if(final_note >= 0)
    {
      tone(buzzer, final_note, note_delay * 2);
      can_play_note = false;
      next_time = millis() + note_delay;
    }
    else
    {
      noTone(note_delay);
      can_play_note = false;
      next_time = millis() + note_delay;
    }
  }
}
