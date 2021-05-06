/*
 * Author : Lea Pitault
 * 
 * 
 */

#ifndef ZEDOOR_H
#define ZEDOOR

#include "includes.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE TOUCHSENSOR
///////////////////////////////////////////////////////////////////////////////////////////////////

class MonTouchSensor : public Sensor, public Digital
{
public:
  //----------------------------constructeurs----------------------------//
  MonTouchSensor();
  
  //---------------------------- destructeur ----------------------------//
  ~MonTouchSensor();

  //----------------------------- fonctions -----------------------------//
  virtual void initialize(int pinNb) override;
  boolean getTouch(); //methode propre a la classe N+1 touchSensor
  void affichageEtatTouch();
  int getTimer() ;

protected:
int touchPin;
int timer;
boolean touch_OK;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SERVOMOTEUR
///////////////////////////////////////////////////////////////////////////////////////////////////

class MonServo : public Actuator, public Digital
{
public:
  //----------------------------constructeurs----------------------------//
  MonServo();

  //---------------------------- destructeur ----------------------------//
  ~MonServo();

  //----------------------------- fonctions -----------------------------//
  virtual void initialize(int pinNb) override;
  
  //void moveServo(); //methode propre a la classe N+1 doorServo
  void movePos(int pos);


protected:
//int servoPin;
Servo myservo;
};


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE PORTE
///////////////////////////////////////////////////////////////////////////////////////////////////
class MaPorte : private MonServo
{
public:
  //----------------------------constructeurs----------------------------//
  MaPorte();
  
  //---------------------------- destructeur ----------------------------//
  ~MaPorte();

  //----------------------------- fonctions -----------------------------//
  void initPorte(int pinServo);
  void movePorte(int pos);

protected:
MonServo cerveau;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//             CLASSE Door_PROJET
///////////////////////////////////////////////////////////////////////////////////////////////////
class DoorProject : private MaPorte, private MonTouchSensor
{
public:
  //----------------------------constructeurs----------------------------//
  DoorProject();
  
  //---------------------------- destructeur ----------------------------//
  ~DoorProject();

  //----------------------------- fonctions -----------------------------//
  void initDoorProject(int pinSensor, int pinServo);
  void runDoorProject(int posOpen, int posClose, int timer1);

protected:
MaPorte porte;
MonTouchSensor touchS;

};


#endif //ZEDOOR_H
