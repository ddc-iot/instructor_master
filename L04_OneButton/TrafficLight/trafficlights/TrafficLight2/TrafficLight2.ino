/*
   Project: TrafficLight
   Decription: Learn to create and use Classes, Objects, and Methods
   Author: Brian Rashap
   Date: 12-JUN-2020
*/

#include "TrafficLight.h"
#include "Button.h"

//Declare Pins
int PIN_GREEN = 5;
int PIN_YELLOW = 6;
int PIN_RED = 7;
int PIN_Button = 23;

TrafficLight trafficLight(PIN_GREEN, PIN_YELLOW, PIN_RED);
Button button(PIN_Button);

void setup() {

}

void loop() {
  if (button.isPressed()) {
    trafficLight.stop();
  }
  else {
    trafficLight.go();
  }

  trafficLight.loop();
}
