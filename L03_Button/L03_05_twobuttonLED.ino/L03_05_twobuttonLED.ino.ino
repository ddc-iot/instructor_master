/*
 * Project: Buttons and Lights 
 * Description: Teach reading a button and controlling an LED
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

 // Connect anode of LED to Pin 5
 // Connect cathode of LED to GND with 220 ohm resistor

int redPin = 5;
int yellowPin = 6;

// Connect button to Pin 5. Add Pull-down resistor to button terminal, Vcc to other.
int redButtonPin = 23;
int yellowButtonPin = 16;
bool redButtonState;
bool yellowButtonState;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(redButtonPin, INPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);

  Serial.begin (9600);
  while (!Serial);       // wait for the Serial monitor it be on-line
  Serial.println ("Ready to Go");
}

void loop() {

  redButtonState = digitalRead(redButtonPin);
  if (redButtonState == false) {
    Serial.printf("Red Button State is = %i. The button is not pressed \n",redButtonState);
    digitalWrite(redPin, LOW);
  }
  else {
    Serial.printf("Red Button State is = %i. Button is pressed \n",redButtonState);
    digitalWrite(redPin, HIGH);
  }

  yellowButtonState = digitalRead(yellowButtonPin);
  if (yellowButtonState == false) {
    Serial.printf("Yellow Button State is = %i. The button is not pressed \n",yellowButtonState);
    digitalWrite(yellowPin, LOW);
  }
  else {
    Serial.printf("Yellow Button State is = %i. Button is pressed \n",yellowButtonState);
    digitalWrite(yellowPin, HIGH);
  }


    
}
