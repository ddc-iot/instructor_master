/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: Brian A Rashap
 * Date: 13-Dec-2019
 */

// Set-up: connect a button with a pulldown resistor to Pin 23

#include "OneButton.h"

// Setup OneButton on pin 23
OneButton button1(20, true, true);    // the second parameter is the "activeLOW" option: "true" means when button is pushed the input is LOW
                                 // our button is connected with a pull_down resistor, so we set this parameter to "false"

bool buttonState = false;        // with a single and double click, we will change the states of these two parameters. 
bool flash = false;              // they will be used in the next assignments

void setup() {

  Serial.begin(9600);
  while (!Serial); 

  // link the button 1 functions.
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);
  button1.attachDuringLongPress(longPress1);
  button1.setClickTicks(250);
  button1.setPressTicks(2000);

  Serial.println("Starting OneButton...");
  Serial.println("Click, Doubleclick, and LongPress the button to see what happens");
} 

void loop() {
  button1.tick();     // keep watching the button to see if it is clicked, doubleclicked, or long pressed. 
} 


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time (a click)
void click1() {
  Serial.println("Button 1 click.");
  buttonState = !buttonState;
  Serial.print("buttonState = ");
  Serial.println(buttonState); 
}

// This function will be called when the button1 was pressed 2 times in a short timeframe (a double click)
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
  flash = !flash;
  Serial.print("flash = ");
  Serial.println(flash);
}

// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("Button 1 longPress start");
}

// This function will be called often, while the button1 is pressed for a long time.
void longPress1() {
  Serial.println("Button 1 longPress...");
}

// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStop1() {
  Serial.println("Button 1 longPress stop");
}
