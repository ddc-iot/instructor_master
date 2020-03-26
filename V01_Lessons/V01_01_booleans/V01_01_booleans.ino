/*
 * Project: V1_1_booleans
 * Description: learn to use boolean variable and operators
 * Auther: Brian Rashap
 * Date: 26-MAR-2020
 */

 /* ASSIGNMENT 
  *  You will need two buttons and four neopixels for today's assignment 
  *  If you do not have two buttons, please see Section 1.2.1 of iot_virtual.pdf for for how to fake a button.
  *  
  *  For this assignment you will be using digitalRead. Do not use oneBUtton.
  *  FOr your button states, you should use the bool variable-types (not int)
  *  
  *  Light up the four neopixels with the following:
  *     Pixel 1 if niether button is pressed
  *     Pixel 2 if both buttons are pressed (Logical AND)
  *     Pixel 3 if either button is pressed (Logical OR)
  *     Pixel 4 if only one button (could be either) is pressed (Logical NOT)
  *  
  */

#include <Adafruit_NeoPixel.h>
#include <colors.h>

// Set-up Neopixel object

const int PIN=17;
const int NUMPIXELS=16;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int pin1 = 23;
const int pin2 = 16;
bool buttonState1;
bool buttonState2;


void setup() {
  Serial.begin(9600);
  while(!Serial);

  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  
  pixels.begin();
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();
}

void loop() {
  buttonState1 = digitalRead(pin1);
  buttonState2 = digitalRead(pin2);

  if((buttonState1==false) && (buttonState2==false)){
    pixels.setPixelColor(0,blue); 
  }
  else {
    pixels.setPixelColor(0,black);
  }

  if((buttonState1==true) && (buttonState2==true)){
    pixels.setPixelColor(1,lime); 
  }
  else {
    pixels.setPixelColor(1,black);
  }

  if((buttonState1==true) || (buttonState2==true)){
    pixels.setPixelColor(2,purple); 
  }
  else {
    pixels.setPixelColor(2,black);
  }

  if(((buttonState1==true) || (buttonState2==true)) && buttonState1!=buttonState2) {
    pixels.setPixelColor(3,red); 
  }
  else {
    pixels.setPixelColor(2,black);
  }
  
  pixels.show();     // Send the updated pixel colors to the hardware.
}
