/*
 * Project L15_01_ColorPicker
 * Description: Learn to recieve color from Adafruit.io and store in EEPROM
 * Author: Brian Rashap
 * Date: 04-AUG-2021
 */

/*
 * Project L14_03_SubscribePublish
 * Description: Starter Code for Adafruit.io
 * Author: Brian Rashap
 * Date: 6-Aug-2020
 */

#include <Adafruit_MQTT.h>

#include "Adafruit_MQTT/Adafruit_MQTT.h" 
#include "Adafruit_MQTT/Adafruit_MQTT_SPARK.h" 
//#include "Adafruit_MQTT/Adafruit_MQTT.h" 

#include "neopixel.h"

const int PIXEL_PIN=D2;
const int PIXEL_COUNT=64;
Adafruit_NeoPixel pixel(PIXEL_COUNT, PIXEL_PIN, WS2812B);

#include "credentials.h"

/************ Global State (you don't need to change this!) ***   ***************/ 
TCPClient TheClient; 

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details. 
Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY); 

/****************************** Feeds ***************************************/ 
// Setup Feeds to publish or subscribe 
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname> 
Adafruit_MQTT_Subscribe colorFeed = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/ColorSend");
Adafruit_MQTT_Subscribe brightFeed = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/NeoBright");

/************Declare Variables*************/
unsigned long last, lastTime;
float value1, value2;
byte buf2[7];
int color,bright;
byte red,green,blue;

SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected, 15000); //wait for Serial Monitor to startup

  //Connect to WiFi without going to Particle Cloud
  WiFi.connect();
  while(WiFi.connecting()) {
    Serial.printf(".");
  }

  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&colorFeed);
  mqtt.subscribe(&brightFeed);


  pixel.begin();
  bright = 127;
  color = 0x0000FF;
}

void loop() {
  // Validate connected to MQTT Broker
  MQTT_connect();

  // Ping MQTT Broker every 2 minutes to keep connection alive
  if ((millis()-last)>120000) {
      Serial.printf("Pinging MQTT \n");
      if(! mqtt.ping()) {
        Serial.printf("Disconnecting \n");
        mqtt.disconnect();
      }
      last = millis();
  }

  // this is our 'wait for incoming subscription packets' busy subloop
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(1000))) {
    if (subscription == &colorFeed) {
      Serial.printf("Received from Adafruit: %s \n",(char *)colorFeed.lastread);
      memcpy(buf2, &colorFeed.lastread[1],6);
      Serial.printf("Buffer: %s \n",(char *)buf2);
      color = strtol((char *)buf2,NULL,16);
      Serial.printf("Buffer: 0x%02X \n",color);
      ring(color,bright);

      // parse colors and write to EEPROM
      colorParser(color, &red, &green, &blue);
      EEPROM.write(0x42,red);
      EEPROM.write(0x43,green);
      EEPROM.write(0x44,blue);

    }
    if (subscription == &brightFeed) {
      Serial.printf("Brightness from Adafruit: %s \n",(char *)brightFeed.lastread);
      bright = atoi((char *)brightFeed.lastread);
      ring(color,bright);
    }
  }
}

// Function to connect and reconnect as necessary to the MQTT server.
void MQTT_connect() {
  int8_t ret;
 
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
 
  Serial.print("Connecting to MQTT... ");
 
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.printf("%s\n",(char *)mqtt.connectErrorString(ret));
       Serial.printf("Retrying MQTT connection in 5 seconds..\n");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
  }
  Serial.printf("MQTT Connected!\n");
}

void ring(int neoColor,int neoBright) {
  int i;

  pixel.setBrightness(neoBright);
  for(i=0;i<PIXEL_COUNT;i++) {
    pixel.setPixelColor(i,neoColor);
  }
  pixel.show();
}

void colorParser(int hex, uint8_t *r, uint8_t *g, uint8_t *b) {
  red = hex >> 16;
  green = (hex >> 8) & 0x0000FF;
  blue = hex & 0x0000FF;
}