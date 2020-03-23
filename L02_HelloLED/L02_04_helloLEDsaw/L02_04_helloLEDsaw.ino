/*
 * Project: Saw Tooth 
 * Description: Teach For loops
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

 // Connect anode of Red LED to Pin 5
 // Connect anode of Green LED to Pin 6
 // Connect anode of Blue LED to Pin 7
 // Connect cathode of each LED to GND with a resistor (100 ohm to 10k ohm)

int ledRed = 5;
int ledGreen = 6;
int ledBlue = 7;
int ledDelay = 10;
int i;

void setup() {
  // put your setup code here, to run once:
pinMode(ledRed, OUTPUT);
pinMode(ledGreen, OUTPUT);
pinMode(ledBlue, OUTPUT);
}

void loop() {

for(i=0;i<256;i++){
  analogWrite(ledRed,i);
  analogWrite(ledGreen,i);
  analogWrite(ledBlue,i);
  delay(ledDelay);
  }

for(i=255;i>=0;i--) {
  analogWrite(ledRed,i);
  analogWrite(ledGreen,i);
  analogWrite(ledBlue,i);
  delay(ledDelay);
  }

}
