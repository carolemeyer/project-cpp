#include <Arduino.h>
#line 1 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
*/
#include "tempe.h"

#line 6 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
void setup();
#line 12 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
void loop();
#line 6 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  printTemperature();
  blinkBlueLed();
}

