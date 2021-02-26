/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L12_HelloParticle/L12_01_HelloParticle/L12_02_HelloNightLight/src/L12_02_HelloNightLight.ino"
/*
 * Project L12_02_HelloNightLight
 * Description: Create a night light using Argon
 * Author: Brian Rashap
 * Date: 7-DEC-2020
 */

void setup();
void loop();
#line 8 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L12_HelloParticle/L12_01_HelloParticle/L12_02_HelloNightLight/src/L12_02_HelloNightLight.ino"
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