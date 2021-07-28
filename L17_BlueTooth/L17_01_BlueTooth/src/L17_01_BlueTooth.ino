/*
 * Project L17_01_BlueTooth
 * Description: Send character strings and data over BLE to Bluefruit Connect
 * Author: Brian Rashap
 * Date: 28-JUL-2021
 */

#include "neopixel.h"
#include "Encoder.h"

// Encoder Setup
Encoder myEnc(D0, D1);
const int ENCODER_COUNT = 96;

// Setup BLE UART

const size_t UART_TX_BUF_SIZE = 16;
uint8_t txBuf[UART_TX_BUF_SIZE];

// These UUIDs were defined by Nordic Semiconductor and are now the defacto standard for
// UART-like services over BLE. Many apps support the UUIDs now, like the Adafruit Bluefruit app.
const BleUuid serviceUuid("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid rxUuid("6E400002-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid txUuid("6E400003-B5A3-F393-E0A9-E50E24DCCA9E");

BleCharacteristic txCharacteristic("tx", BleCharacteristicProperty::NOTIFY, txUuid, serviceUuid);
BleCharacteristic rxCharacteristic("rx", BleCharacteristicProperty::WRITE_WO_RSP, rxUuid, serviceUuid, onDataReceived, NULL);
BleAdvertisingData data;

// Setup NeoPixels
#define PIXEL_COUNT 64
#define PIXEL_PIN D2
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel pixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

//Declare Global Variables
int i;
int red, green, blue;
int lastPosition, newPosition;
int pixelNumber, lastPixel, pixelColor;

SYSTEM_MODE(SEMI_AUTOMATIC); //Using BLE and not Wifi

void setup() { 
    Serial.begin();
    waitFor(Serial.isConnected, 15000);  
    delay(2000);
 
    BLE.on();

    Serial.printf("Starting up BLE Connection \n");

    BLE.addCharacteristic(txCharacteristic);
    BLE.addCharacteristic(rxCharacteristic);
    data.appendServiceUUID(serviceUuid);
    BLE.advertise(&data);

    Serial.printf("Argon BLE Address: %s\n",BLE.address().toString().c_str());

    lastPixel = -999;
    pixelColor = 0x0000FF;
    pixel.setBrightness(31);
}

void loop() {

  newPosition = getEnc();
  pixelNumber = map(newPosition,0,ENCODER_COUNT-1,0,PIXEL_COUNT-1);

  if (pixelNumber != lastPixel) {
    lastPixel = pixelNumber;
    red = random(0,255);
    green = random(0,255);
    blue = random(0,255);
    pixelColor = red << 16 | green << 8 | blue;
    fillPixels(pixelNumber,pixelColor);
    Serial.printf("Pixel position = %i\n",pixelNumber);
    bleSend(pixelNumber,red,green,blue);
  }
}

//onDataReceived is used to recieve data from Bluefruit Connect App
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer, void* context) {
    //int pixelcount,pixelcolor;
    uint8_t i;
    int encPos;

    Serial.printf("Received data from: %02X:%02X:%02X:%02X:%02X:%02X \n", peer.address()[0], peer.address()[1],peer.address()[2], peer.address()[3], peer.address()[4], peer.address()[5]);
    for (i = 0; i < len; i++) {
        Serial.printf("%02X",data[i]);
    }
    Serial.printf("\n");

    if(len < 5) {
      pixelNumber = atoi((char *)data);
      lastPixel = pixelNumber;
      encPos = map(pixelNumber,0,PIXEL_COUNT-1,0,ENCODER_COUNT-1);
      myEnc.write(encPos); 
    }
    else {
      pixelColor = data[2]<<16 | data[3]<<8 | data[4];
    }
    fillPixels(pixelNumber,pixelColor);
}

// get encoder position, and pin encoder to 0 to ENCODER_COUNT
int getEnc() {
  int position;

  position = myEnc.read();
  if (position > ENCODER_COUNT) {
    position = ENCODER_COUNT;
    myEnc.write(ENCODER_COUNT);
  }
  if (position < 0) {
    position = 0;
    myEnc.write(0);
  }
  return position;
}

// fill pixels with pixColor up to pixel pixNum
void fillPixels(int pixNum, int pixColor) {
  int i;

  pixel.clear();
  for (i=0;i<=pixNum;i++) {
    pixel.setPixelColor(i,pixColor);
  }
  pixel.show();
}

// Convert data to ASCII and send to Bluefruit connect for display and/or plotting
void bleSend(int pixNum, int PixRed, int PixGreen, int PixBlue) {

    txBuf[0] = 0x30 + pixNum / 10;
    txBuf[1] = 0x30 + pixNum % 10;
    txBuf[2] = 0x2C;
    txBuf[3] = 0x30 + red/100;
    txBuf[4] = 0x30 + (red%100)/10;
    txBuf[5] = 0x30 + (red%100)%10;
    txBuf[6] = 0x2C;
    txBuf[7] = 0x30 + green/100;
    txBuf[8] = 0x30 + (green%100)/10;
    txBuf[9] = 0x30 + (green%100)%10;
    txBuf[10] = 0x2C;
    txBuf[11] = 0x30 + blue/100;
    txBuf[12] = 0x30 + (blue%100)/10;
    txBuf[13] = 0x30 + (blue%100)%10;
    txBuf[14] = 0x0A;

    txCharacteristic.setValue(txBuf,15);
}
