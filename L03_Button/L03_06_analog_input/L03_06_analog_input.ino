/*
 * Project: Analog_Input 
 * Description: Introduce Analog Read and Functions
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

// Connect the rotary resistor and another resistor in Series
// Connect the middle of these two resistors to Pin 14

int inPin = 14;
int inputDelay = 3000;
int inVal;
float voltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  pinMode(inPin, INPUT);
}

void loop() {
  inVal = analogRead(inPin);
  Serial.printf("analogRead value is %i \n",inVal);
  voltage = in2volts(inVal);    // call function bits2volts
  Serial.printf("The input voltage is %0.2f \n",voltage/2);
  delay(inputDelay);
}

float in2volts(int bitVal) {    // define function in2volts
  float voltVal;
  voltVal = bitVal*(3.3/1028);
  return voltVal;                 // return volts value
}
  
