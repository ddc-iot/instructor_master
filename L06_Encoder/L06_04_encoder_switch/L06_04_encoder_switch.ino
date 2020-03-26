/*
 * Project: encorder_NeoPixel
 * Description: Use Encoder to control NeoPixel ring
 * Author: Brian Rashap
 * Date 11-Feb-2020
 */

/* Wiring Instructions
 *  A = Pin 2
 *  B = Pin 3
 *  C = GND
 *  SW = Pin 20
 *  R = Pin 21
 *  G = Pin 22
 *  GND = GND
 *  there is one pin with no wiring
 *  
 *  Wire the first NeoPixel's D_in to Pin 17
 */

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
bool encoder_sw;
bool last_sw = false;
bool onoff = false;
const int encoderPin = 20;
const int greenPin = 21;
const int redPin = 22;
 

void setup() { 
  Serial.begin(9600);
  while(!Serial);
  scale = numenc / numpix; 
  
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(63);
  pixels.show();  
  Serial.println("Push encoder button to turn on/off");
  Serial.println("When on, turn encoder to light up ring");

  pinMode(encoderPin, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  encoder_sw = digitalRead(encoderPin);
  delay(50);
  if (encoder_sw != last_sw) {
    if (encoder_sw == false) {
      onoff = !onoff;
    }
  }
  last_sw = encoder_sw;

  if (onoff == false) {
    pixels.clear();
    pixels.show();
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
  }
  else {
    lightpixels();
    digitalWrite(greenPin,LOW);
    digitalWrite(redPin,HIGH);
  }
}

void lightpixels() {
  pixels.clear();
  //pixels.setPixelColor(0,lime);
  pixels.show();
  
  newPosition = myEnc.read();
  encoderPosition = (newPosition/scale);

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
