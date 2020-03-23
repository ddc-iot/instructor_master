/*
 * Project: Buttons 
 * Description: Introduce buttons, pull-down resistors, and Serial Monitor
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

int ledDelay = 1000; 

// Connect button to Pin 23. Add Pull-up resistor to button terminal, GND to other.
int buttonPin = 23;

bool buttonState; // variable to store button position

void setup() {

pinMode(buttonPin, INPUT);

// Enable Serial Monitor
  Serial.begin (9600);
  while (!Serial);        // wait for the Serial monitor it be on-line
  Serial.println ();
  Serial.println ("Ready to Go");
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == true) {                     // for bool: true = HIGH = 1
    Serial.println("Button is not pressed");
  }
  else
  {
    Serial.println("Button is pressed");
  }

delay(ledDelay);
}
