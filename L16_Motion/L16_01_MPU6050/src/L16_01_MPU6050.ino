/*
 * Project L16_01_MPU6050
 * Description: Get accleration data and convert to g's
 * Author: Brian Rashap
 * Date: 12-NOV-2021
 */

#include <math.h>

const int MPU_ADDR = 0x68;

// Declare variables
byte accel_x_h, accel_x_l, accel_y_h, accel_y_l, accel_z_h, accel_z_l;    //variables to store the individual btyes
int16_t accel_x,accel_y,accel_z;              //variable to store the x-acceleration
float a_x,a_y,a_z,a_tot;

SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected,5000);

  // Begin I2C communications
  Wire.begin();  

  // Begin transmission to MPU-6050
  Wire.beginTransmission(MPU_ADDR); 

  // Select and write to PWR_MGMT1 register
  Wire.write(0x6B);
  Wire.write(0x00); // set to 0 (wakes up MPU-6050)

  // End transmission and close connection
  Wire.endTransmission(true);
}


void loop() {
  // Set the "pointer" to the 0x3B memory location of the MPU and wait for data
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B
  Wire.endTransmission(false); // keep active.

  // Request and then read 2 bytes
  // Syntax:
  //    Wire.requestFrom(I2C_addr, quantity, stop);
  //    Wire.read(); //repeat this for each byte to be read

  Wire.requestFrom(MPU_ADDR, 6, true);
  accel_x_h = Wire.read(); // x accel MSB
  accel_x_l = Wire.read(); // x accel LSB
  accel_y_h = Wire.read(); // y accel MSB
  accel_y_l = Wire.read(); // y accel LSB
  accel_z_h = Wire.read(); // z accel MSB
  accel_z_l = Wire.read(); // z accel LSB

  accel_x = accel_x_h << 8 | accel_x_l;  
  accel_y = accel_y_h << 8 | accel_y_l; 
  accel_z = accel_z_h << 8 | accel_z_l; 
  
  a_x = accel_x / 16384.0;
  a_y = accel_y / 16384.0;
  a_z = accel_z / 16384.0;
  
  Serial.printf("X-axis acceleration is %i (%0.2fg) \n",accel_x,a_x);
  a_tot = sqrt(pow(a_x,2)+ pow(a_y,2)+ pow(a_z,2));
  Serial.printf("Total acceleration is %0.2f \n",a_tot);

  delay(2000);

}