/*
 * Project L12_02_HelloNightLight
 * Description: Create a night light using Argon
 * Author: Brian Rashap
 * Date: 7-DEC-2020
 */

const int LEDPIN = D4;
const int PHOTOPIN = A0;
const int THRESHOLD = 100;

int photoValue;
int ledValue;
unsigned int currentTime, lastTime;

void setup() {
  pinMode(LEDPIN,OUTPUT);
  pinMode(PHOTOPIN,INPUT);
}

void loop() {
  photoValue = analogRead(A0);

  /* Part 1 - digitalWrite
    if(photoValue < THRESHOLD ) {
      digitalWrite(LEDPIN,HIGH);
    }
    else {
      digitalWrite(LEDPIN,LOW);
    }
  */

  ledValue = map(photoValue,0,4096,255,0);
  analogWrite(LEDPIN,ledValue);
}