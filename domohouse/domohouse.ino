/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
*/
#include "tempe.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  printTemperature();
  blinkBlueLed();
}
