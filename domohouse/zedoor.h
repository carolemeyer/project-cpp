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
  void AffichageEtatTouch();
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

  //MonServo(int ServoPin);

  //---------------------------- destructeur ----------------------------//
  ~MonServo();

  //----------------------------- fonctions -----------------------------//
  virtual void initialize(int pinNb) override;
  
  void moveServo(); //methode propre a la classe N+1 doorServo
  void MovePos(int pos);


protected:
int servoPin;
Servo myservo;
};



#endif //ZEDOOR_H
