/*
 * Project Button Bounce
 * Description: Button Demonstration without debound
 * Author: Brian A. Rashap
 * Date: 11/10/2019
 */

// Connect one pole of button to GND via a 100 to 10k ohm resistor
// Connect this same pole to pin 23
// This will pull the signal to false/LOW/0 when button is not pressed
// Connect other pole to Vcc

int buttonPin = 23;              // button is connected to pin 7
bool buttonRead;                 // variable for reading the pin status
bool buttonState;                // variable to hold the button state
int n;                          // how many times the button has been pressed

void setup() {
  pinMode(buttonPin, INPUT);    // Set the switch pin as input

  Serial.begin(9600);           // Set up serial communication at 9600bps
  while(!Serial);               // Wait for Serial port to start
  Serial.println("Counting how many times the botton is pressed");
    
  buttonState = digitalRead(buttonPin);   // read the initial state
}


void loop(){
  buttonRead = digitalRead(buttonPin);      // read input value and store it in val

  if (buttonRead != buttonState) {          // the button state has changed!
    if (buttonRead == true) {                // check if the button is pressed
      n++;                                  // increment the button presses variable
      Serial.print("Button has been pressed ");
      Serial.print(n);
      Serial.println(" times");
    }
  }
  buttonState = buttonRead;                 // save the new state in our variable
}
