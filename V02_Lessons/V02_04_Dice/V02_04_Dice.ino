/*
 * Project: Dice
 * Description: using switch case
 */
int die;
void setup() {
  Serial.begin(9600);
  while(!Serial);
}
void loop() {
  die = random(0,8);
  Serial.println(die);
  switch(die) {
    case 1:
      Serial.println("A one was rolled");
      break;
    case 2:
      Serial.println("A two was rolled");
      break;
    case 3:
      Serial.println("A three was rolled");
      break;
    case 4:
      Serial.println("A four was rolled");
      break;
    case 5:
      Serial.println("A five was rolled");
      break;
    case 6:
      Serial.println("A six was rolled");
      break;
    default:
      Serial.println("Invalid Roll");
      break;
  }
  delay(2000);
}
