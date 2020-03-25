/*
 * Project OLEDwrite
 * Description: Learn to write to 128x24 OLED screen
 * Author: Brian A. Rashap
 * Date: 11/13/2019
 */

#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

String myname;
String mymsg;

void setup()
{                
    // Start Serial Monitor
    Serial.begin(9600);
    while(!Serial);         // wait for serial to start running
    Serial.println("Serial Monitor Up and Running");

  // initialie OLED display
  Wire.begin();  
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen


  myname = "Brian";
  mymsg = "Welcome to IoT";
}

void loop()                     
{
    oled_write(myname, mymsg, millis());
    delay(5000);
}

void oled_write(String myname, String mymsg, long clk) {
  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0);              
  oled.putString("Hello World");
  oled.setTextXY(1,0);              
  oled.putString("from ");
  oled.setTextXY(1,5);              
  oled.putString(myname);
  oled.setTextXY(3,0);              
  oled.putString(mymsg);
  oled.setTextXY(5,0);             
  oled.putString("Elapse ");
  oled.setTextXY(5,8);             
  oled.putString(String(clk/1000.0));
}
