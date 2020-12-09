/*
 * Project AMS5812
 * Description: NCD Differential Pressure Sensor 
 * Author: Brian Rashap
 * Date: 22-APR-2020
 */

// AMS5812 I2C address is 0x78(120)
#define Addr 0x78

uint8_t data[4];
int16_t ptemp; 
int16_t temp;

float pressure = 0.0;
float cTemp = 0.0;
float fTemp = 0.0;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  delay(300);
}

void loop()
{
  // Request 4 bytes of data
  Wire.requestFrom(Addr, 4);

  // Read 4 bytes of data
  // pressure msb, pressure lsb, temp msb, temp lsb
  if (Wire.available() == 4)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
    data[2] = Wire.read();
    data[3] = Wire.read();
  } 

  // Convert the data
  ptemp = data[0]<<8 | data[1];
  temp = data[2]<<8 | data[3];

  pressure = ((ptemp - 3277.0) / ((26214.0) / 5.0));
  cTemp = ((temp - 3277.0) / ((26214.0) / 110.0)) - 25.0;
  fTemp = (cTemp * 1.8 ) + 32;

  Serial.printf("Temperature in Celsius: %0.2f \n", cTemp);
  Serial.printf("Temperature in Fahrenheit: %0.2f \n",fTemp);
  Serial.printf("Pressure in psi: %0.2f, Raw Reading: %i\n", pressure,ptemp);
  Particle.publish("Pressure", String(pressure));
  delay(10000);
}