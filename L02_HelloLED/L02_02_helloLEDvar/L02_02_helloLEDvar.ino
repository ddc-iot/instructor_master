/*
 * Project: Variables 
 * Description: Teach the use of variables
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

 // Connect anode of LED to Pin 5
 // Connect cathode of LED to GND with a resistor (100 ohm to 10k ohm)

const int LEDPIN = 5;
const int LEDDELAY = 100; // 1000 ms or 1 s

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  digitalWrite(LEDPIN, HIGH);
  delay(LEDDELAY);
  digitalWrite(LEDPIN, LOW);
  delay(LEDDELAY);
}
