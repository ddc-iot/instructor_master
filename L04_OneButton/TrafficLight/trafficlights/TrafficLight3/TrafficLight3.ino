/*
   Project: TrafficLight
   Decription: Learn to create and use Classes, Objects, and Methods
   Author: Brian Rashap
   Date: 12-JUN-2020
*/

#include "TrafficLight.h"
#include "Button.h"
#include "Timer.h"

// Declare Pins
const int GREENPIN = 5;
const int YELLOWPIN = 6;
const int REDPIN = 7;
const int BUTTONPIN = 23;

Timer lightTimer;
TrafficLight lightOne(GREENPIN,YELLOWPIN,REDPIN);
Button buttonOne(BUTTONPIN);

void setup() {


}

void loop() {
  if(buttonOne.isPressed()) {
    lightOne.stop();
    lightTimer.startTimer(10000);
  }
  else {
    if(lightTimer.isTimerReady()) {
      lightOne.go();
    }
  }
  lightOne.trafficLoop();
}
