/*
 * Project: NeoPixel Light String 
 * Description: Use 60 LED string to demonstrate NeoPixel
 * Author: Brian A Rashap
 * Date: 5-Dec-2019
 */

#include <Adafruit_NeoPixel.h>
#include <colors.h>

const int LED_PIN=17;
const int NUM_PIXELS=60;

Adafruit_NeoPixel pixels(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// i and j are used to control the loops;
int i;
int j;

// r, g, and b are will be random numbers to control the color of the RGB LEDs.
int r;
int g;
int b;

const int RAINBOW[7]={red,orange,yellow,green,blue,indigo,violet};

int pixDelay1 = 50;
int pixDelay2 = 500;
int pixDelay3 = 250;

void setup() {
  Serial.begin (9600);
  delay(100);
  Serial.println ("Ready to Go");  

  pixels.begin();
  pixels.setBrightness(63); // dull the pixels a bit
  pixels.clear(); 
}


void loop() {

  pixels.fill(maize,0,60);
  delay(1000);

  for (j = 0; j < 5; j++) {  // run a light up and down the LED string 5 times
    RNDpixels();
  }

  rainbow();
  GoBlue();

}

void RNDpixels() {
  
  // create a random RGB value for the LED for each run
  r = random(0,255);
  g = random(0,255);
  b = random(0,255);
  Serial.printf("Color: %i, %i, %i\n",r,g,b);
  
  // run the color up and then down the LED string once for each run of the loop - 5 times with different colors
  for (i = 0; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i,r,g,b);
    pixels.show();
    delay(pixDelay1);
    pixels.setPixelColor(i,0,0,0);
    pixels.show();
  }

  for (i = (NUM_PIXELS-1); i >= 0; i--) {
    pixels.setPixelColor(i,r,g,b);
    pixels.show();
    delay(pixDelay1);
    pixels.setPixelColor(i,0,0,0);
    pixels.show();
  }
}

// Light up the first 7 LEDs with a rainbow (ROYGBIV)
void rainbow() { 
  int x,i;
  for (x=0; x < (NUM_PIXELS-1); x = x + 12){
    for(i=0;i<7;i++){
      pixels.setPixelColor(x+i ,RAINBOW[i]);
      pixels.show();
      delay(pixDelay2);
    }
    for(i=6;i>0;i--){
      pixels.setPixelColor(x+(12-(i-1)),RAINBOW[i]);
      pixels.show();
      delay(pixDelay2);
    }
  }
}

void GoBlue() {

  // Run a pair of Maize and Blue lights down the string - Go Blue!!!
  
  for (i = 0; i < (NUM_PIXELS-1); i++) {
    pixels.setPixelColor(i ,0x00274C);
    pixels.setPixelColor(i+1 ,0xFFCB05);
    pixels.show();
    delay(pixDelay3);
    pixels.setPixelColor(i ,black);
    pixels.setPixelColor(i+1 ,black);
    pixels.show();
  }
}

/*
void rainbow() {
  // Light up the first 7 LEDs with a rainbow (ROYGBIV)
  int x = 0;
  for (x=0; x < (NUM_PIXELS-1); x = x + 12){
  
  pixels.setPixelColor(x+0 ,red);   // Red
  pixels.show();
  delay(pixDelay2); 
  pixels.setPixelColor(x+1 ,orange);   // Orange
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+2 ,yellow);  // Yellow
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+3 ,green);   // Green
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+4 ,blue);   // Blue
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+5 ,indigo);  // Indigo
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+6 ,violet);  // Violet
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+7 ,19, 0, 33);  // Indigo
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+8 ,0, 0, 63);   // Blue
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+9,0, 63, 0);   // Green
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+10,63, 63, 0);  // Yellow
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+11,63, 31, 0);   // Orange
  pixels.show();
  }
}*/
