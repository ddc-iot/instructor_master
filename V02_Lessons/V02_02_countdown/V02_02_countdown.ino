/*
 * Project: V02_2_timer
 * Description: timer that counts down from SerialInput value
 * Auther: Brian Rashap
 * Date: 26-MAR-2020
 */

 /* ASSIGNMENT 
  *  You will need one button and the Neopixels for this assignment. 
  *  You are going to modify your timer code. 
  *     Create a countdown timer
  *     Use the SerialMonitor to input the starting value for the timer.
  *     Push the button once to start the countdown.
  *     When you get to zero, turn on or flash the NeoPixels show that time has expired
  *     Optional: write to the OLED display or use the NeoPixels to show the last 10 seconds counting down
  */
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

String inString;
int inChar;

int buttonB = 23;
int startTime;
int counterTime=0;
int elapseTime;
int remainingTime;


void setup () {
Serial.begin (9600) ;
while(!Serial);

pinMode(buttonB,INPUT);

Wire.begin();  
oled.init();                      // Initialze SSD1306 OLED display
oled.clearDisplay();              // Clear screen

Serial.println("End time to countdown from (in seconds)");
inString = ""; // ensure the string is blank to begin with
}

void loop () {

while(counterTime==0) {
  while (Serial.available() > 0) { // read serial input
  inChar = Serial.read();
  if (isDigit(inChar)) {
  inString += ( char ) inChar ; // convert incoming byte to char and add to string
  }
  if (inChar == '\n') { // '\n' represents the btye for newline (or enter )
    counterTime = inString.toInt()*1000; 
    Serial.print("Counter Time: ");
    Serial.println(counterTime);
    }
  }
}

  Serial.println("Push Button to Begin");
  while (digitalRead(buttonB)==false);
  startTime = millis();
  remainingTime = startTime;
  while(remainingTime > 0) {
    elapseTime = (millis()-startTime);
    remainingTime = counterTime - elapseTime;
    oled_write(1, int((remainingTime/1000.0)+1));
  }
  Serial.println("DONE");
  oled_write(2, 0);
  delay(10000);
}

void oled_write(int state, float theTime) {
//  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0); 
  if(state==1) {             
    oled.putString("Remaining Time");
  }
  else {
    oled.putString("DONE          ");
  }
  oled.setTextXY(1,0);              
  oled.putString(String(theTime,3));
}
