/*
 * Project: Servo
 * Description: Learn to use a Servo Motor
 * Author: Brian A Rashap
 * Date: 06-JAN-2021
 */

#include <PWMServo.h> 
#include <math.h>

PWMServo myServo;

const float FREQ = .1;
float t;
int servoOut;

void setup() {
  myServo.attach(22);
}

void loop() {
  t = millis()/1000.0;
  servoOut = 100*(sin(2*M_PI*FREQ*t)+0.5);
  myServo.write(servoOut);  
  delay(20);
}
