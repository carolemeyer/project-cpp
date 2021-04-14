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

class MonTouchSensor
{
public:
  //----------------------------constructeurs----------------------------//
  MonTouchSensor();

  MonTouchSensor(int TouchP, int LedP);

  //---------------------------- destructeur ----------------------------//
  ~MonTouchSensor();

  //----------------------------- fonctions -----------------------------//
  void useTouchSensor(); //methode propre a la classe N+1 touchSensor

protected:
int touchPin;
int ledPin;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SERVOMOTEUR
///////////////////////////////////////////////////////////////////////////////////////////////////

class MonServo
{
public:
  //----------------------------constructeurs----------------------------//
  MonServo();

  MonServo(int ServoPin);

  //---------------------------- destructeur ----------------------------//
  ~MonServo();

  //----------------------------- fonctions -----------------------------//
  //virtual void initialize(int pinNb);
  void moveServo(); //methode propre a la classe N+1 doorServo

protected:
int servoPin;
Servo myservo;
};



#endif //ZEDOOR_H
