#include "zedoor.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE TOUCHSENSOR
///////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------constructeurs----------------------------//

MonTouchSensor::MonTouchSensor() {
}

MonTouchSensor::MonTouchSensor(int TouchP, int LedP): touchPin(TouchP), ledPin(LedP) {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

//---------------------------- destructeur ----------------------------//

MonTouchSensor::~MonTouchSensor() {
}

//----------------------------fonctions----------------------------//

//fonction d'initialisation virtuelle issue de Sensor
/*void MonTouchSensor::initialize(int pinNb) {
  pinMode(pinNb, INPUT);
}*/


void MonTouchSensor::useTouchSensor() {

  int sensorValue = digitalRead(touchPin);
  if (sensorValue == 1)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SERVOMOTEUR
///////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------constructeurs----------------------------//

MonServo::MonServo() {
}

MonServo::MonServo(int ServoPin): servoPin(ServoPin) {
  myservo.attach(servoPin);
}

//---------------------------- destructeur ----------------------------//

MonServo::~MonServo() {
}

//----------------------------fonctions----------------------------//

void MonServo::moveServo() {
  int pos = 0;
  for (pos = 0; pos <= 180; pos += 1) {     // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) {     // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}
