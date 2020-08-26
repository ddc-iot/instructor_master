/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/NCD/MQ09/src/MQ09.ino"
/*
 * Project MQ09
 * Description: Sample Code for Using NCD.io MQ09
 * Author: Brian Rashap
 * Date: 21-APR-2020
 */


// ADC121C_MQ9 I2C address is 0x50(80)
void setup();
void loop();
uint16_t getData(int address);
#line 10 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/NCD/MQ09/src/MQ09.ino"
#define Addr 0x50

uint16_t raw_adc;
float ppm;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  raw_adc = getData(Addr);
  ppm = (1000 / 4096.0) * raw_adc + 10;
  Serial.printf("CO conc = %0.2f \n",ppm);
  delay(60000);
}

uint16_t getData(int address) {
  uint8_t data[2] = {0,0};
  uint16_t rawACD;
  
  // Start I2C transmission
  Wire.beginTransmission(address);
  // Select data register
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 2 bytes of data
  Wire.requestFrom(address, 2);

  // Read 2 bytes of data
  // raw_adc msb, raw_adc lsb
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  // Convert the data to 12-bits
  rawACD = data[0]<<8 | data[1];
  return rawACD;
}
