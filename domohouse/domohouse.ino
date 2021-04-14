et C/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
*/
#include "tempe.h"
#include "kozy.h"
#include "weblink.h"

void setup() {
  //Serial.begin(9600);         // pour le debug au printf sur la console
  //configLED(LED_BUILTIN);     // Initializes the LED_BUILTIN pin as an output
  //configLED(PIN_WhiteLED);
  //configLED(PIN_GreenLED);
  //configBuzzer(PIN_Buzzer);
  configWifi();
}

// the loop function runs over and over again forever
void loop() {
  //blinkBlueLed();           // Blinks blue LED built-in
  //blinkLed(PIN_WhiteLED);          // Blinks green LED
  //blinkLed(PIN_GreenLED);
  //printTemperature();
  //bipBuzzer(PIN_Buzzer);
  //singSong();
  boucleWifi();
}
