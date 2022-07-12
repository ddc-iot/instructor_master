/* 
 *  Project: Colorheader
 *  Description: Learn to Use Header Files
 *  Author: Brian Rashap
 *  Date: 4-Mar-2020
 */

#include <Adafruit_NeoPixel.h>

// Set-up Neopixel object

const int PIN=17;
const int NUMPIXELS=16;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


const int STARTPIXEL = 0; // the first pixel is 0
int i = 0;                 // counter variable
int pixeldelay=1000;
int colorpix;

void setup() {
  Serial.begin(9600);
  delay(500);         // pause for Serial Monitor, but still work without Monitor
  Serial.println("Starting NeoPixel");

  //Initialize NeoPixels
  pixels.begin();
  pixels.setBrightness(63);
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();

  colorpix = random(0x000000,0xFFFFFF);
  for(i=STARTPIXEL; i<NUMPIXELS; i++) { 
    Serial.print("Lighting up pixel ");
    Serial.println(i);
    pixels.setPixelColor(i,colorpix);  
    pixels.show();     // Send the updated pixel colors to the hardware.
    delay(pixeldelay); // Pause before next pass through loop
  }
}
