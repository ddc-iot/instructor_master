/*
 * Project: Sine Wave 
 * Description: Teach sine wave
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

#include <math.h>   //the math library gives access to Trigometeric functions

const int LEDPIN = 5;
float t;               //time variable 
float freq = 0.2;      //frequency in Hz
int value;             //sine wave output, scaled for analogWrite

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  t = millis() / 1000.0;
  value = 127*(sin(2*M_PI*freq*t)+1);
  analogWrite(LEDPIN,value);
}
