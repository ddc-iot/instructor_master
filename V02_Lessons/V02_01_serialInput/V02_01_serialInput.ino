/*
 * Project : serialInput
 * Description : take characters from the Serial Input and convert to an integrer
 * Auther : Brian Rashap
 * Date : 15-Mar-2020
 */


/* Note : A String is a class of objects that behave
 * like an array of char ( individual characters )
 * And , because it is an object , as we will see below ,
 * it has methods associated with it.
 */

String inString ;
int myValue ;
int inChar ;

void setup () {
Serial.begin (9600) ;
while(!Serial);

Serial.println("Beginning String to Int():");
inString = ""; // ensure the string is blank to begin with
}

void loop () {
while (Serial.available() > 0) { // read serial input
  inChar = Serial.read();
  if (isDigit(inChar)) {
  inString += ( char ) inChar ; // convert incoming byte to char and add to string
  }
  if (inChar == '\n') { // '\n' represents the btye for newline (or enter )
    myValue = inString.toInt ();
    Serial.print("Value: ");
    Serial.println(myValue);
    Serial.print("String: ");
    Serial.println(inString);
    inString = ""; // reset string for next input
    }
  }
}
