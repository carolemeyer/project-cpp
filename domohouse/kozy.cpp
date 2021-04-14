  #include "kozy.h"


int Light::initialize(int pinNb) {
  pinMode(pinNb, INPUT);
}


int Light::getLightLevel(int pinNb) {
  value = digitalRead(pinNb);
  Serial.print("Light Level = ");
  Serial.println(value);
}
