/*
 * Project: Encoder_Read
 * Description: Learn to use an encoder by displaying position on Serial.monitor
 * Author: Brian Rashap
 * Date: 11-Feb-2020
 */

// Wire Pins 2 and 3 of the Teensy to the A and B terminals of the Encoder
// The C (Common) terminal of the Encoder should be connected to Ground
 
#include <Encoder.h>
Encoder myEnc(3,2);

int oldPosition  = -999;
int newPosition;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Basic Encoder Test:");
}

void loop() {
  newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
}
