/*
 * Project: Buttons and Lights 
 * Description: Teach the use of variables
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

 // Connect anode of LED to Pin 5
 // Connect cathode of LED to GND with 220 ohm resistor

int ledPin = 5;
int ledDelay = 10; // 1000 ms or 1 s


// Connect button to Pin 18. Add Pull-down resistor to button terminal, Vcc to other.
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
    Serial.println("Button is not pressed");
    digitalWrite(ledPin, LOW);
    }
  else {
    Serial.println("Button is pressed");
    digitalWrite(ledPin, HIGH);
    }

delay(ledDelay);
}
