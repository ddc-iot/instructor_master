/*
 * Project L12_01_HelloParticle
 * Description: First Particle Argon assignment without using delays
 * Author: Brian Rashap
 * Date: 7-DEC-2020
 */

const int LEDPIN = D7;
const int BLINKTIME = 250;

bool ledState;
unsigned int currentTime, lastTime;

void setup() {
  pinMode(LEDPIN,OUTPUT);
  ledState = LOW;
}

void loop() {
  currentTime = millis();
  if(millis()-lastTime > BLINKTIME) {
    ledState = !ledState;
    digitalWrite(LEDPIN,ledState);
    lastTime = currentTime;
  }
}