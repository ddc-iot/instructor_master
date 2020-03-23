/*
 * Project Button Debounce
 * Description: Button Demonstration without debound
 * Author: Brian A. Rashap
 * Date: 11/10/2019
 */

// Connect one pole of the button to pin 23 and to ground via a 100 to 10k ohm resistor
// Connect other pole to Vcc (3.3V)

int buttonPin = 23;              // button is connected to pin 7
bool buttonRead;                 // variable for reading the pin status
bool buttonState;                // variable to hold the button state
int n;                          // how many times the button has been pressed
bool reading;
int lastbuttonState = LOW;

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 20;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);    

  Serial.begin(9600);           // Set up serial communication at 9600bps
  while(!Serial);               // Wait for Serial port to start
  Serial.println("Counting how many times the botton is pressed");
}


void loop(){
  reading = digitalRead(buttonPin);      // read input value and store it in val 

    if (reading != lastbuttonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if it's been there for longer than the 
    // debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {

    if (reading == HIGH) {                         // check if the button is pressed
      n++;                                      // increment the button presses variable
      Serial.print("Button has been pressed ");
      Serial.print(n);
      Serial.println(" times");
    }
          buttonState = reading;
  }
    }
      lastbuttonState = reading;             // save the new state in our variable
}
