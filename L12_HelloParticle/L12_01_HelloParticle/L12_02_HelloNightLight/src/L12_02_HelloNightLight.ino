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
unsigned int currentTime, lastTime;

void setup() {
  pinMode(LEDPIN,OUTPUT);
  pinMode(PHOTOPIN,INPUT);
}

void loop() {
  photoValue = analogRead(A0);
  if(photoValue < THRESHOLD ) {
    digitalWrite(LEDPIN,HIGH);
  }
  else {
    digitalWrite(LEDPIN,LOW);
  }
}