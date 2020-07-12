/*
 * Project: Analog 
 * Description: Teach analog output and PWM
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

int ledPin = 5;
int ledDelay = 1000; // 1000 ms or 1 s

void setup() {
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
