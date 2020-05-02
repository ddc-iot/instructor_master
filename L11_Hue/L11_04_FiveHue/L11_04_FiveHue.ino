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

int buttonPin = 23;
boolean activated = true;
int bulb;
long color;

unsigned long lastmillis = -10000;
unsigned int elapse;

bool onoff = false;
bool last = HIGH;
bool buttonstate;
 
IPAddress ip(172,16,0,28);  // Teensy IP


void setup()
{
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);

  
  Serial.begin(9600);
  Ethernet.begin(mac,ip);
  delay(2000);
  Serial.print("LinkStatus: ");
  Serial.println(Ethernet.linkStatus());

  pinMode(buttonPin,INPUT);
  delay(2000);
  Serial.println("Ready.");

  color = 0;
}

void loop() 
{ 
    buttonstate = digitalRead(buttonPin);

    if(buttonstate !=last)
    {
      if (buttonstate == HIGH) {
        onoff = !onoff;
      }
      last = buttonstate;
      Serial.print("On/Off = "); Serial.println(onoff);
    }
    
    elapse = millis()-lastmillis;
    if(onoff==true && elapse > 1000) {
      Serial.println(" - activated");
      //delay(500);
      activated = true;
      bulb = random(1,6);
      lastmillis = millis();
      setHue(bulb,activated, HueRainbow[color]);
      color++;
    }  

  if(onoff==false && activated == true) {
      Serial.println(" - DEactivated");
      //delay(500);
      activated = false;
      for (bulb=1;bulb<=5;bulb++) {
        setHue(bulb,activated,0);
      }  
  }
  delay(1000);
  if (color>6) {
    color = 0;
  }
}
