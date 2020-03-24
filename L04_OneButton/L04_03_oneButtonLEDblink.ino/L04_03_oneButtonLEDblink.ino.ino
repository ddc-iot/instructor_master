/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library: Solid vs Blinking LED
 * Author: Brian A Rashap
 * Date: 13-Dec-2019
 */

#include "OneButton.h"

// Setup OneButton on pin 23 and pin 16
OneButton button1(23, false); 

// LED pin configure
int ledPin = 5;
int ledDelay = 50;

bool buttonState = false;
bool flash = false;

void setup() {

  Serial.begin(9600);
  while (!Serial); 

  pinMode(ledPin, OUTPUT);

  // link the button 1 functions.
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);
  button1.attachDuringLongPress(longPress1);
  button1.setClickTicks(500);
  button1.setPressTicks(2000);

  Serial.println("Starting oneButtonLED...");
} 

void loop() {
  // keep watching the push buttons:
  button1.tick();

  if (buttonState == false) {       
    digitalWrite(ledPin, LOW);          // if buttonState false, LED is off
  }
  else {                                // else, if buttonState true, LED is on
    if (flash == false) {
      digitalWrite(ledPin, HIGH);       //    if flash false, then solid LED
    }
    else {                              //    else, if flash true, then blink LED
      digitalWrite(ledPin, HIGH);       
      delay(ledDelay);
      digitalWrite(ledPin, LOW);        //        to blink, one on/off flash each loop of void loop()
      delay(ledDelay);
    }
  } 
}


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time 
void click1() {
  Serial.println("Button 1 click.");
  buttonState = !buttonState;
  Serial.print("buttonState = ");
  Serial.println(buttonState); 
}

// This function will be called when the button1 was pressed 2 times in a short timeframe.
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
