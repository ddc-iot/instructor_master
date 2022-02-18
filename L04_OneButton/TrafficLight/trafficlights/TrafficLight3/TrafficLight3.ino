/*
 * Project: Traffic Light
 * Description: Teach OOP to the class
 * Author: Brian Rashap
 * Date: 08-OCT-2021
 */

#include "TrafficLight.h"
#include "Button.h"
#include "IoTTimer.h"

// Declare Pins
const int GREENPIN = 5;
const int YELLOWPIN = 6;
const int REDPIN = 7;
const int BUTTONPIN = 23;

const int TIMER_RED = 5000;

IoTTimer lightTimer;
TrafficLight lightOne(GREENPIN,YELLOWPIN,REDPIN);
Button button(BUTTONPIN);

void setup() {
  
}

void loop() {
  if(button.isPressed()) {
    lightOne.stop();
    lightTimer.startTimer(TIMER_RED);
  }
  else {
    if(lightTimer.isTimerReady()) {
          lightOne.go();
    }
  }

  lightOne.trafficLoop();
}
