//Dynamic Host Configuration protocol 
//(connect to rj45) (get dhcp address) - spoof mac id
#include <SPI.h>
#include <Ethernet.h>
#include <mac.h>

EthernetClient client;
bool status;

void setup() {
  
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);

  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  //Open Serial Communication and wait for port to open:
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Starting Program");

  //Start ethernet connection
  status = Ethernet.begin(mac);
  if (!status) {
    Serial.println("failed to configure Ethernet using DHCP");
    //no point in continueing 
    while(1);
    }
  //print your local IP address
  Serial.print("My IP address:");
  for (byte thisbyte = 0; thisbyte < 4; thisbyte++) {
    //print value of each byte of the IP address
    Serial.print(Ethernet.localIP()[thisbyte], DEC);
    if (thisbyte < 3) Serial.print(".");
    }
  Serial.println();
}

void loop() { }  //no loop
