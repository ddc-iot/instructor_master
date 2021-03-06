/*
 * Project: Triangle Wave 
 * Description: Teach FOR loops
 * Author: Brian A Rashap
 * Date: 09-FEB-2020
 */

 // Connect anode of Red LED to Pin 5
 // Connect anode of Green LED to Pin 6
 // Connect anode of Blue LED to Pin 7
 // Connect cathode of each LED to GND with a resistor (100 ohm to 10k ohm)

const int LEDRED = 5;
const int LEDDELAY = 19; // 5000 ms / 255 steps = 19ms per step for 5 sec half period
int i;

void setup() {
  pinMode(LEDRED, OUTPUT);
}

void loop() {

  for(i=0;i<256;i++){
    analogWrite(LEDRED,i);
    delay(LEDDELAY);
  }

  for(i=255;i>=0;i--) {
    analogWrite(LEDRED,i);
    delay(LEDDELAY);
  }
}
