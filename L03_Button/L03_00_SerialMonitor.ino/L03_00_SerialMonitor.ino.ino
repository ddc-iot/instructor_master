/*
 * Project: Serial Monitor 
 * Description: Displaying to the Serial Monitor
 * Author: Brian A Rashap
 * Date: 26-Feb-2020
 */

int printDelay = 500;
int i;

void setup() {

  Serial.begin (9600);            // Enable Serial Monitor
  while(!Serial);                 // wait a moment for the Serial monitor it be on-line
  Serial.println ("Ready to Go");

  for (i=0; i <=13; i++) {
    Serial.print(i);
    Serial.print(",");
    delay(printDelay);
  }

  for (i=0; i <=13; i++) {
    Serial.print(i);
    Serial.println(",");
    delay(printDelay);
  }
  
  for (i=0; i <=13; i++) {
    Serial.printf("%i, ",i);
    delay(printDelay);
  }
}

void loop() {}
