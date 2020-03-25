/*
 * Project: servoSweep
 * Description: Serial communication using PWM Analog output
 * Author: Brian Rashap
 * Date: 17-FEB-2020
*/ 

// Connect Servo signal line to one of the PWM analog outputs
// The MG90S servo requires 4.4V to 6.0V control signals, works with 3.3V.
// However, the supply voltage does need to be over 4.4V
// When we get them, we will utilize a 74HCT125 (or similar) shift leveler to translate signal voltage


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards

servoPin = 6;
servoDelay;
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(servoPin);  // attaches the servo on PWM pin to the servo object 
} 
 
void loop() 
{ 
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(servoDelay);               // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(servoDelay);               // waits 15ms for the servo to reach the position 
  } 
} 
