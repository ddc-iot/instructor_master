/*
 * Project: Variables 
 * Description: Teach the use of variables
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

 // Connect anode of LED to Pin 5
 // Connect cathode of LED to GND with a resistor (100 ohm to 10k ohm)

int ledPin = 5;
int ledDelay = 1000; // 1000 ms or 1 s

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
}

void loop() {
digitalWrite(ledPin, HIGH);
delay(ledDelay);
digitalWrite(ledPin, LOW);
delay(ledDelay);
}
