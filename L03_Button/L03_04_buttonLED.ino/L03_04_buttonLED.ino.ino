/*
 * Project: Buttons and Lights 
 * Description: Teach reading a button and controlling an LED
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

 // Connect anode of LED to Pin 5
 // Connect cathode of LED to GND with 220 ohm resistor

int ledPin = 5;

// Connect button to Pin 5. Add Pull-down resistor to button terminal, Vcc to other.
int buttonPin = 23;
bool buttonState;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin (9600);
  while (!Serial);       // wait for the Serial monitor it be on-line
  Serial.println ("Ready to Go");
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == false) {
    Serial.printf("Button State is = %i. The button is not pressed \n",buttonState);
    digitalWrite(ledPin, LOW);
    }
  else {
    Serial.printf("Button State is = %i. Button is pressed \n",buttonState);
    digitalWrite(ledPin, HIGH);
    }
}
