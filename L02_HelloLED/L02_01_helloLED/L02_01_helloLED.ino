/*
 * Project: Hello World - IoT Style 
 * Description: First Program
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

 // Connect anode of LED to Pin 5
 // Connect cathode of LED to GND with a resistor (100 ohms to 10,000 ohms)




void setup() {
  // put your setup code here, to run once:
pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(5, HIGH);
delay(1000);
digitalWrite(5, LOW);
delay(1000);
}
