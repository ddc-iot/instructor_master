/*
 * Project: Buttons and Lights 
 * Description: Teach using two buttons
 * Author: Brian A Rashap
 * Date: 11-Dec-2019
 */

int BLUELED = 5;
int YELLOWLED = 6;
 
int BLUEBUTTON = 23;
int YELLOWBUTTON = 16;

bool blueState;
bool yellowState;

void setup() {
  Serial.begin (9600);   // Turn on Serial Monitor, Open it on the Tools menu
  while (!Serial);      

  pinMode(BLUELED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(BLUEBUTTON, INPUT);
  pinMode(YELLOWBUTTON, INPUT);

  Serial.println ("Ready to Go");
}

void loop() {
  blueState = digitalRead(BLUEBUTTON);
  if (blueState) {
    Serial.println("  Blue Button is pressed");
    digitalWrite(BLUELED, HIGH);
  }
  else {
    Serial.println("  Blue Button not is pressed");
    digitalWrite(BLUELED, LOW);
  }

yellowState = digitalRead(YELLOWBUTTON);
  if (yellowState) {
    Serial.println("Yellow Button is pressed");
    digitalWrite(YELLOWLED, HIGH);
  }
  else {
    Serial.println("Yellow Button not is pressed");
    digitalWrite(YELLOWLED, LOW);
  }
}
