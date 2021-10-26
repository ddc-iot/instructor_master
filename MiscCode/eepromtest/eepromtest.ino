#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>


#define LED_PIN    17
#define LED_COUNT   6
Adafruit_NeoPixel pixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int addr = 42;

int color;
int red;
int green;
int blue;

void setup() {

  Serial.begin(9600);
  while(!Serial);
  pinMode(A0,INPUT_PULLUP);
  pixel.begin();           
  pixel.show();            
  pixel.setBrightness(20); 
  color=fromEEPROM();
  Serial.printf("Last: 0x%06X \n",color);

}

void loop() {

  if(!digitalRead(A0)) {
    color = random(0x000000,0xFFFFFF); 
      Serial.printf("Color = 0x%06X \n",color);
      toEEPROM(color); 
  }
  pixel.setPixelColor(0,color);
  pixel.show();
  delay(200);
}

void toEEPROM(int number) {
  blue = number & 0x0000FF;
  //Serial.printf("Blue = %02X \n",blue);
  EEPROM.write(addr,blue);

  green = (number >> 8) & 0x0000FF;
  //Serial.printf("Green = %02X \n",green);
  EEPROM.write(addr+1,green);

  red = (number >> 16) & 0x0000FF;
  //Serial.printf("Red = %02X \n",red);
  EEPROM.write(addr+2,red);
}

int fromEEPROM() {
  return ((EEPROM.read(addr+2)<<16)+(EEPROM.read(addr+1)<<8)+EEPROM.read(addr));
}
