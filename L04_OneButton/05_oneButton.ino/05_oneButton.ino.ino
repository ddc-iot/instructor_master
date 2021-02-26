/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: 
 * Date: 
 */

#include <OneButton.h>

// Setup OneButton on pin 23

// Create variables buttonState and flash

OneButton button1(23,false);

void setup() {

// Setup Serial Monitor
// Link oneButton library to functions click1, doubleclick1, longPressStart1

} 

void loop() {
  // keep watching the push buttons:
  button1.tick();
} // loop


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time.
void click1() {
//change and print buttonState
  
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
// change state of flash and print
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
// print longPress
} // longPressStart1
