/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/IoT_Instructor/Documents/IoT/cohort4/L17_BlueTooth/L17_00_UART/src/L17_00_UART.ino"
/*
 * Project L17_00_UART
 * Description: Demosntration project for sending / recieving data from Bluefruit Connect app
 * Author: Brian Rashap
 * Date: 28-JUL-20212
 */

#include "Particle.h"

// Setup BLE UART

void setup();
void loop();
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer, void* context);
#line 12 "c:/Users/IoT_Instructor/Documents/IoT/cohort4/L17_BlueTooth/L17_00_UART/src/L17_00_UART.ino"
const size_t UART_TX_BUF_SIZE = 20;
uint8_t txBuf[UART_TX_BUF_SIZE];
uint8_t i;

// These UUIDs were defined by Nordic Semiconductor and are now the defacto standard for
// UART-like services over BLE. Many apps support the UUIDs now, like the Adafruit Bluefruit app.
const BleUuid serviceUuid("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid rxUuid("6E400002-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid txUuid("6E400003-B5A3-F393-E0A9-E50E24DCCA9E");

BleCharacteristic txCharacteristic("tx", BleCharacteristicProperty::NOTIFY, txUuid, serviceUuid);
BleCharacteristic rxCharacteristic("rx", BleCharacteristicProperty::WRITE_WO_RSP, rxUuid, serviceUuid, onDataReceived, NULL);
BleAdvertisingData data;

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
}

void loop() {
    for(i=0;i<UART_TX_BUF_SIZE-1;i++) {
      txBuf[i] = random(0x40,0x5B); //Captial ASCII characters plus @
    }
    txBuf[UART_TX_BUF_SIZE-1] = 0x0A;
    txCharacteristic.setValue(txBuf, UART_TX_BUF_SIZE);
    for(i=0;i<UART_TX_BUF_SIZE;i++) {
        Serial.printf("%c",txBuf[i]);
    }
    delay(5000);
}

//onDataReceived is used to recieve data from Bluefruit Connect App
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer, void* context) {
    uint8_t i;

    Serial.printf("Received data from: %02X:%02X:%02X:%02X:%02X:%02X \n", peer.address()[0], peer.address()[1],peer.address()[2], peer.address()[3], peer.address()[4], peer.address()[5]);
    Serial.printf("Bytes: ");
    for (i = 0; i < len; i++) {
        Serial.printf("%02X ",data[i]);
    }
    Serial.printf("\n");
    Serial.printf("Message: %s\n",(char *)data);
}