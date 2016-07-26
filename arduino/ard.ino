#include <RF24_config.h>
#include <printf.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(9, 10);

void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(0x72);
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  radio.enableDynamicPayloads();
  radio.powerUp();
}

void loop() {
  const char text[] = "uguyfhft";
  radio.write(&text, sizeof(text));
  
  int buttonState9 = digitalRead(9);
  Serial.println(buttonState9);
  int buttonState10 = digitalRead(10);
  Serial.println(buttonState10);
  delay(1000);
}
