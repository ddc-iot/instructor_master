/*
 * Project L17_00_UART
 * Description: Starter Code for sending / recieving data from Bluefruit Connect app
 * Author: Brian Rashap
 * Date: 28-JUL-20212
 */

// Setup BLE UART

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
}

void loop() {

}
