/*
 * Project: BME280 SDMicro
 * Description: BME280 Pressure Sensor data 
 *              written to SD Micro card
 * Author: Brian A Rashap
 * Date: 12-Nov-2019
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <SPI.h>
#include <SD.h>

File myFile;

// Define bme as the I2C interface to the BME280 sensor
Adafruit_BME280 bme; // I2C

#define SEALEVELPRESSURE_HPA (1013.25)

int delayTime;

float temp;
float prs;
float alt;
float hum;

unsigned status;
unsigned long now;


void setup() {
    Serial.begin(9600);
    while(!Serial);    // time to get serial running

    Serial.print("Initializing SD card...");

    if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
    }
    
  Serial.println("initialization done.");
    
    Serial.println(F("BME280 test"));
    status = bme.begin(0x76);  
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
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

  myFile = SD.open("bmetest1.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to bme_test1...");
    myFile.print("Time Stamp ");
    myFile.println(millis()/1000.0);
    
    myFile.print("Temperature = ");
    myFile.print(temp);
    myFile.println(" *F");

    myFile.print("Pressure = ");
    myFile.print(prs);
    myFile.println(" psi");

    myFile.print("Approx. Altitude = ");
    myFile.print(alt);
    myFile.println(" ft");

    myFile.print("Humidity = ");
    myFile.print(hum);
    myFile.println(" %");

    myFile.println();
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  // re-open the file for reading:
  myFile = SD.open("bmetest1.txt");
  if (myFile) {
    Serial.println("bme_test1.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
    
    delay(300000);

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
