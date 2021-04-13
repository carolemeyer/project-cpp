/*
 * Author : Lea Pitault
 */

#ifndef ZEDOOR_H
#define ZEDOOR

#include "includes.h"

class touchSensor
{
public:
  //----------------------------constructeurs----------------------------//
  touchSensor();

  touchSensor(int TouchP, int LedP);

  //---------------------------- destructeur ----------------------------//
  ~touchSensor();

  //----------------------------- fonctions -----------------------------//
  //void initSensor(int TouchP, int LedP); //issue de la classe N Classes
  void useTouchSensor(); //methode propre a la classe N+1 touchSensor

protected:
int touchPin;
int ledPin;
};



#endif //ZEDOOR_H
