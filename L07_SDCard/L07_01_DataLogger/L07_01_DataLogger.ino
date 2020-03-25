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
const int readArray[] = {14, 15, 16};
String dataString;
int i;
int num_sensors;
float sensor;

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

  num_sensors = sizeof(readArray)/4;
}

void loop()
{
  // clear thestring for assembling the data to log:
  dataString = "";


  Serial.println("About to collect data from sensors");
  delay(2000);
  // read three sensors and append to the string:
  for (i = 0; i < num_sensors; i++) {
    sensor = random(0,1047);
    dataString += String(sensor);
    if (i < (num_sensors - 1)) {
      dataString += ",";
    }
  }

  print2SD();
  delay(2000);
  read2SD();
}

void print2SD() {

  dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }  
  else {
    Serial.println("error opening datalog.txt");
  }
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
}
