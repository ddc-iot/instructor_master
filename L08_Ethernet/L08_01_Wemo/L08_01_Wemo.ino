/*
 * Project: WEMO with PullUp
 * Description: Control smart lighting switch from a button
 * Author: Brian A Rashap
 * Date: 24-Mar-2020
 */

 // Connect Ethernet port per Fritzing diagram and a button to Pin 23
 // You will need to find the IP address of your Wemo smart plug  by logining onto your router

#include <Ethernet.h>
#include <SPI.h>
#include <mac.h>
 
EthernetClient WemoClient;

int inPin = 23;
bool state = true;
bool reading;

char wemoIP[ ] = "10.0.0.145";
int wemoPort = 49153;

void setup()
{
  pinMode(inPin, INPUT_PULLUP);
 
  Serial.begin(9600);
  Ethernet.begin(mac);
  delay(1000);
  Serial.println("connecting...");

  // print your local IP address:
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println();
}

void loop(){

   reading = digitalRead(inPin);
   
   if (reading != state){
     if (reading==true){
       switchON();
       delay(1000);
     }else{
       switchOFF();
       delay(1000);
     }
     state = reading;
   }
}

void switchON()
{
  String data1;
  
  Serial.println("switchON");
  data1+="<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:SetBinaryState xmlns:u=\"urn:Belkin:service:basicevent:1\"><BinaryState>1</BinaryState></u:SetBinaryState></s:Body></s:Envelope>"; // Use HTML encoding for comma's
  if (WemoClient.connect(wemoIP,wemoPort)) {
        WemoClient.println("POST /upnp/control/basicevent1 HTTP/1.1");
        WemoClient.println("Content-Type: text/xml; charset=utf-8");
        WemoClient.println("SOAPACTION: \"urn:Belkin:service:basicevent:1#SetBinaryState\"");
        WemoClient.println("Connection: keep-alive");
        WemoClient.print("Content-Length: ");
        WemoClient.println(data1.length());
        WemoClient.println();
        WemoClient.print(data1);
        WemoClient.println();
    }

  if (WemoClient.connected()) {
     WemoClient.stop();
  }
}

void switchOFF(){
  
  Serial.println("switchOFF");
  String data1;
  data1+="<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:SetBinaryState xmlns:u=\"urn:Belkin:service:basicevent:1\"><BinaryState>0</BinaryState></u:SetBinaryState></s:Body></s:Envelope>"; // Use HTML encoding for comma's
  if (WemoClient.connect(wemoIP,wemoPort)) {
        WemoClient.println("POST /upnp/control/basicevent1 HTTP/1.1");
        WemoClient.println("Content-Type: text/xml; charset=utf-8");
        WemoClient.println("SOAPACTION: \"urn:Belkin:service:basicevent:1#SetBinaryState\"");
        WemoClient.println("Connection: keep-alive");
        WemoClient.print("Content-Length: ");
        WemoClient.println(data1.length());
        WemoClient.println();
        WemoClient.print(data1);
        WemoClient.println();
    }
   
  if (WemoClient.connected()) {
     WemoClient.stop();
  }
}
