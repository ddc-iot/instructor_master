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
int ledDelay = 19; // 5000 ms / 255 steps = 19ms per step for 5 sec half period
int i;

void setup() {
  pinMode(ledRed, OUTPUT);
}

void loop() {

  for(i=0;i<256;i++){
    analogWrite(ledRed,i);
    delay(ledDelay);
  }

  for(i=255;i>=0;i--) {
    analogWrite(ledRed,i);
    delay(ledDelay);
  }

}
