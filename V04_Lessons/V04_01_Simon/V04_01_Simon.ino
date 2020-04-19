/*
 * Project: V04_01_Simon
 * Description: The Simon Game
 * Author: Brian Rashap
 * Date: 29-MAR-2020
 */

/* ASSIGNMENT
 *  Now that you have utilzied Arrays in the FillanArray and UserArray
 *  assignments, you have the building blocks to create the same Simon
 */

#include <Adafruit_NeoPixel.h>
#include <colors.h>

#define LED_PIN     17
#define NUM_PIXELS   16
Adafruit_NeoPixel pixels(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int simonArray[20];     // array holding Simon's random colors
int userArray[20];      // array holding user inputs from the buttons
int i;                  // an index
int k;                  // an index
bool lose;              // boolean set to true if incorrect color entered
int setMax = 20;        // number of interations before user wins

const int bluebutton = 23;
const int yellowbutton = 16;
const int greenbutton = 15;
const int redbutton = 8;

void setup() {
  pixels.begin();
  pixels.clear();

  Serial.begin (9600);
  delay(100);
  Serial.println ("Ready to Go");

  pinMode(bluebutton,INPUT);
  pinMode(yellowbutton,INPUT);
  pinMode(greenbutton,INPUT);
  pinMode(redbutton,INPUT);
  
  randomSeed(analogRead(0));          // use floating input to seed the random number generator
  Serial.print("Random Seed = ");
  Serial.println(analogRead(0));

  i=0;
  lose = false;
}

void loop() {

pixels.clear();
pixels.show();
delay(1500);
simonArray[i] = random(0,4);          // add random color to simonArray
displaySimon(simonArray,i+1);         // display sequence on neoPixels for user to follow

for(k=0;k<i+1;k++) {                  // for loop that has user follow all the colors displayed above
  userArray[k] = -1;                  // initialize userArray element to an invalid entry
  while(userArray[k]==-1) {           // while element is still invalid, wait for user input from getinput()
    userArray[k]=getinput();
    }
  delay(1000);
  Serial.print("Button ");
  Serial.print(userArray[k]);
  Serial.println(" was pressed");
  if(userArray[k]!=simonArray[k]) {   // compare user input to corresponding element in simonArray
    Serial.println("You loose!");
    lose=true;
    break;                            // if user enters invalid entry, break out of FOR loop 
    }
    else {
      Serial.println("Correct");
    }
}

if(i==setMax-1 || lose==true) {      // if user reaches max or enters invalid entry then reset game
  displayReset(lose);
  lose=false;
  for(k=0;k<20;k++) {
   simonArray[k]=0;
   i=0;
   }
  }
  else {
    i++;
    }
}

void displaySimon(int simon[20], int n) {
  int j;
  for(j=0;j<n;j++){
    pixels.clear();
    switch(simon[j]) {
      case 0:
        pixels.setPixelColor(15,blue);        // note, my pixels are hooked up after the PixelRing, so they are 15->12 instead of 0->3
        break;
    case 1:
        pixels.setPixelColor(14,yellow);
        break;
    case 2:
        pixels.setPixelColor(13,green);
        break;
    case 3:
        pixels.setPixelColor(12,red);
        break;
    }
    pixels.show();
    delay(1000);
    pixels.clear();
    pixels.show();
    delay(500);
  }
}

int getinput() {                                 // see if a button is pressed
  int userinput=-1;                              // default, return invalid entry if no button is pressed
  if(digitalRead(bluebutton)==true) {
    userinput=0;
    Serial.println("Blue was pressed");
    pixels.setPixelColor(15,blue);
  }
  if(digitalRead(yellowbutton)==true) {
    userinput=1;
    Serial.println("Yellow was pressed");
    pixels.setPixelColor(14,yellow);  
  }
  if(digitalRead(greenbutton)==true) {
    userinput=2;
    Serial.println("Green was pressed");
    pixels.setPixelColor(13,green);  
  }
  if(digitalRead(redbutton)==true) {
    userinput=3;
    Serial.println("Red was pressed");
    pixels.setPixelColor(12,red);  
  }
  pixels.show();
  pixels.clear();
  return userinput;
}

void displayReset(bool lose) {                        // reset game after displaying message based on winning or losing
  int j;
  int thecolor;
  if(lose==true) {
    thecolor=orange;
    Serial.println("Resetting");
  }
  else {
    thecolor=green;
    Serial.println("CONGRATULATIONS - YOU WIN!!!!!");
  }
  for(j=0;j<4;j++) {                                  // flash green for winning, orange for losing
    pixels.setPixelColor(12,thecolor);
    pixels.setPixelColor(13,thecolor);
    pixels.setPixelColor(14,thecolor);
    pixels.setPixelColor(15,thecolor);
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    delay(500);
  }
  Serial.println("Let's Play Again");
}
    
  
