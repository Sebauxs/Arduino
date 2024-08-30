/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

#include <Servo.h>

Servo myservo;
int pos = 0;
bool backwards = false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo.attach(8);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int potentiometerValue = analogRead(A0);

  if(potentiometerValue > 10)
  {
    int local_pot_var = potentiometerValue;
    if(potentiometerValue > 1023 / 3)
    {
      local_pot_var = 1023 / 3;
    }
    int brightness_9 = map(local_pot_var, 0, 1023 / 3, 0, 255);
    analogWrite(9, brightness_9);
  }
  else
  {
    analogWrite(9, 0);
  }
  
  if (potentiometerValue >= (1023 / 3 ))
  {
    int local_pot_var = potentiometerValue;
    if(potentiometerValue > 1023 / 1.5)
    {
      local_pot_var = 1023 / 1.5;
    }
    int brightness = map(local_pot_var, 1023 / 3, 1023 / 1.5, 0, 255);
    analogWrite(10, brightness);
  }
  else
  {
    analogWrite(10, 0);
  }
  
  if (potentiometerValue >= (1023 / 1.5 ))
  {
    int brightness = map(potentiometerValue, 1023 / 1.5, 1023, 0, 255);
    analogWrite(11, brightness);
  }
  else
  {
    analogWrite(11, 0);
  }

  Serial.print(pos);
  Serial.print("/t");
  if(pos < 180 && !backwards)
  {
    pos += potentiometerValue / 8;
    myservo.write(pos);

    if(pos > 170)
    {
      backwards = true;
    }
  }
  else
  {
    pos -= potentiometerValue / 8;
    myservo.write(pos);

    if(pos <= 5)
    {
      backwards = false;
    }
  }

  delay(100);  // delay in between reads for stability
}
