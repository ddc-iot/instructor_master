/*
 * Project: Analog 
 * Description: Teach analog output and PWM
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

 // Connect anode of Red LED to Pin 5
 // Connect cathode of each LED to GND with a resistor (100 to 10k ohm)

int ledPin = 5;
int ledDelay = 1000; // 1000 ms or 1 s

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
}

void loop() {
analogWrite(ledPin, 255);
delay(ledDelay);
analogWrite(ledPin, 63);
delay(ledDelay);
analogWrite(ledPin, 171);
delay(ledDelay);
analogWrite(ledPin, 16);
delay(ledDelay);
}
