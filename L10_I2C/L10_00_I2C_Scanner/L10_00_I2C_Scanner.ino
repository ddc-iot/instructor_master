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
    Serial.printf("Wire transmission end returned: %d \n",Wire.endTransmission());
    if (Wire.endTransmission () == 0)
      {
      Serial.printf("Found address: %02d (0x%02X) \n",i,i);  
      count++;
      delay (1);
      } 
  }
  Serial.printf("Done: Found %d device(s). \n",count);
}  

void loop() {}   // empty
