/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L12_HelloParticle/L12_03_Resolution/src/L12_03_Resolution.ino"
/*
 * Project L12_03_Resolution
 * Description: Determine Read/Write resolution of Particle Argon
 * Author: Brian Rashap
 * Date: 02-AUG-2021
 */

void setup();
void loop();
#line 8 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L12_HelloParticle/L12_03_Resolution/src/L12_03_Resolution.ino"
const int READPIN = A0;
const int WRITEPIN = A1;

void setup() {
  Serial.begin(9600);
  while(!Serial);     // no reason to continue if Serial monitor not connected

  pinMode(READPIN,INPUT);
  pinMode(WRITEPIN,OUTPUT);

  analogWrite(WRITEPIN,63);

  Serial.printf("Please connect 3.3V to Pin A0 \n And, the voltmeter to Pin A1\n");
}

void loop() {
  Serial.printf("A0 reads a value of %i\n",analogRead(READPIN));
  delay(1000);
}