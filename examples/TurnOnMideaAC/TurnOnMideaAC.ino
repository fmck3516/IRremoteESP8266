#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Midea.h>
#include <IRutils.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRMideaAC ac(kIrLed);  // Set the GPIO used for sending messages.

void setup() {
  ac.begin();
  Serial.begin(115200);
  delay(200);

  ac.on();
  // recorded using IRrecvDumpV2 & Mr Cool 4th gen remote control RG10A4(D1)/BGEFU1
  ac.setRaw(0xA1A06AFFFF44);  
  ac.setBeep(false);
}

void loop() {
  ac.send();
  Serial.println("Description: " + ac.toString());
  Serial.println("Hex:         " + uint64ToString(ac.getRaw(), 16));
  delay(5000);
}
