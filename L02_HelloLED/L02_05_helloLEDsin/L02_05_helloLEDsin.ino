/*
 * Project: Sine Wave 
 * Description: Teach sine wave
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

#include <math.h>   //the math library gives access to Trigometeric functions

const int LEDPIN = 5;

float t;               //time variable 
float period = 5000;   //period in ms
int value;             //sine wave output, scaled for analogWrite

void setup() {
pinMode(LEDPIN, OUTPUT);
}

void loop() {
  t = millis() / period;
  value = 255*(0.5*sin(2*3.14159*t)+0.5);
  analogWrite(LEDPIN,value);
}
