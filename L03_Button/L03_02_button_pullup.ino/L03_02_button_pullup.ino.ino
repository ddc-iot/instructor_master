/*
 * Project: Buttons 
 * Description: Introduce buttons, pull-down resistors, and Serial Monitor
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

int printDelay = 1000; // 1000 ms or 1 s

// Connect button to Pin 23. Add Pull-down resistor to button terminal, Vcc to other.
int buttonPin = 23;
bool buttonState; // variable to store button position

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin (9600);
  while (!Serial);        // wait for the Serial monitor it be on-line
  Serial.printf ("Ready to Go \n");
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    Serial.printf("Button State is = %i. The button is not pressed \n",buttonState);
  }
  else
  {
    Serial.printf("Button State is = %i. Button is pressed \n",buttonState);
  }

delay(printDelay);
}
