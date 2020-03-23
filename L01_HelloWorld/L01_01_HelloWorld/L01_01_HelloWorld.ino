/*
 * Project: Hello World - IoT Style 
 * Description: First Program
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13, HIGH);
delay(1000);                // the delay in in milliseconds
digitalWrite(13, LOW);
delay(250);
}
