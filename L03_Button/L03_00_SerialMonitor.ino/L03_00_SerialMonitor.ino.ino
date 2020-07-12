/*
 * Project: Serial Monitor 
 * Description: Displaying to the Serial Monitor
 * Author: Brian A Rashap
 * Date: 26-Feb-2020
 */

int printDelay = 500;
int i;

void setup() {

// Enable Serial Monitor
  Serial.begin (9600);
  while (!Serial);                // wait for the Serial monitor it be on-line
  Serial.println ("Ready to Go");
}

void loop() {
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
