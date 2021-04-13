#include "zedoor.h"



//----------------------------constructeurs----------------------------//


touchSensor::touchSensor() {
}

touchSensor::touchSensor(int TouchP, int LedP): touchPin(TouchP),ledPin(LedP) {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

//---------------------------- destructeur ----------------------------//

touchSensor::~touchSensor() {
}

//----------------------------fonctions----------------------------//

void touchSensor::useTouchSensor() {
    int sensorValue = digitalRead(touchPin);
    if(sensorValue==1)
    {
        digitalWrite(ledPin,HIGH);
    }
    else
    {
        digitalWrite(ledPin,LOW);
    }
}
