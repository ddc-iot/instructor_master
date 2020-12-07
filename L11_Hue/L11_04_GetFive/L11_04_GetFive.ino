/*
 *  Project:      Hue ColorWheel HeaderExample
 *  Description:  Example code for Hue Lights in IoT Classroom using Hue IoT LIbrary
 *  Authors:      Brian Rashap
 *  Date:         1-May-2020
 */
#include <SPI.h>
#include <Ethernet.h>
#include <mac.h>
#include <hue.h>

int buttonPin = 20;
boolean activated = true;
int bulb;
long color;

unsigned long lastmillis = -10000;
unsigned int elapse;
bool onoff = false;
bool last = HIGH;
bool buttonstate;
 
IPAddress ip(192,168,1,9);  // Teensy IP


void setup()
{
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);

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
  //Ethernet.begin(mac,ip);
  //delay(2000);
  Serial.print("LinkStatus: ");
  Serial.println(Ethernet.linkStatus());

  pinMode(buttonPin,INPUT);
  delay(2000);
  Serial.println("Ready.");

  color = 0;

  for (bulb=1;bulb<=5;bulb++) {
        getHue(bulb);
  }
}

void loop() {}
