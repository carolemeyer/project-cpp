#include "tempe.h"


void Temperature::printTemperature(void){
    int a = analogRead(pinTempSensor);
 
    float R = 1023.0/a-1.0;
    R = R0*R;
 
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
 
    Serial.print("Temperature = ");
    Serial.println(temperature);
 
    delay(100);
}
