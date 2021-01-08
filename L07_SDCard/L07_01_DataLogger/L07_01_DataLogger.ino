/*
 * Project: Learn to use SPI and microSD card via reading and logging data
 * Description: Learn to use SPI and microSD card
 * Author: Brian Rashap
 * Date: 08-MAR-2020
*/

/* Assignment:
 *  Attach analog "sensors" to three of the analogRead pins
 *  Attach the SD card to the SPI bus as follows
 *  ** DO - Pin 11 to SD Card MOSI (Master Out, Slave In
 *  ** DI - Pin 12 to SD Card MISO, Master In, Slave OUt
 *  ** SCK - Pin 13 to SD Card SCK/CLK, Clock
 *  ** CS - Pin 4 to SD Card CS/SS, Chip or Slave Select
 */

#include <SD.h>
#include <SPI.h>

File dataFile;

const int chipSelect = 4;
int temp;
int humid;

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.print("Initializing SD card...");
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{
  Serial.println("About to collect make believe data");
  delay(2000);
  temp = random(65,75);
  humid = random(20,50);

  print2SD(temp,humid);
  delay(2000);
  read2SD();
}

void print2SD(int print_temp, int print_humid) {

  dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.printf("%i, %i, %i \n",temp,humid);
    dataFile.close();
    Serial.printf("%i, %i, %i \n",temp,humid);
  }  
  else {
    Serial.println("error opening datalog.txt");
  }
  return;
} 

void read2SD(){

    // re-open the file for reading:
  dataFile = SD.open("datalog.txt");
  if (dataFile) {
    Serial.println("datafile.txt: ");

    // read from the file until there's nothing else in it:
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    Serial.println("error opening datafile.txt");
  }
  return;
}
