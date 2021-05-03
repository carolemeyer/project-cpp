#include "zedoor.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE TOUCHSENSOR
///////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------constructeurs----------------------------//

MonTouchSensor::MonTouchSensor() {
}

/*MonTouchSensor::MonTouchSensor(int TouchP, int LedP): touchPin(TouchP), ledPin(LedP) {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  }*/

//---------------------------- destructeur ----------------------------//

MonTouchSensor::~MonTouchSensor() {
}

//----------------------------fonctions----------------------------//

//fonction d'initialisation virtuelle issue de Sensor
void MonTouchSensor::initialize(int pinNb) {
  pinMode(pinNb, INPUT);
  touchPin = pinNb;
}

//fonction qui retourne le booléen indiquant si le touchSensor est touché ou non

boolean MonTouchSensor::getTouch() {
  int sensorValue = digitalRead(touchPin);
  if (sensorValue == 1)
  {
    touch_OK = true;
    timer++;
  }
  else {
    touch_OK = false;
    if ((timer--) <= 0) {
      timer = 0;
    }
  }
  return touch_OK;

}

int MonTouchSensor::getTimer() {
  return timer;
}

void MonTouchSensor::AffichageEtatTouch() {
  Serial.print("Etat du touch : " );
  Serial.println(touch_OK);
  Serial.print("Etat du timer : " );
  Serial.println(timer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SERVOMOTEUR
///////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------constructeurs----------------------------//

MonServo::MonServo() {
}


//---------------------------- destructeur ----------------------------//

MonServo::~MonServo() {
}

//----------------------------fonctions----------------------------//

//fonction d'initialisation virtuelle issue de Sensor
void MonServo::initialize(int pinNb) {
  myservo.attach(pinNb);
}

/*void MonServo::moveServo() {
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
  }*/

void MonServo::MovePos(int pos) {
  myservo.write(pos);
}
