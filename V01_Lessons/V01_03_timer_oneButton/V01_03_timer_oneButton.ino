/*
 * Project: V1_3_timer
 * Description: learn to use boolean logic and while loops
 * Auther: Brian Rashap
 * Date: 26-Mar-2020
 */

 /* ASSIGNMENT 
  *  You will need one buttons and the OLED display for this assignment. It is suggested that you also write to the serial display
  *  For this assignment you will be using oneBUtton.
  *  For your button states, you should use the bool variable-types (not int)
  *  You should remind yourself of the millis() function that we used with the OLED
  *  
  *  Create a stop watch. 
  *  Push the button once to start the timer
  *  While the timer is running, display to seconds to the OLED. (i.e., 1 second, 2 seconds, 3 seconds, etc)
  *     Only display the whole second, not the milliseconds.
  *  When the button is pushed again, stop the timer
  *     Now display the final time to the OLED through the millisecond space (i.e, 3.145 seconds)
  */
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>
#include "OneButton.h"

OneButton button1(23, false);  

int startTime;
float currentTime;
int endTime;
float elapseTime;
bool buttonState = false;
 
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  button1.attachClick(click1);

  Wire.begin();  
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen
}

void loop() {
  Serial.println("Push button to start timer");
  while (buttonState==false) {
    button1.tick();   // loops and does nothing until button pressed
  }
  startTime=millis();  // sets startTime to where ever the system clock is
  Serial.println("Timer Starting...");
  buttonState = false;
  
  while (buttonState==false) {    // wait until button pressed a second time
    button1.tick();
    Serial.print("waiting to press ");
    currentTime = (millis()-startTime)/1000.0;
    oled_write(1, int(currentTime));
    Serial.println(currentTime);
  }
  
  endTime=millis();
  Serial.println("Timer Ending...");
  elapseTime = (endTime - startTime)/1000.0;
  Serial.print("The total time is: ");
  Serial.println(elapseTime);
  oled_write(2, elapseTime);
  delay(5000);
}

void oled_write(int state, float theTime) {
//  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0); 
  if(state==1) {             
    oled.putString("The Time is");
  }
  else {
    oled.putString("Final Time is");
  }
  oled.setTextXY(1,0);              
  oled.putString(String(theTime,3));
}

void click1() {
  buttonState = true;
}
