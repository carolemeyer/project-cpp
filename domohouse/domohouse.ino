/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault

  Fichiers :
  - classes   : définition des classes de base pour actionneurs et capteurs, analogiques ou numériques
  - includes  : chargé d'inclure toutes les bibliothèques qui vont bien et fixer les pins et autres valeurs
  - weblink   : wifi, serveur web
  - kozy      : frigo, lumières, musique
  - zedoor    : servo, capteur ouverture de porte
  - amongueus : detection intru + alarme
*/

//// OUR OWN FILES ////
#include "includes.h"
#include "tempe.h"
#include "kozy.h"
#include "weblink.h"
#include "zedoor.h"

// HERE YOU DEFINE WHETHER YOU WANT TO USE THE HOUSE IN NORMAL OR DOMOTIK (WIFI) MODE
#define MODE 1 // MODE 0 is Normal mode ; MODE 1 is Domotik (Wifi) mode ;

#if (MODE==0) // NORMAL MODE

//// CLASS INSTANCIATIONS //// //Si on veut créer un object avec le constructeur sans argument, ne pas mettre de parentheses
// Tempe.cpp
class Temperature heatsup;
// Kozy.cpp
//class Light jacquouilleLaFripouille; // Non implementee mais ce fut une possibilité
class MyAlarm intruzion;
class MyMood goodMood;
class MyFridge monFrigo;
// Zedoor.cpp
DoorProject* ProjetPorte1;

//// INIT //// the setup runs once once at the start
void setup() {
  Serial.begin(115200);
  welcome();
  
  // Tempe.cpp
  heatsup.initialize(PIN_TempSensor);
  // Kozy.cpp
  intruzion.initialize();
  goodMood.initialize();
  monFrigo.initialize();
  // Zedoor.cpp
  ProjetPorte1 = new DoorProject();
  ProjetPorte1->initDoorProject(PIN_TouchPin, PIN_ServoPin, CloseDoorAngle);

  monFrigo.use();
}

//// LOOP //// the loop function runs over and over again forever
void loop() {  
  // Kosy.cpp
  if (heatsup.getHeatLevel(PIN_TempSensor) > 28.0) goodMood.posey();
  // Zedoor.cpp
  ProjetPorte1->runDoorProject(OpenDoorAngle, CloseDoorAngle, TimerOpenDoor1, TimerOpenDoor2);
  ProjetPorte1->afficheInfos();
}

#else // DOMOTIK (WIFI) MODE

//// INIT ////
void setup() {
  Serial.begin(115200);
  welcome();
  
  // Weblink.cpp
  initializeWifi();
}

//// LOOP //// the loop function runs over and over again forever
void loop() {  
  // Weblink.cpp
  startWifi();
}

#endif

void welcome(void) {
  Serial.println("\n\n\n");
  Serial.println("#####################################################");
  Serial.println("##            Welcome to the DomoHouse             ##");
  Serial.println("## By Romain Choulot, Carole Meyer and Lea Pitault ##");
  Serial.println("#####################################################");
}
