/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L15_Memory/L15_02_RetrieveShow/src/L15_02_RetrieveShow.ino"
/*
 * Project L15_02_RetrieveShow
 * Description: Learn to retrieve data from EEPROM and recontruct Hex from RGB
 * Author: Brian Rashap
 * Date: 04-AUG-2021
 */

#include "neopixel.h"

void setup();
void loop();
void ring(int neoColor,int neoBright);
int colorGenerator(uint8_t r, uint8_t g, uint8_t b);
#line 10 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L15_Memory/L15_02_RetrieveShow/src/L15_02_RetrieveShow.ino"
const int PIXEL_PIN=D2;
const int PIXEL_COUNT=64;
Adafruit_NeoPixel pixel(PIXEL_COUNT, PIXEL_PIN, WS2812B);

// **** Declare Variables **** //
byte red,green,blue;
int color, brightness;

void setup() {
  pixel.begin();
  brightness = 31;

  red = EEPROM.read(0x42);
  green = EEPROM.read(0x43);
  blue = EEPROM.read(0x44);

  color = colorGenerator(red,green,blue);
  ring(color,brightness);
}


void loop() {}

void ring(int neoColor,int neoBright) {
  int i;

  pixel.setBrightness(neoBright);
  for(i=0;i<PIXEL_COUNT;i++) {
    pixel.setPixelColor(i,neoColor);
  }
  pixel.show();
}

int colorGenerator(uint8_t r, uint8_t g, uint8_t b) {

  int hexColor;

  hexColor = (r<<16) | (g<<8) | b;
  return hexColor;
}