/*
 * Project: Buttons 
 * Description: Introduce buttons, pull-down resistors, and Serial Monitor
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

int ledDelay = 1000; // 1000 ms or 1 s

// Connect button to Pin 23. Connect GND to one end of the button. No resistor needed
int buttonPin = 23;

bool buttonState; // variable to store button position

void setup() {

pinMode(buttonPin, INPUT_PULLUP);

// Enable Serial Monitor
  Serial.begin (9600);
  while (!Serial);        // wait for the Serial monitor it be on-line
  Serial.println ();
  Serial.println ("Ready to Go");
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == true) {
    Serial.println("Button is not pressed");
  }
  else
  {
    Serial.println("Button is pressed");
  }

delay(ledDelay);
}
