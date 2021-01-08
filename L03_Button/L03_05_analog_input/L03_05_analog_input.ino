/*
 * Project: Analog_Input 
 * Description: Introduce Analog Read and Functions
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

// Connect the potentiometer between Vcc and GND
// Connect the middle pin of the potentiometer to Pin 14

const int INPIN = 14;
int inVal;
float voltage;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  pinMode(INPIN, INPUT);
}

void loop() {
  inVal = analogRead(INPIN);
  voltage = in2volts(inVal);    // call function bits2volts
  Serial.printf("Input value = %03i, Input voltage = %0.2f\n",inVal,voltage);
}

float in2volts(int bitVal) {    // define function bits2volts
  float voltVal;
  voltVal = bitVal*(3.3/1028);
  return voltVal;                 // return volts value
}
  
