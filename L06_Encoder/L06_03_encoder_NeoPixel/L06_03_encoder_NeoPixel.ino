/*
 * Project: encorder_NeoPixel
 * Description: Use Encoder to control NeoPixel ring
 * Author: Brian Rashap
 * Date 11-Feb-2020
 */

// Wire Pins 2 and 3 of the Teensy to the A and B terminals of the Encoder
// The C (Common) terminal of the Encoder should be connected to Ground
// Wire the Neopixels as usual

#include <Encoder.h>
#include <Adafruit_NeoPixel.h>
#include <colors.h>

#define PIX_PIN 17
#define PIN_COUNT 16
Adafruit_NeoPixel pixels=Adafruit_NeoPixel(PIN_COUNT, PIX_PIN, NEO_GRB + NEO_KHZ800);

Encoder myEnc(3,2);

const int numenc = 96;   // number of positions on Encoder
const int numpix = 12;   // number of pixels in the Ring
int oldPosition  = -999;
int newPosition;
int scale;


int encoderPosition;

 

void setup() { 
  Serial.begin(9600);
  delay(500);
  scale = numenc / numpix; 
  
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(63);
  pixels.show();  
  Serial.println("Turn encoder to light up ring");
}

void loop() 
{
  pixels.clear();
  //pixels.setPixelColor(0,lime);
  pixels.show();
  
  newPosition = myEnc.read();
  encoderPosition = (newPosition/scale);
  Serial.println(encoderPosition);

  if (encoderPosition < 0) {                 // bound the encoder to the bottom pixel
    myEnc.write(0);   // set encoder to 0
  }
  
  if (encoderPosition >  numpix) {           // bound the encoder to the top pixel
    myEnc.write(numenc);
    encoderPosition = numpix;
  }

  if (encoderPosition > 0) {                // ensure the number of pixels filled it greater than 0
    pixels.fill(lime, 0, encoderPosition); // light up the first pixel (0) when encoder is at 1
    pixels.show();
  }
  

}
