#include "zedoor.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE TOUCHSENSOR
///////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------constructeurs----------------------------//

MonTouchSensor::MonTouchSensor() {}

//---------------------------- destructeur ----------------------------//

MonTouchSensor::~MonTouchSensor() {}

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
    touchOK = true;
  }
  else {
    touchOK = false;
  }
  return touchOK;

}

int MonTouchSensor::getTimer() {
  return timer;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SERVOMOTEUR
///////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------constructeurs----------------------------//

MonServo::MonServo() {}

//---------------------------- destructeur ----------------------------//

MonServo::~MonServo() {}

//----------------------------fonctions----------------------------//

//fonction d'initialisation virtuelle issue de Sensor
void MonServo::initialize(int pinNb) {
  myservo.attach(pinNb);
}

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

MaPorte::MaPorte(): MonServo() {}

//---------------------------- destructeur ----------------------------//

MaPorte::~MaPorte() {}

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

DoorProject::DoorProject(): MaPorte(), MonTouchSensor() {}

//---------------------------- destructeur ----------------------------//

DoorProject::~DoorProject() {}

//----------------------------fonctions----------------------------//

//fonction d'initialisation de la porte
void DoorProject::initDoorProject(int pinSensor, int pinServo, int posClose) {
  porte.initPorte(pinServo); //ou faire MonServo::initialize(pinServo);
  touchS.initialize(pinSensor); //MonTouchSensor::initialize(pinSensor);
  alarm.initialize(); //initialisation de l'alarme
  //initialisation de la porte à l'état fermé
  setDoorPos(posClose);
  setIntrusion(false);
}

void DoorProject::runDoorProject(int posOpen, int posClose, int timer1, int timer2) {
  if (getIntrusion() == false) {
    if  (touchS.getTouch() == true) {
      setOldTouch(touchS.getTouch());
      timerAdd();
      //Déclenchement de l'alarme si l'utilisation reste appuyé le double du temps nécessaire
      if (getDoorTimer() > (2 * timer1)) {
        alarm.alarmOn();
        setIntrusion(true);
      }
    } else { //si on n'appuie plus sur le sensor
      //si l'ancien etat etait appuyé et que la porte est ouverte
      if (getOldTouch() == 1) {
        if (getDoorPos() == posOpen) {
          //on retient le moment auquel on relache le sensor
          setDoorTimerOpen(getDoorTimer());
        }
        //on remet à zero le timer si on relache avant que la porte ne se soit ouverte
        else if (getDoorPos() == posClose) {
          setTimerNull();
        }
      }
      setOldTouch(touchS.getTouch()); //MAJ de l'ancien état du sensor (=0 maintenant)
      //si on le timer est positif, on le décrémente tant qu'on appuit pas sur le sensor
      if (getDoorTimer() > 0) {
        timerSub();
      }
    }
    //si le timer est supérieur au timer choisi et que la porte n'est pas ouverte
    if  ((getDoorTimer() > timer1) && (getDoorPos() != posOpen)) {
      //alors on ouvre la porte
      setDoorPos(posOpen);
    }
    //si le timer est inférieur au dernier temps où on a laché le sensor moins le timer choisi pour fermer la porte
    if ((getDoorTimer() <= (getDoorTimerOpen() - timer2))  && (getDoorPos() == posOpen)) {
      //on ferme la porte
      setDoorPos(posClose);
      //on remet le timer à 0
      setTimerNull(); //remettre le timer à 0 quand j'ai fermé la porte
      setDoorTimerOpen(0);
    }
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

int DoorProject::getOldTouch() {
  return oldTouch;
}

void DoorProject::setOldTouch(int etat) {
  oldTouch = etat;
}

int DoorProject::getDoorEtat() {
  return doorClosed;
}

void DoorProject::setDoorEtat(int doorState) {
  doorClosed = doorState;
}

int DoorProject::getDoorPos() {
  return porte.getPosPorte();
}

void DoorProject::setDoorPos(int pos) {
  porte.movePorte(pos);
}

boolean DoorProject::getIntrusion() {
  return intrusion;
}

void DoorProject::setIntrusion(boolean intru) {
  intrusion = intru;
}

void DoorProject::afficheInfos() {
  //if (touchS.getTouch() == true) {

  Serial.print("Etat du touch : " );
  Serial.println(touchS.getTouch());
  Serial.print("Etat du timer : " );
  Serial.println(getDoorTimer());
  Serial.print("Etat du timerOpen : " );
  Serial.println(getDoorTimerOpen());
  Serial.print("Pos de la porte final : " );
  Serial.println(getDoorPos());


  //}
}
