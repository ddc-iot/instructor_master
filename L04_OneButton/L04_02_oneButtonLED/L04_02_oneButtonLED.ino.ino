/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library: Solid vs Blinking LED
 * Author: Brian A Rashap
 * Date: 13-Dec-2019
 */

// Set-up: connect a button with a pulldown resistor to Pin 23 and a LED to Pin 5.

#include "OneButton.h"

// Setup OneButton on pin 23
OneButton button1(23,false);    // the second parameter is the "activeLOW" option: "true" means when button is pushed the input is LOW
                                // our button is connected with a pull_down resistor, so we set this parameter to "false"
bool buttonState = false;       // with a single and double click, we will change the states of these two parameters. 
bool blinker = false;           // they will be used in the next assignments

// LED pin configure
const int LEDPIN = 5;
int ledDelay = 50;

void setup() {

  Serial.begin(9600);
  while (!Serial); 
  pinMode(LEDPIN,OUTPUT);

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
  if(buttonState) {
    if(blinker) {
      digitalWrite(LEDPIN,HIGH);
      delay(ledDelay);
      digitalWrite(LEDPIN,LOW);
      delay(ledDelay);
    } 
    else {
      digitalWrite(LEDPIN,HIGH);  
    }
  }
  else {
    digitalWrite(LEDPIN,LOW);  
  }
} 


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time (a click)
void click1() {
  Serial.printf("Button 1 click.\n");
  buttonState = !buttonState;
  Serial.printf("buttonState = %i\n",buttonState);
}

// This function will be called when the button1 was pressed 2 times in a short timeframe (a double click)
void doubleclick1() {
  Serial.printf("Button 1 doubleclick.\n");
  blinker = !blinker;
  Serial.printf("blinker = %i\n",blinker);
}

// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.printf("Button 1 longPress start\n");
}

// This function will be called often, while the button1 is pressed for a long time.
void longPress1() {
  Serial.printf("Button 1 longPress...\n");
  delay(250);
}

// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStop1() {
  Serial.printf("Button 1 longPress stop\n");
}
