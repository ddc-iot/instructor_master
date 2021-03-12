/*
 * Project: Using OneButton library
 * Description: Use oneButton to light and blink an LED
 * Author: 
 * Date: 
 */

#include "OneButton.h"

// Setup OneButton on pin 23 



void setup() {

  Serial.begin(9600);


} 

void loop() {
  // keep watching the push button:
  button1.tick();
  
  // light or blink LED based on buttonState and Flash 
} 


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time.
void click1() {

// change button state
  
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {

// change flash state

} // doubleclick1
