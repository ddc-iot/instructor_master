/*
 * Project: I2C_Scanner
 * Description: scan the I2C bus for devices
 * Author: Brian Rashap
 * Date: 10-Mar-2020
 */

#include <Wire.h>

byte count = 0;
byte i;

void setup() {
  Serial.begin (9600);
  while (!Serial);
  Serial.println ("Begin I2C scanning");
 
  Wire.begin();
  for (i = 0; i <= 127; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);
      } 
  }
  
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  

void loop() {}   // this code has no loop, as it only runs once
