/*
   Project: TrafficLight
   Decription: Learn to create and use Classes, Objects, and Methods
   Author: Brian Rashap
   Date: 12-JUN-2020
*/

#include "TrafficLight.h"
#include "Button.h"

//Declare Pins
const int GREENPIN = 5;
const int YELLOWPIN = 6;
const int REDPIN = 7;
const int BUTTONPIN = 23;


TrafficLight trafficLight(GREENPIN, YELLOWPIN, REDPIN);
Button button(BUTTONPIN);

void setup() {


}

void loop() {
  /*trafficLight.green();
  delay(1000);
  trafficLight.yellow();
  delay(1000);
  trafficLight.red();
  delay(1000);*/

  if (button.isPressed()) {
    trafficLight.red();
  }
  else {
    trafficLight.green();
  }
}
