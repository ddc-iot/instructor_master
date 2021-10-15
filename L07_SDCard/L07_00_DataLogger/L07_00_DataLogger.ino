/*
 * Project: Learn to use SPI and microSD card via reading and logging data
 * Description: Learn to use SPI and microSD card
 * Author: Brian Rashap
 * Date: 08-MAR-2020
*/

/* 
 *  Attach the SD card to the SPI bus as follows
 *  ** DO (MOSI) - Pin 11 to SD Card DI 
 *  ** DI (MISO) - Pin 12 to SD Card DO
 *  ** SCK - Pin 13 to SD Card SCK/CLK, Clock
 *  ** CS - Pin 4 to SD Card CS/SS, Chip or Slave Select
 *  ** 3.3V - to SD Card <5V (this is the input power)
 *  ** GND - to SD Card GND
 *  ** NOTE: Nothing is connected to SD Card 3v nor CD (card detect)
 */

#include <SD.h>
#include <SPI.h>

File dataFile;

const int chipSelect = 4;
int temp;
int humid;
bool status;

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.printf("Initializing SD card...");

  // initialize uSD card module CS to off
  pinMode(chipSelect,OUTPUT); 
  digitalWrite(chipSelect,HIGH);
  
  // see if the card is present and can be initialized:
  status = SD.begin(chipSelect);
  if (!status) {  // if status is false
    Serial.printf("Card failed, or not present\n");
    while(true);  // pause the code indefinately
  }
  else {
    Serial.printf("card initialized.\n");
  }
}

void loop()
{
  Serial.printf("About to collect make believe data \n");
  delay(2000);
  temp = random(65,75);
  humid = random(20,50);

  print2SD(temp,humid);
  delay(2000);
  readFromSD();
}

void print2SD(int print_temp, int print_humid) {

  dataFile = SD.open("datalog.csv", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.printf("%i, %i \n",temp,print_humid);
    dataFile.close();
    Serial.printf("%i, %i \n",temp,print_humid);
  }  
  else {
    Serial.printf("error opening datalog.csv \n");
  }
  return;
} 

void readFromSD(){

    // re-open the file for reading:
  dataFile = SD.open("datalog.csv");
  if (dataFile) {
    Serial.printf("datalog.csv: \n");

    // read from the file until there's nothing else in it:
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    Serial.printf("error opening datalog.csv \n");
  }
  return;
}
