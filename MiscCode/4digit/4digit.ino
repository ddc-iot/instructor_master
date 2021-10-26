/*
 * Project: 4digit
 * Description: Simple Countdown
 * Author: Brian Rashap
 * Date: 29-JUN-2021
 */
#include "TM1637.h"


TM1637 tm1637(1,0);

const unsigned int starter =  99 * 60 * 1000;
int8_t TimeDisp[] = {0x00,0x00,0x00,0x00};
unsigned int startTime, countTime, minute, second;

void setup() {
  tm1637.set(5);
  tm1637.init();
  countTime = -9999;
}

void loop() {
  if(countTime < 500) {
    countTime = starter;
    startTime = millis();  
  }
  countTime = starter - (millis() - startTime);
  minute = countTime / 60000;
  second = (countTime % 60000)/1000;

  TimeDisp[0] = minute / 10;
  TimeDisp[1] = minute % 10;
  TimeDisp[2] = second / 10;
  TimeDisp[3] = second % 10;

  tm1637.display(TimeDisp);
}
