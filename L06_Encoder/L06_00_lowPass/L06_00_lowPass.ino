/*
 * Project: LowPass
 * Description: Learn to build Low Pass Filter and use Serial Plotter
 * Author: Brian A Rashap
 * Date: 11-JAN-2021
 */

#include <math.h>

const int OUTPIN = A14;
const int SIGNALPIN = 15;
const int FILTERPIN = 14;
const int FREQPIN = 16;

int freq;
float t;
float sig,unfilt, filt;
 
void setup() {
  Serial.begin(9600);
  while(!Serial);

  pinMode(OUTPIN,OUTPUT);
  pinMode(SIGNALPIN,INPUT);
  pinMode(FILTERPIN,INPUT);
  pinMode(FREQPIN,INPUT);
}

void loop() {
  freq = analogRead(FREQPIN)/2;  //vary freq from 0 to 511;
  //freq = 50;
  t = micros()/1000000.0;
  sig = 1.65*(sin(2*M_PI*freq*t)+1);
  analogWrite(OUTPIN,(255/3.3)*sig);
  unfilt = analogRead(SIGNALPIN);
  filt = analogRead(FILTERPIN);
  Serial.printf("%i,%0.2f, %0.2f\n",freq,unfilt/4,filt/4);
  delayMicroseconds((10000/freq));
}
