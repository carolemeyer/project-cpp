#include "tempe.h"


void Temperature::initialize(int pinNb) {
  pinMode(pinNb, INPUT);
}

/*
void Temperature::getHeatLevel(int pinNb) {
    value = analogRead(pinNb);
    float R = 1023.0/value-1.0;
    R = R0*R;
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // Convert to temperature via datasheet
 
    Serial.print("Temperature = ");
    Serial.println(temperature);
}
*/
