#include <VirtualWire.h>

const int led_pin = 13;
const int transmit_pin = 14;
const int receive_pin = 2;
const int transmit_en_pin = 3;
uint8_t msg2;

void setup()
{

    Serial.begin(9600);  // Debugging only
    Serial.println("setup");
    pinMode(led_pin,OUTPUT);
  // Initialise the IO and ISR
  vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  vw_set_ptt_pin(transmit_en_pin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);   // Bits per sec
}

byte count = 1;

void loop()
{
  Serial.println("Preparing Data");
  //char msg[7] = {'h','e','l','l','o',' ','#'};
  char msg[5] = {'B','A','R',' ','#'};

  msg[4] = count;
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  delay(100);
  vw_send((uint8_t *)msg, sizeof(msg));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);
  delay(1000);
  count = count + 1;
}
