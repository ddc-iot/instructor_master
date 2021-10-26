#include <VirtualWire.h>

const int led_pin = 13;
const int transmit_pin = 12;
const int receive_pin = 11;
const int transmit_en_pin = 3;
int i;

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
    vw_setup(2000);  // Bits per sec

    vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
    //Serial.println("Preparing to get data");
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      if(buf[2]='R') {
        Serial.printf("Brian's Initials (in HEX): ");
      }
      digitalWrite(led_pin, HIGH); // Flash a light to show received good message
      delay(250);
      // Message with a good checksum received, print it.
      for (i = 0; i < buflen; i++)
        {
        Serial.print(buf[i], HEX);
        Serial.print(' ');
      }
  Serial.println();

      digitalWrite(led_pin, LOW);
    }
}
