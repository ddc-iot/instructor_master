/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L16_Motion/L16_06_DriveByWire/src/L16_06_DriveByWire.ino"
/*
 * Project L16_06_DriveByWire
 * Description: Control a stepper motor with rotation of a gyro
 * Author: Brian Rashap
 * Date: 14-AUG-2020
 */

#include <Stepper.h>
#include <math.h>

void setup();
void loop();
uint16_t getGyroZ();
#line 11 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/L16_Motion/L16_06_DriveByWire/src/L16_06_DriveByWire.ino"
const int SPR = 2048;  // 28BYJ-48 2048 steps per revolution 
const int MOTORSPEED = 10;

// IN1, IN3, IN2, IN4
Stepper myStepper(SPR, 9, 11, 10, 12);

#include "Wire.h" // This library allows you to communicate with I2C devices.
const int MPU_ADDR = 0x68; // I2C address of the MPU-6050. If AD0 pin is set to HIGH, the I2C address will be 0x69.
int16_t gyroZ; // variables for gyro raw data
unsigned long currentTime, lastTime;
int rotationDeg, rotationSteps;

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected,15000);

  myStepper.setSpeed(MOTORSPEED);
  
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  lastTime = 0;
}
void loop() {
  currentTime = micros();
  if (currentTime - lastTime > 10000) {
    gyroZ = getGyroZ();
    rotationDeg = 0.01 * (gyroZ * (250/16535) );
    rotationSteps = rotationDeg * (SPR/360);
    if(rotationSteps > 100) { //add in a deadzone
      myStepper.step(rotationSteps);
    }

    lastTime = currentTime;
  }
}

uint16_t getGyroZ() {
  uint16_t gyro_z;

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x47); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire.requestFrom(MPU_ADDR, 2, true); // request a total of 7*2=14 registers
  gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)
  return gyro_z;
}