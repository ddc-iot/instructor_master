/*
 * Project: V3_1_functs
 * Description: Practice Using Functions
 * Author: Brian Rashap
 * Date: 27-MAR-2020
 */

/* ASSIGNMENT
 *  We are going to practice creating 
 *  and using functions:
 *  
 *  The void loop() has been writen for you (don't modify it)
 *  There are also three variables defined in the header. YOu don't need to add more.
 *  You will need to put the appropriate code into void.setup for the Serial Monitor
 *  
 *  You need to create three functions:
 *  dieroll - this returns an int which is a random number between 1 and 6, inclusive
 *  didyouwin - this returns a bool that is true if the sum of the two die is 7 or over
 *  send2monitor  - this function simply prints your two die values and whether or not you won
 *                  to the serial monitor
 *                  
 *  NOTE - create and only use local variables in the functions. 
 */

bool youwin;
int die1;
int die2;


void setup() {
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  die1 = dieroll();
  die2 = dieroll();
  youwin = didyouwin(die1,die2);
  send2monitor(die1, die2, youwin);
  delay(5000);     // wait 5 seconds before playing again
}

int dieroll() {
  int die;
  die = random(1,7);
  return die;
}

bool didyouwin(int d1, int d2) {
  bool winner;
  if ((d1+d2)>=7) {
    winner = true;
  }
  else {
    winner = false;
  }
  return winner;
}
  
void send2monitor(int dice1, int dice2, bool win) {
  Serial.print("You rolled a "); Serial.print(dice1); Serial.print(" and a "); Serial.println(dice2);
  if (win==true) {
    Serial.println("YOU WIN!!!");
  }
  else {
    Serial.println("Sorry, you did not win. Please play again");
  }
}

 
