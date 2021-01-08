/*
 * Project: Servo
 * Description: Learn to use a Servo Motor
 * Author: Brian A Rashap
 * Date: 06-JAN-2021
 */

#include <PWMServo.h> 
#include <math.h>
#include <Keypad.h>

PWMServo myServo;

char key[4] = {'4','2','6','8'};
const byte ROWS = 4; 
const byte COLS = 4; 
char customKey;
char code[4];
int i;
bool locked;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {21,20,19,18}; 
byte colPins[COLS] = {17,16,15,14}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(9600);
  while(!Serial);
  myServo.attach(22);
  Serial.printf("Get Started\n");
  pinMode(13,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(13,LOW);
  digitalWrite(5,HIGH);
}

void loop() {
  i = 0;
  while(i<4) {
    customKey = customKeypad.getKey();
    if(customKey) {
      Serial.printf("%c\n",customKey);
      code[i] = customKey;
      i++;
    }
  }
  for(i=0;i<4;i++) {
    Serial.printf("%c",code[i]);
  }
  Serial.printf("\n");
  if(checkMatch(code,key)){
    locked = !locked;
    Serial.printf("Locked: %i\n",locked);
    if(locked) {
      myServo.write(200);
      digitalWrite(13,HIGH);
      digitalWrite(5,LOW);
    }
    else {
      myServo.write(0);
      digitalWrite(13,LOW);
      digitalWrite(5,HIGH);
    }
  }
  else {
    Serial.printf("Wrong Code Entered\n");
  }
}


bool checkMatch(char code[4], char key[4]) {
  int i;
  bool match = false;

  for(i=0;i<4;i++) {
    if(code[i] != key[i]) {
      return match;
    }
  }
  match = true;
  return match;
}
