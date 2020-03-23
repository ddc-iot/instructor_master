/*
 * Project: Serial Monitor 
 * Description: Displaying to the Serial Monitor
 * Author: Brian A Rashap
 * Date: 26-Feb-2020
 */

int ledDelay = 1000; // 1000 ms or 1 s
int i;

void setup() {

// Enable Serial Monitor
  Serial.begin (9600);
  while (!Serial);                // wait for the Serial monitor it be on-line
  Serial.println ("Ready to Go");
}

void loop() {
  for (i=0; i <=13; i++) {
    Serial.println(i);
    delay(ledDelay);
  }
}
