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
    //timer++;
  }
  else {
    touch_OK = false;
    //if ((timer--) <= 0) {
    //timer = 0;
    // }
  }
  return touch_OK;

}

int MonTouchSensor::getTimer() {
  return timer;
}

void MonTouchSensor::affichageEtatTouch() {
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

void MonServo::movePos(int pos) {
  myservo.write(pos);
}

int MonServo::readPos() {
  return myservo.read();
}


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE PORTE
///////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------constructeurs----------------------------//

MaPorte::MaPorte(): MonServo() {
}


//---------------------------- destructeur ----------------------------//

MaPorte::~MaPorte() {
}

//----------------------------fonctions----------------------------//

//fonction d'initialisation de la porte
void MaPorte::initPorte(int pinServo) {
  cerveau.initialize(pinServo); //ou faire MonServo::initialize(pinServo);
}

void MaPorte::movePorte(int pos) {
  cerveau.movePos(pos);
}

int MaPorte::getPosPorte() {
  return cerveau.readPos();
}


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE Door_PROJET
///////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------constructeurs----------------------------//

DoorProject::DoorProject(): MaPorte(), MonTouchSensor() {
}


//---------------------------- destructeur ----------------------------//

DoorProject::~DoorProject() {
}

//----------------------------fonctions----------------------------//

//fonction d'initialisation de la porte
void DoorProject::initDoorProject(int pinSensor, int pinServo) {
  porte.initPorte(pinServo); //ou faire MonServo::initialize(pinServo);
  touchS.initialize(pinSensor); //MonTouchSensor::initialize(pinSensor);
  //porte.movePorte(0);
}


void DoorProject::runDoorProject(int posOpen, int posClose, int timer1, int timer2) {
  //static int timerDoor = 0;
  //int timerOpen;
  //static int oldEtat;
  if  (touchS.getTouch() == true) {
    setOldTouch(touchS.getTouch());
    timerAdd();
  } else {
    if ((getOldEtat() == 1) && (porte.getPosPorte() == posOpen)) {
      setDoorTimerOpen(getDoorTimer());
      //timerOpen = getDoorTimer();
    }
    setOldTouch(touchS.getTouch());
    if (getDoorTimer() > 0) {
      timerSub();
    }
  }
  if  ((getDoorTimer() > timer1)) { // && (porte.getPosPorte() != posOpen)) {
    porte.movePorte(posOpen);
  }
  if ((getDoorTimer() <= (getDoorTimerOpen() - timer2)) ) { //&& (porte.getPosPorte() != posClose)) {
    porte.movePorte(posClose);
    setDoorEtat(1);
    //setTimerNull(); //remettre le timer à 0 quand j'ai fermé la porte
  }
  if (getDoorEtat() == 1) {
    setTimerNull();
    setDoorEtat(0);
  }

}


void DoorProject::timerAdd() {
  timerDoor++;
}

void DoorProject::timerSub() {
  timerDoor--;
}

void DoorProject::setTimerNull() {
  timerDoor = 0;
}

int DoorProject::getDoorTimer() {
  return timerDoor;
}

int DoorProject::getDoorTimerOpen() {
  return timerOpen;
}

void DoorProject::setDoorTimerOpen(int timer) {
  timerOpen = timer;
}

int DoorProject::getOldEtat() {
  return oldEtat;
}

void DoorProject::setOldTouch(int etat) {
  oldEtat = etat;
}

int DoorProject::getDoorEtat() {
  return doorClosed;
}

void DoorProject::setDoorEtat(int doorState) {
  doorClosed = doorState;
}

void DoorProject::afficheInfos() {
  //if (touchS.getTouch() == true) {

  Serial.print("Etat du touch : " );
  Serial.println(touchS.getTouch());
  Serial.print("Etat du timer : " );
  Serial.println(getDoorTimer());
  Serial.print("Etat du timerOpen : " );
  Serial.println(getDoorTimerOpen());
  Serial.print("Pos de la porte : " );
  Serial.println(getPosPorte());


  //}
}
