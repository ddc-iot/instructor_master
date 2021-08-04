/*
 * Project L16_05_Stepper
 * Description: Learn how to use Stepper Motor
 * Author: Brian Rashap
 * Date: 14-AUG-2020
 */

#include <Stepper.h>

const int SPR = 2048;  // 28BYJ-48 2048 steps per revolution 
const int MOTORSPEED = 10;

// IN1, IN3, IN2, IN4
Stepper myStepper(SPR, 9, 11, 10, 12);

void setup() {
  myStepper.setSpeed(MOTORSPEED);
}

void loop() {
  myStepper.step(4096);
  myStepper.step(-2048);
}
