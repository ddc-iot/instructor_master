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
const int LEDPIN1 = 5;
const int LEDPIN2 = 6;
const int LEDPIN3 = 7;
const int LEDARRAY[] = {LEDPIN1, LEDPIN2, LEDPIN3};

boolean buttonState;

int n;                     // number of LEDs, to be set in void setup()
int j;                     // index variable for which LED to light

void setup() {

  Serial.begin(9600);
  while (!Serial); 

  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  pinMode(LEDPIN3, OUTPUT);

  n = sizeof(LEDARRAY)/4;      // counter for the Array
  buttonState = false;


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
    Serial.print(LEDARRAY[j]);
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
    digitalWrite(LEDARRAY[j], LOW);
  }
  else {
    digitalWrite(LEDARRAY[j], HIGH);
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
    digitalWrite(LEDARRAY[n], HIGH);
    delay(200);
    digitalWrite(LEDARRAY[n], LOW);
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
    digitalWrite(LEDARRAY[n], HIGH);
    delay(200);
    digitalWrite(LEDARRAY[n], LOW);
  }
} // longPressStop1
