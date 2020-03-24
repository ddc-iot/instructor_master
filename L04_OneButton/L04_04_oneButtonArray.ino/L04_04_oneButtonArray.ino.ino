/*
 * Project: Using OneButton library - introducing an array
 * Description: Introduct Students to OneButton Library using 1 button and an array
 * Author: Brian A Rashap
 * Date: 13-Dec-2019
 */

#include "OneButton.h"

// Setup OneButton on pin 23
OneButton button1(23, false); 

// LED pin configure
int ledPin = 5;
int ledPin2 = 6;
int ledPin3 = 7;
int ledArray[] = {ledPin, ledPin2, ledPin3};

boolean buttonState = LOW;

int n;                     // number of LEDs, to be set in void setup()
int j;                     // index variable for which LED to light

void setup() {

  Serial.begin(9600);
  while (!Serial); 

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  n = sizeof(ledArray)/4;      // counter for the Array



  // link the button 1 functions.
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);
  button1.attachDuringLongPress(longPress1);
  button1.setClickTicks(250);
  button1.setPressTicks(2000);

  Serial.println("Starting oneButtonArray...");
  Serial.print("LEDs are attached to pins: ");
  for (j = 0; j<n; j++) {
    Serial.print(ledArray[j]);
    if (j < (n-1)) {
      Serial.print(",");
    }
  }
  Serial.println();
  j = 0;   // reset index to 0;
} 

void loop() {
  button1.tick();
  if (buttonState == LOW) {
    digitalWrite(ledArray[j], LOW);
  }
  else {
    digitalWrite(ledArray[j], HIGH);
  }
}


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time
void click1() {
  Serial.println("Button 1 click.");
  buttonState = !buttonState;
  Serial.print("buttonState = ");
  Serial.println(buttonState);  
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
  j++;
  if (j > 2) j = 0;
  Serial.print("j = ");
  Serial.println(j);
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("Button 1 longPress start");
  for (n = 0; n<3; n++) {
    digitalWrite(ledArray[n], HIGH);
    delay(200);
    digitalWrite(ledArray[n], LOW);
  }
} // longPressStart1


// This function will be called often, while the button1 is pressed for a long time.
void longPress1() {
  Serial.println("Button 1 longPress...");
} // longPress1


// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStop1() {
  Serial.println("Button 1 longPress stop");
  for (n = 2; n>=0; n--) {
    digitalWrite(ledArray[n], HIGH);
    delay(200);
    digitalWrite(ledArray[n], LOW);
  }
} // longPressStop1
