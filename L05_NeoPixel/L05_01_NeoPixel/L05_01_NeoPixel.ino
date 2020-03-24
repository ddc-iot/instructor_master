/* 
 *  Project: Neopixel
 *  Description: Learn to Use Neopixels
 *  Author: Brian Rashap
 *  Date: 4-Mar-2020
 */

#include <Adafruit_NeoPixel.h>

// Set-up Neopixel object

const int PIN=17;
const int NUMPIXELS=16;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int pixeldelay=2000;
const int start_pixel = 0; // the first pixel is 0
int i = 0;                 // counter variable

void setup() {
  Serial.begin(9600);
  delay(500); // pause for Serial Monitor, but still work without Monitor
  Serial.println("Starting NeoPixel");

  //Initialize NeoPixels
  pixels.begin();
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();

  for(i=start_pixel; i<NUMPIXELS; i++) { 

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    Serial.print("Lighting up pixel ");
    Serial.println(i);
    // pixels.setPixelColor(i,63,63,0);
    pixels.setPixelColor(i,random(0,63),random(0,32),random(0,63));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(pixeldelay); // Pause before next pass through loop
  }
}
