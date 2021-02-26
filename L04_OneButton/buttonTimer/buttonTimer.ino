/*
 * Project: Using OneButton library
 * Description: Use oneButton to light and blink an LED
 * Author: 
 * Date: 
 */

#include "OneButton.h"
OneButton button1(23,false);
bool buttonState = false;
bool flash = false;
bool LEDon = false;
unsigned int lastTime = 0;
const int ledPin = 5;
unsigned int flashTime = 1000;

void setup() {

  Serial.begin(9600);
  pinMode(23,OUTPUT);
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
} 

void loop() {
  button1.tick();
  if (buttonState == true) {
    if (flash == false) {
      digitalWrite(ledPin,HIGH);
      Serial.println("Solid");
    }
    else {
      if (millis()-lastTime >= flashTime) {
        Serial.printf("Time = %i \n", millis()-lastTime);
        if (LEDon == false) {
          digitalWrite(ledPin,HIGH);
          LEDon = true;
          lastTime = millis();
          Serial.printf("On is %i \n",LEDon);
        }
        else {
          digitalWrite(ledPin,LOW);
          LEDon = false;
          lastTime = millis();
          Serial.printf("On is %i \n",LEDon); 
        }
      }
    }
  }
  else {
    digitalWrite(ledPin,LOW);
    Serial.println("Off");
  }
} 

void click1() {
  buttonState = !buttonState; 
  Serial.println("Click");
}

void doubleclick1() {
  flash = !flash;
  Serial.println("DoubleClick");
} 
