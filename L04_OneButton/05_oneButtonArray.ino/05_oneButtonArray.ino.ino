/*
 * Project: Using OneButton library - introducing an array
 * Description: Introduct Students to OneButton Library using 1 button and an array
 * Author: 
 * Date: 
 */

// Setup OneButton on pin 23


// LED pin configure
int ledPin = 5;
int ledPin2 = 6;
int ledPin3 = 7;
int ledArray[] = {ledPin, ledPin2, ledPin3};

boolean buttonState = LOW;

int n = sizeof(ledArray);      // counter for the Array
int j = 0;                     // variable for which LED to light

void setup() {


} 

void loop() {
  // keep watching the push buttons:
  button1.tick();
}


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time (and no 2. button press followed).
void click1() {
  Serial.println("Button 1 click.");
  buttonState = !buttonState;
  Serial.print("buttonState = ");
  Serial.println(buttonState);
  if (buttonState == LOW) digitalWrite(ledArray[j], LOW);
  else digitalWrite(ledArray[j], HIGH);
  
} // click1
