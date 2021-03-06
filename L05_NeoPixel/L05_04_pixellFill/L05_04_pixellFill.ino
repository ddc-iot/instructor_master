/* 
 *  Project: Neopixel Fill
 *  Description: Learn to Use Header Files
 *  Author: Brian Rashap
 *  Date: 4-Mar-2020
 */

// NOTE: colors.h needs to be placed in Arduino->Libraries->colors directory
// You may need to create the colors directory in the LIbraries 

#include <Adafruit_NeoPixel.h>
#include <colors.h>

// Set-up Neopixel object

const int PIN=17;
const int NUMPIXELS=16;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


const int STARTPIXEL = 0; //  the first pixel is 0
int i = 0;                 // counter variable
int pixeldelay=1000;

void setup() {
  Serial.begin(9600);
  delay(500); // pause for Serial Monitor, but still work without Monitor
  Serial.println("Starting NeoPixel");

  //Initialize NeoPixels
  pixels.begin();
  pixels.setBrightness(255);
  pixels.clear();
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();
  delay(pixeldelay);

  for(i=STARTPIXEL;i<NUMPIXELS;i+(NUMPIXELS/6)) {
    pixel.fill(random(0x000000,0xFFFFFF),i,NUMPIXELS/6);
    delay(pixeldelay);
  }
}
