/*
 * Project: Traffic Light
 * Description: Code-a-long to learn objects
 * Author: Brian Rashap
 * Date: 19-MAR-2021
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