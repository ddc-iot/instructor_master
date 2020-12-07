/*
 *  Project: Hue Light Test
 *  Description: Test Hue Lights at IOT Classroom
 *  Authors:  Frank Gonzales and Brian Rashap
 *  Date:     20-Jan-2020
 */
#include <SPI.h>
#include <Ethernet.h>
#include <mac.h>
 
//  Hue constants
 
const char hueHubIP[] = "172.16.0.2";       // Hue hub IP
const char hueUsername[] = "MQlZziRO0Wai5MsMHll8xAUAQqw85Qrr8tM37F3T";
const int hueHubPort = 80;   // HTTP: 80, HTTPS: 443, HTTP-PROXY: 8080

// PIR
int pir = 23;
boolean activated = true;
int bulb = 5;

//  Hue variables
boolean hueOn;  // on/off
int hueBri;  // brightness value
long hueHue;  // hue value
String hueCmd;  // Hue command

unsigned long buffer=0;  //buffer for received data storage
unsigned long addr;

unsigned long lastmillis;
unsigned int elapse;

bool onoff = false;
bool last = HIGH;
bool buttonstate;
 
//  Ethernet
 
//byte mac[] = {0x90,0xA2,0xDA,0x00,0x55,0x8D};  // Light Controller MAC address
// byte mac[] = {0x91,0xA3,0xDD,0x00,0x58,0x7D};  // Light Mini MAC address
IPAddress ip(172,16,0,28);  // Arduino IP
EthernetClient HueClient;

void setup()
{
   pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);

  
  Serial.begin(9600);
  Ethernet.begin(mac,ip);
  delay(2000);
  Serial.print("LinkStatus: ");
  Serial.println(Ethernet.linkStatus());

  //pinMode(pir,INPUT_PULLUP);
  pinMode(pir,INPUT);
  delay(2000);
  Serial.println("Ready.");
}

void loop() 
{ 
    /*Serial.print("Switch Setting: ");
    Serial.print(digitalRead(pir));
    Serial.print(" - Bulb#: ");
    Serial.println(bulb); */
    //Serial.println("Bulb state: ");
    //Serial.println(getHue(bulb));

    buttonstate = digitalRead(pir);

    Serial.print("Switch Setting: ");
    Serial.print(buttonstate);
    Serial.print(" last: ");
    Serial.print(last);
    Serial.print(" on/off: ");
    Serial.println(onoff);
    
    if(buttonstate !=last)
    {
      if (buttonstate == HIGH) {
        onoff = !onoff;
      }
      last = buttonstate;
      Serial.print("On/Off = "); Serial.println(onoff);
    }
    
    if(onoff==true && activated == false) {
      Serial.println(" - activated");
      delay(500);
      activated = true;
      lastmillis = millis();
      int RNDhue = random(1,65000);
      String command = "{\"on\":true,\"sat\":255,\"bri\":255,\"hue\":";
      command = command + String(RNDhue) + "}";
      setHue(bulb,command);
    }

    elapse = millis()-lastmillis;
    if(onoff==true && elapse > 30000) {
      Serial.println(" - activated");
      delay(500);
      activated = true;
      lastmillis = millis();
      int RNDhue = random(1,65000);
      String command = "{\"on\":true,\"sat\":255,\"bri\":255,\"hue\":";
      command = command + String(RNDhue) + "}";
      setHue(bulb,command);
    }  

  if(onoff==false && activated == true) {
      Serial.println(" - DEactivated");
      delay(500);
      activated = false;
      String command = "{\"on\":false}";
      setHue(bulb,command); 
  }
  delay(1000);
}

/* setHue() is our main command function, which needs to be passed a light number and a 
 * properly formatted command string in JSON format (basically a Javascript style array of variables
 * and values. It then makes a simple HTTP PUT request to the Bridge at the IP specified at the start.
 */
boolean setHue(int lightNum,String command)
{
  if (HueClient.connect(hueHubIP, hueHubPort))
  {
    //while (HueClient.connected())
    //{
      Serial.println("Sending Command to Hue");
      Serial.println(command);
      HueClient.print("PUT /api/");
      HueClient.print(hueUsername);
      HueClient.print("/lights/");
      HueClient.print(lightNum);  // hueLight zero based, add 1
      //  HueClient.println("/state");
      HueClient.println("/state HTTP/1.1");
      HueClient.println("keep-alive");
      HueClient.print("Host: ");
      HueClient.println(hueHubIP);
      HueClient.print("Content-Length: ");
      HueClient.println(command.length());
      HueClient.println("Content-Type: text/plain;charset=UTF-8");
      HueClient.println();  // blank line before body
      HueClient.println(command);  // Hue command
      Serial.println("From Hue");
      Serial.println(HueClient.readString()); // To close connection
    HueClient.stop();
    return true;  // command executed
  }
  else
    return false;  // command failed
}

/* A helper function in case your logic depends on the current state of the light. 
 * This sets a number of global variables which you can check to find out if a light is currently on or not
 * and the hue etc. Not needed just to send out commands
 */
boolean getHue(int lightNum)
{
  if (HueClient.connect(hueHubIP, hueHubPort))
  {
    HueClient.print("GET /api/");
    HueClient.print(hueUsername);
    HueClient.print("/lights/");
    HueClient.print(lightNum);  
    HueClient.println(" HTTP/1.1");
    HueClient.print("Host: ");
    HueClient.println(hueHubIP);
    HueClient.println("Content-type: application/json");
    HueClient.println("keep-alive");
    HueClient.println();
    while (HueClient.connected())
    {
      if (HueClient.available())
      {
        Serial.println();
        Serial.println(HueClient.readString());
        Serial.println();
        HueClient.findUntil("\"on\":", "\0");
        hueOn = (HueClient.readStringUntil(',') == "true");  // if light is on, set variable to true
        Serial.print("Hue Status: ");
        Serial.println(hueOn);
 
        HueClient.findUntil("\"bri\":", "\0");
        hueBri = HueClient.readStringUntil(',').toInt();  // set variable to brightness value
        //Serial.println(hueBri);
        
        HueClient.findUntil("\"hue\":", "\0");
        hueHue = HueClient.readStringUntil(',').toInt();  // set variable to hue value
        //Serial.println(hueHue);
        
        break;  // not capturing other light attributes yet
      }
    }
    HueClient.stop();
    return true;  // captured on,bri,hue
  }
  else
    return false;  // error reading on,bri,hue
}
