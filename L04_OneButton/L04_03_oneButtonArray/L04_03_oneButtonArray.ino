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

  n = sizeof(LEDARRAY)/4;      // counter for the Array
  for(j=0;j<n;j++) {
    pinMode(LEDARRAY[j],OUTPUT);    
  }

  buttonState = false;

  // link the button 1 functions.
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);
  button1.attachDuringLongPress(longPress1);
  button1.setClickTicks(250);
  button1.setPressTicks(2000);

  Serial.printf("Starting oneButtonArray...\nLEDs are attached to pins:");
  for (j = 0; j<n-1; j++) {
    Serial.printf("%i,",LEDARRAY[j]);
  }
  Serial.printf("%i\n\n",LEDARRAY[j]);
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

void click1() {
  Serial.printf("Button 1 click.\n");
  buttonState = !buttonState;
  Serial.printf("buttonState = %i\n",buttonState); 
}

void doubleclick1() {
  Serial.printf("Button 1 doubleclick.\n");
  j++;
  if (j > 2) j = 0;
  Serial.printf("j = %i\n",j);
}


void longPressStart1() {
  Serial.printf("Button 1 longPress start\n");
  for (j = 0; j<n; j++) {
    digitalWrite(LEDARRAY[j], HIGH);
    delay(500);
    digitalWrite(LEDARRAY[j], LOW);
  }
}

void longPress1() {
  Serial.printf("Button 1 longPress...\n");
}

void longPressStop1() {
  Serial.printf("Button 1 longPress stop.\n");
  for (j = n-1; j>=0; j--) {
    digitalWrite(LEDARRAY[j], HIGH);
    delay(500);
    digitalWrite(LEDARRAY[j], LOW);
  }
}
