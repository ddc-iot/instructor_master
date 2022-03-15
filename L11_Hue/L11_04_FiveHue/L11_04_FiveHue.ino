/*
 *  Project:      Hue ColorWheel HeaderExample
 *  Description:  Example code for Hue Lights in IoT Classroom using Hue IoT LIbrary
 *  Authors:      Brian Rashap
 *  Date:         1-May-2020
 */
#include <SPI.h>
#include <Ethernet.h>
#include <mac.h>
#include <hue2.h>

int buttonPin = 23;
boolean activated = true;
int bulb;
long color;

unsigned long lastmillis = -10000;
unsigned int elapse;
bool onoff = false;
bool last = HIGH;
bool status;
byte thisbyte;
bool buttonstate;
const int numBulbs=6;
 
//IPAddress ip(192,168,1,12);  // Teensy IP


void setup()
{
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  Serial.begin(9600);

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
      bulb = random(1,numBulbs+1);
      lastmillis = millis();
      setHue(bulb,activated, HueRainbow[color],random(32,265),255);
      color++;
    }  

  if(onoff==false && activated == true) {
      Serial.println(" - DEactivated");
      //delay(500);
      activated = false;
      for (bulb=1;bulb<=numBulbs;bulb++) {
        setHue(bulb,activated,0,0,0);
      }  
  }
  delay(1000);
  if (color>numBulbs+1) {
    color = 0;
  }
}
