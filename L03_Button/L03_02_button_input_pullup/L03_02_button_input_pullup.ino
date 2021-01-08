/*
 * Project: Button_Input_Pullup
 * Description: The INPUT_PULLUP pinMode
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

// Connect button to Pin 23. Add Pull-down resistor to button terminal, Vcc to other.
const int BUTTONPIN = 23;
bool buttonState; // variable to store button position

void setup() {
  Serial.begin (9600);    // Enable Serial Monitor
  while (!Serial);        // wait for the Serial monitor it be on-line

  pinMode(BUTTONPIN, INPUT_PULLUP);
  
  Serial.printf("Ready to Go\n");
}

void loop() {
  buttonState = digitalRead(BUTTONPIN);
  Serial.printf("buttonState = %i\n",buttonState);
}
