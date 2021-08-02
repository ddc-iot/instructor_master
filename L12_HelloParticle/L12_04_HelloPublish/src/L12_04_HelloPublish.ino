/*
 * Project L12_04_HelloPublish
 * Description: Learn to publish to Particle Clod
 * Author: Brian Rashap
 * Date: 02-AUG-2021
 */

#include "JsonParserGeneratorRK.h"

const int LEDPIN = D4;
const int PHOTOPIN = A0;
const int PUBLISHFREQ = 2000;

int photoValue;
int ledValue;
unsigned int currentTime, lastTime;

void setup() {
  pinMode(LEDPIN,OUTPUT);
  pinMode(PHOTOPIN,INPUT);
  lastTime = 0;
}

void loop() {
  currentTime = millis();
  if ((currentTime-lastTime)>PUBLISHFREQ) {
    photoValue = analogRead(A0);
    ledValue = map(photoValue,0,4096,255,0);
    analogWrite(LEDPIN,ledValue);
    Particle.publish("PhotoDiode",String(photoValue));
    Particle.publish("LED",String(ledValue));
    createEventPayload(photoValue,ledValue);
    lastTime = currentTime;
  }
}

void createEventPayload(int photo, int led) {
  JsonWriterStatic<256> jw;
  {
    JsonWriterAutoObject obj(&jw);

    jw.insertKeyValue("Photo Diode",photo);
    jw.insertKeyValue("LED",led);
  }
  Particle.publish("env-vals",jw.getBuffer(),PRIVATE);
}