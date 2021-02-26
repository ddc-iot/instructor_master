/*
 * Project: Using OneButton library - Two buttons, Two LEDs
 * Description: Use two buttons to light and flash two LEDs 
 * Author: 
 * Date: 
 */

#include "OneButton.h"

// Setup OneButton on pin 23
OneButton button1(23, false); 
OneButton button2(16, false);

// Setup LEDs on Pins 5 and 6


void setup() {



} 

void loop() {
  // keep watching the push buttons:
  button1.tick();
  button2.tick();



}
