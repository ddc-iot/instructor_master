/*
 * Project: V02_03_switchcase
 * Description: Learn to use Switch Case
 * Auther: <your name>
 * Date: <today's date>
 */

 /* ASSIGNMENT 
  * For this assignment, you will need NeoPixels
  * Enter an integer 1, 2, or 3 from the Serial Monitor
  * Use Switch Case to create three different Neopixel patterns
  * Show each case based on what number is entered
  */
#include <Adafruit_NeoPixel.h>
#define LED_PIN     17

// attach the input of LED string to pin 20
#define NUM_PIXELS   16

Adafruit_NeoPixel pixels(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// i and j are used to control the loops;
int i;
int j;

// r, g, and b are will be random numbers to control the color of the RGB LEDs.

int r;
int g;
int b;

int const pixDelay1 = 50;
int const pixDelay2 = 500;
int const pixDelay3 = 250;

int selectmode;
char inChar;
String inString;

 
 void setup() {
  // Initialize the LED String

  pixels.begin();
  pixels.clear();

  // Initialize Serial Monitor
  
  Serial.begin (9600);
  delay(100);
  Serial.println ("Ready to Go");

  inString = "";
}

void loop() {
inString = "";
Serial.println("Select Mode 1, 2, or 3");
selectmode = 0;
while(selectmode==0) {
  while (Serial.available() > 0) { // read serial input
  inChar = Serial.read();
  if (isDigit(inChar)) {
  inString += ( char ) inChar ; // convert incoming byte to char and add to string
  }
  if (inChar == '\n') { // '\n' represents the btye for newline (or enter )
    selectmode = inString.toInt(); 
    }
  }
}

switch(selectmode) {
  case 1:
    RNDpixels();
    break;
  case 2:
    rainbow();
    break;
  case 3:
    GoBlue();
    break;
  default:
    Serial.println("Invalid Selection");
    break;
  }
}

void RNDpixels() {
  
  // create a random RGB value for the LED for each run
  pixels.setBrightness(63); // dull the pixels a bit

  r = random(0,255);
  g = random(0,255);
  b = random(0,255);

  Serial.print(r);
  Serial.print(",");
  Serial.print(g);
  Serial.print(",");
  Serial.println(b);
  
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


void rainbow() {
  // Light up the first 7 LEDs with a rainbow (ROYGBIV)
  int x = 0;
  for (x=0; x < (NUM_PIXELS-1); x = x + 12){
  
  pixels.setPixelColor(x+0 ,63, 0, 0);   // Red
  pixels.show();
  delay(pixDelay2); 
  pixels.setPixelColor(x+1 ,63, 31, 0);   // Orange
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+2 ,63, 63, 0);  // Yellow
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+3 ,0, 63, 0);   // Green
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+4 ,0, 0, 63);   // Blue
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+5 ,19, 0, 33);  // Indigo
  pixels.show();
  delay(pixDelay2);
  pixels.setPixelColor(x+6 ,37, 0, 53);  // Violet
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
}

void GoBlue() {

  // Run a pair of Maize and Blue lights down the string - Go Blue!!!
  
  for (i = 0; i < (NUM_PIXELS-1); i++) {
    pixels.setPixelColor(i ,0x00274c);
    pixels.setPixelColor(i+1 ,0xffcb05);
    pixels.show();
    delay(pixDelay3);
    pixels.setPixelColor(i ,0x000000);
    pixels.setPixelColor(i+1 ,0x000000);
    pixels.show();
  }
}
