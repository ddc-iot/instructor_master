/*
 * Project L13_00_DAC
 * Description: Sine Wave Generator for Digital to Analog Project 
 * Author: Brian Rashap
 * Date: 4-AUG-2021
 */

#include "math.h"

const int PIN63 = D4;
const int SIGNALPIN = A0;
const int FREQ = 75;

float t, signal;

void setup() {
  pinMode(PIN63,OUTPUT);
  pinMode(SIGNALPIN,OUTPUT);
  analogWrite(PIN63,63);
}

void loop() {
  t = micros()/1000000;
  signal = 31 * sin(2 * M_PI * FREQ * t) + 127;
  analogWrite(SIGNALPIN,signal,5000);
}