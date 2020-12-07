/*
 * Project: BME280 SDMicro
 * Description: BME280 Pressure Sensor data 
 * Author: Brian A Rashap
 * Date: 12-Nov-2019
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>


// Define bme as the I2C interface to the BME280 sensor
Adafruit_BME280 bme; 

#define SEALEVELPRESSURE_HPA (1013.25)

int delayTime = 10000;

float temp;
float prs;
float alt;
float hum;

bool status;

void setup() {
    Serial.begin(9600);
    while(!Serial);    // time to get serial running
    
    Serial.println(F("BME280 test"));   // ask the instructor about the F
    status = bme.begin(0x76);  
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),HEX);
        Serial.println("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085");
        Serial.println("   ID of 0x56-0x58 represents a BMP 280,");
        Serial.println("        ID of 0x60 represents a BME 280.");
        Serial.println("        ID of 0x61 represents a BME 680.");
        while (1);
    }
    else {
      Serial.println("BME280 Up and Running");
    }
}

void loop() {

    temp = (bme.readTemperature() * 8 / 5) + 32;
    prs = (bme.readPressure() / 100.0F) / 68.9476;
    alt = bme.readAltitude(SEALEVELPRESSURE_HPA) * 3.28084;
    hum = bme.readHumidity();

    printValues(temp,prs,alt,hum);
 
    delay(delayTime);

}

void printValues(float Ptemp, float Pprs, float Palt, float Phum) {
    
    Serial.print("Temperature = ");
    Serial.print(Ptemp);
    Serial.println(" *F");

    Serial.print("Pressure = ");
    Serial.print(Pprs);
    Serial.println(" psi");

    Serial.print("Approx. Altitude = ");
    Serial.print(Palt);
    Serial.println(" ft");

    Serial.print("Humidity = ");
    Serial.print(Phum);
    Serial.println(" %");

    Serial.println();
}
