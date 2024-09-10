#include "pitches.h"

// Sonic pins:

const int one_trigger = 12;
const int two_trigger = 13;

const int one_echo =  8;
const int two_echo =  7;



// Buzzer pin
int buzzer = 4; 


// Potentiometer goes from 0 to 1000
void setup() {

	pinMode(one_trigger, OUTPUT);  
  pinMode(two_trigger, OUTPUT);  
	pinMode(one_echo, INPUT);  
	pinMode(two_echo, INPUT);  

	Serial.begin(9600);  
}


int notes[] = {NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4};

void loop() {

  unsigned long  one_duration, two_duration, one_distance, two_distance;
  // Trigger first one
  digitalWrite(one_trigger, LOW);  
	delayMicroseconds(2);  
	digitalWrite(one_trigger, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(one_trigger, LOW);  

  one_duration = pulseIn(one_echo, HIGH);  
  one_distance = (one_duration*.0343)/2;  

  delay(100);

  // Trigger second one
  digitalWrite(two_trigger, LOW);  
	delayMicroseconds(2);  
	digitalWrite(two_trigger, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(two_trigger, LOW); 

  two_duration = pulseIn(two_echo, HIGH);  
  two_distance = (two_duration*.0343)/2;  

  Serial.print("One duration: ");  
	Serial.println(one_duration);  

  Serial.print("Two duration: ");  
	Serial.println(two_duration);  

  Serial.print("Two Distance: ");  
	Serial.println(two_distance);  

  
}
