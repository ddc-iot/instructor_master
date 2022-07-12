/*
 * Project: Servo
 * Description: Learn to use a Servo Motor
 * Author: Brian A Rashap
 * Date: 06-JAN-2021
 */

#include <PWMServo.h> 
#include <math.h>
#include <Keypad.h>

// set constants for pins
const int LOCKPIN = 22;
const int REDLED = 5;
const int GREENLED = 7;

// define servo object and variables
PWMServo myServo;

// define keypad object and variables
char key[4] = {'4','2','6','8'};
const byte ROWS = 4; 
const byte COLS = 4; 
char customKey;
char code[4];

const char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {21,20,19,18}; 
byte colPins[COLS] = {17,16,15,14}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

// global variables needed in code
int i;
bool locked;

void setup() {
  Serial.begin(9600);
  //while(!Serial);     // comment out as lock should work without monitor
  myServo.attach(LOCKPIN);

  pinMode(REDLED,OUTPUT);
  pinMode(GREENLED,OUTPUT);

  // Start with lock locked
  locked = true;
  myServo.write(180);
  digitalWrite(REDLED,HIGH);
  digitalWrite(GREENLED,LOW);

  Serial.printf("Get Started\n");
}

void loop() {
  i = 0;

  // enter 4 keys
  while(i<4) {
    customKey = customKeypad.getKey();
    if(customKey) {
      Serial.printf("%c\n",customKey);
      code[i] = customKey;
      i++;
    }
  }

  // validate they correctly stored in array
  for(i=0;i<4;i++) {
    Serial.printf("%c",code[i]);
  }
  Serial.printf("\n");

// check if matched 
  if(isMatched(code,key)){
    locked = !locked;
    Serial.printf("Locked: %i\n",locked);
    if(locked) {
      myServo.write(180);
      digitalWrite(REDLED,HIGH);
      digitalWrite(GREENLED,LOW);
    }
    else {
      myServo.write(0);
      digitalWrite(REDLED,LOW);
      digitalWrite(GREENLED,HIGH);
    }
  }
  else {
    Serial.printf("Wrong Code Entered\n");
  }
}

bool isMatched(char enteredCode[4], char secretKey[4]) {
  int i;

  for(i=0;i<4;i++) {
    if(enteredCode[i] != secretKey[i]) {
      return false;
    }
  }
  return true;
}
