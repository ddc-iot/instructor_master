/*
 * Project: Analog 
 * Description: Teach analog output and PWM
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

const int LEDPIN = 5;
const int LEDDELAY = 1000; // 1000 ms or 1 s

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  analogWrite(LEDPIN, 255);
  delay(LEDDELAY);
  analogWrite(LEDPIN, 63);
  delay(LEDDELAY);
  analogWrite(LEDPIN, 171);
  delay(LEDDELAY);
  analogWrite(LEDPIN, 16);
  delay(LEDDELAY);
}
