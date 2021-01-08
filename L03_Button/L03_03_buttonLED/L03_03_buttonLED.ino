/*
 * Project: Buttons and Lights 
 * Description: Teach reading a button and controlling an LED
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

 // Connect anode of LED to Pin 5
 // Connect cathode of LED to GND with 220 ohm resistor

int LEDPIN = 5;

// Connect button to Pin 23. Add Pull-down resistor to button terminal, Vcc to other.
const int BUTTONPIN = 23;
bool buttonState;

void setup() {
  Serial.begin (9600);
  while (!Serial);       // wait for the Serial monitor it be on-line

  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
  Serial.println ("Ready to Go");
}

void loop() {

  buttonState = digitalRead(BUTTONPIN);
  if (buttonState) {
    Serial.println("Button is pressed");
    digitalWrite(LEDPIN, HIGH);
    }
  else {
    Serial.println("Button is not pressed");
    digitalWrite(LEDPIN, LOW);
  }
}
