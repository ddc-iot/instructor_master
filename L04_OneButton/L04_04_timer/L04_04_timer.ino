/*
 * Project: Stopwatch and Timer
 * Description: Learn Serial Input
 * Author: Brian A Rashap
 * Date: 06-JAN-2021
 */
#include <OneButton.h>
OneButton button(23,false);

bool timer, start;
unsigned int currentTime, startTime, stopTime, elapseTime, lastTime;
unsigned int timerTime;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  button.attachClick(click);
  button.attachDoubleClick(doubleClick);

  timer = false;
  start = false;
  lastTime = 0;

  Serial.printf("DoulbeClick to switch between Stop Watch and Timer\n");
  Serial.printf("Single Click to Start / Stop\n");
}

void loop() {
  while(!start) {
    button.tick();
  }
  startTime = millis();
  if(!timer) {
    while(start) {
      button.tick();
      currentTime = millis();
      elapseTime = currentTime-startTime;
      if(currentTime-lastTime > 1000) {
        Serial.printf("Time = %03i seconds\n",elapseTime/1000);
        lastTime = currentTime;
      }
    }
    currentTime = millis();
    elapseTime = currentTime-startTime;
    Serial.printf("Stop Time = %0.3f seconds\n",elapseTime/1000.0);
  }
  else {
    elapseTime = 0;
    delay(50);
    while(elapseTime < timerTime) {
      button.tick();
      currentTime = millis();
      elapseTime = currentTime-startTime;
      if(currentTime-lastTime > 1000) {
        //Serial.printf("%i, %i, %i, %i\n",timerTime,startTime,currentTime,elapseTime);
        Serial.printf("Time = %03i seconds\n",((timerTime-elapseTime)/1000)+1);
        lastTime = currentTime;
      }
    }
    Serial.printf("DONE\n");
    start=false;
    Serial.printf("Resetting timer at %i seconds\n",timerTime/1000);
    Serial.printf("Single click to start timer\n");
  }
}

void click() {
  start = !start;
}

void doubleClick() {
  String timerInput;
  
  timer = !timer;
  if(timer) {
    Serial.printf("Switching to Timer\n");
    Serial.printf("Enter Countdown Time in seconds\n");
    timerInput="";
    while(timerInput=="") {
      timerInput = Serial.readStringUntil('\n');
    }
    timerTime = timerInput.toInt()*1000;;
    Serial.printf("Starting timer at %i seconds\n",timerTime/1000);
    Serial.printf("Single click to start timer\n");
  }
  else {
    Serial.printf("Switching to Stop Watch\n");
    Serial.printf("Single click to start stop watch\n");
  }
  
}
