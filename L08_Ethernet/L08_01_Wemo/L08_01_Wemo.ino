/*
 * Project: WEMO with PullUp
 * Description: Control smart lighting switch from a button
 * Author: Brian A Rashap
 * Date: 24-Mar-2020
 */

 // Connect Ethernet port per Fritzing diagram and a button to Pin 23
 // You will need to find the IP address of your Wemo smart plug  by logining onto your router

#include <Ethernet.h>
#include <SPI.h>
#include <mac.h>
#include <wemo.h>
 
const int mywemo = 0;
int inPin = 23;
bool state = true;
bool reading;


void setup()
{
  pinMode(inPin, INPUT);
 
  Serial.begin(9600);
  Ethernet.begin(mac);
  delay(1000);
  Serial.println("connecting...");

  // print your local IP address:
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println();
}

void loop(){

   reading = digitalRead(inPin);
   
   if (reading != state){
     if (reading==true){
       switchON(mywemo);
       delay(1000);
     }else{
       switchOFF(mywemo);
       delay(1000);
     }
     state = reading;
   }
}
