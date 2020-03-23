/*
 * Project: Buttons and Lights 
 * Description: Teach using two buttons
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

int ledPin0 = 5;
int ledPin1 = 6;
int ledDelay = 10; 


int buttonPin0 = 23;
int buttonPin1 = 16;

bool buttonState0;
bool buttonState1;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);

  Serial.begin (9600);   // Turn on Serial Monitor, Open it on the Tools menu
  while (!Serial);      
  Serial.println ("Ready to Go");
}

void loop() {

buttonState0 = digitalRead(buttonPin0);
if (buttonState0 == false) {
  Serial.println("Button 0 is not pressed");
  digitalWrite(ledPin0, LOW);
  }
  else {
    Serial.println("Button 0 is pressed");
    digitalWrite(ledPin0, HIGH);
  }

buttonState1 = digitalRead(buttonPin1);
if (buttonState1 == false) {
  Serial.println("Button 1 is not pressed");
  digitalWrite(ledPin1, LOW);
  }
  else {
    Serial.println("Button  1 is pressed");
    digitalWrite(ledPin1, HIGH);
  }

delay(ledDelay);
}
