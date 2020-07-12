/*
 * Project: Sine Wave 
 * Description: Teach sine wave
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

#include <math.h>

int ledPin = 5;
float t;            //time variable 
float per = 5000;   //period in ms
int out;            //sine wave output, scaled for analogWrite

void setup() {
pinMode(ledPin, OUTPUT);
}

void loop() {
  t = millis() / per;
  out = 255*(0.5*sin(2*3.14159*t)+0.5);
  analogWrite(ledPin,out);
}
