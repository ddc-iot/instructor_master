/*
 * Project: Sine Wave 
 * Description: Teach sine wave
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

 // Connect anode of Red LED to Pin 5
 // Connect cathode of each LED to GND with 100 to 10k ohm resistor

int ledPin = 5;
int ledDelay = 50; 
float i = 0;
int out;


void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
}

void loop() {

  out = 255*(0.5*sin(2*3.14159*i)+0.5);
  analogWrite(ledPin,out);
  i = i+0.01;
  delay(ledDelay);
}
