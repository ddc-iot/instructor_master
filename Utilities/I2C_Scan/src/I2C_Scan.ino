/*
 * Project I2C_Scan
 * Description: Scan I2C bus and return found addresses
 * Author: Brian Rashap
 * Date: 13-Jan-2020
 */

#include "Particle.h"

byte error; 
byte address;
int nDevices;
unsigned long delayTime;

void setup() {
	Wire.begin();
	Serial.begin(9600);
	while(!Serial);    // time to get serial running
	Serial.println("\nI2C Scanner");
}


void loop() {
	Serial.printf("Scanning: \n--------- \n");
	nDevices = 0;
	for(address = 1; address < 127; address++ ) {
		Wire.beginTransmission(address);
		error = Wire.endTransmission();
		if (error == 0) {
			Serial.printf("I2C device found at address 0x%2x \n",address);
			nDevices++;
		} else if (error == 4) {
			Serial.printf("Unknown error at address 0x%2x \n",address);
		}
	}
	if (nDevices == 0) {
		Serial.printf("No I2C devices found\n");
	}
	Serial.printf("Scan Complete!\n");
	delay(delayTime);           // wait 5 seconds for next scan
}