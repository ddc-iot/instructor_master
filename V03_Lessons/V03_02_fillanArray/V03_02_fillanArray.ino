/*
 * Project: V03_02_fillanArray
 * Description: Practice using Arrays
 * Author: Brian Rashap
 * Date: 27-MAR-2020
 */

/* ASSIGNMENT
 *  We are going to practice and using Arrays
 *  For this assignment you'll need our four individual NeoPixels
 *  
 *  Try to keep the void loop() portion of this code short by using functions.
 *  
 *  Create an array of integers called pixelSequence. It's size should be 20.
 *  In each interation, 
 *    1) Generate a random number between 0 and 3, inclusive
 *    2) Store the Pixel that was lit up in pixelSequence
 *    3) Light up the appropriate pixel with its associated color for 
 *       the previous and current random numbers
 *          Pixel 0 - Blue
 *          Pixel 1 - Yellow
 *          Pixel 2 - Red
 *          Pixel 3 - Green
 * 
 *  For example:
 *    Iteration 1 - if the random number is 1, light up Pixel 1 (Yellow)
 *    Iteration 2 - if the random number is 3, light up Pixel 1 (Yellow), and then 
 *                  light up Pixel 3 (Green)
 *    Iteration 3 - number is 0 then show sequence Pixel 1 (Yellow), Pixel 3 (Green), 
 *                  Pixel 0 (Blue)
 *    
 *  Each pixel should remain lit for 1 second, turn off and then go to the next pixel.
 *  Run through 20 iterations and then restart with a new sequence.
 *  
 *  
 */

#include <Adafruit_NeoPixel.h>
#include <colors.h>
#define LED_PIN     17

// attach the input of LED string to pin 20
#define NUM_PIXELS   16

Adafruit_NeoPixel pixels(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int simonArray[20];
int i;
int nextColor;

void setup() {
  pixels.begin();
  pixels.clear();

  Serial.begin (9600);
  delay(100);
  Serial.println ("Ready to Go");
}

void loop() {

for(i=0;i<20;i++) {
  simonArray[i] = random(0,4);
  displaySimon(simonArray,i+1);
  delay(1000);  
  }
  
for(i=0;i<20;i++) {
  simonArray[i]=0;
  }
}

void displaySimon(int simon[20], int n) {
  int j;
  for(j=0;j<n;j++){
    pixels.clear();
    switch(simon[j]) {
      case 0:
        pixels.setPixelColor(0,blue);
        break;
    case 1:
        pixels.setPixelColor(1,yellow);
        break;
    case 2:
        pixels.setPixelColor(2,green);
        break;
    case 3:
        pixels.setPixelColor(3,red);
        break;
    }
    pixels.show();
    delay(1000);
    pixels.clear();
    pixels.show();
    delay(500);
  }
}
  
