/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L12_HelloParticle/L12_01_HelloParticle/src/L12_01_HelloParticle.ino"
/*
 * Project L12_01_HelloParticle
 * Description: First Particle Argon assignment without using delays
 * Author: Brian Rashap
 * Date: 7-DEC-2020
 */

void setup();
void loop();
#line 8 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L12_HelloParticle/L12_01_HelloParticle/src/L12_01_HelloParticle.ino"
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