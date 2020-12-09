/*
 * Project: SerialReadExample
 * Description: Read input from Serial Monitor
 * Author: Brian Rashap
 * Date: 12-JUL-2020
 */

String incomingText="";
int startValue;

void setup() {
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  Serial.printf("Enter a Value: \n");
  incomingText="";
  while(incomingText=="") {
      incomingText = Serial.readStringUntil('\n');
      Serial.print(".");
  }
  Serial.println(incomingText);
  startValue = incomingText.toInt();
  Serial.printf("The counter will start at %i \n",startValue);
}
