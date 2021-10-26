/*
 * Project: WEMO with PullUp
 * Description: Control smart lighting switch from a button
 * Author: Brian A Rashap
 * Date: 24-Mar-2020
 */

 /*
  * Ethernet Port Wiring
  * 3.3V to Teensy 3.3V
  * GND to Teensy GND
  * MISO to Teensy DI (Pin 12)
  * MOSI to Teensy DO (Pin 11)
  * SCLK to Teensy SCK (Pin 13)
  * SCNn to Teensy Pin 10 (for Chip Select)
  * RSTn to Teensy Pin 9
  * INTn and NC (No Connection) not connected
  */

#include <SPI.h>
#include <OneButton.h>
#include <wemo.h>
#include <mac.h>
#include "IoTTimer.h"


EthernetClient client;
OneButton button(23,false);
IoTTimer timer;

const int wemo = 0;
const int sleepTime = 10000;

bool status;   //user to ensure port openned correctly
byte thisbyte; //used to get IP address

bool desiredState, actualState;

void setup() {
  //initialize ethernet port and uSD module to off
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);

  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  //Open Serial Communication and wait for port to open:
  Serial.begin(9600);
  while (!Serial);

  Serial.printf("Starting Program:\n");

  //Start ethernet connection
  status = Ethernet.begin(mac);
  if (!status) {
    Serial.printf("failed to configure Ethernet using DHCP \n");
    //no point in continueing 
    while(1);
  }
    
  //print your local IP address
  Serial.print("My IP address: ");
  for (thisbyte = 0; thisbyte < 3; thisbyte++) {
    //print value of each byte of the IP address
    Serial.printf("%i.",Ethernet.localIP()[thisbyte]);
    }
  Serial.printf("%i\n",Ethernet.localIP()[thisbyte]);

  //onebutton config
  button.attachClick(click1);
  actualState = false;
}

void loop(){
  button.tick();
  if (desiredState && !actualState) {
    switchON(wemo);
    actualState=true;
  }

  if (!desiredState && actualState && timer.isTimerReady()) {
    switchOFF(wemo);
    actualState=false;
  }
}

void click1() {
  desiredState = !desiredState;
  timer.startTimer(sleepTime);
  Serial.printf("desiredState = %i\n",desiredState);
}
