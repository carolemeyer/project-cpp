/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
  https://www.go4expert.com/articles/writing-multithreaded-program-cpp-t29980/
*/

/*
  Fichiers :
  -weblink : wifi, serveur web
  -kozy : lumières, musique
  -zedoor : servo, capteur mdp
  -amongueus : detection intru + alarme
*/


//// OUR OWN FILES ////
#include "includes.h"
#include "tempe.h"
#include "kozy.h"
#include "weblink.h"
#include "zedoor.h"

//// CLASS INSTANCIATIONS //// //Si on veut créer un object avec le constructeur sans argument, ne pas mettre de parentheses
// Tempe.cpp
//class Temperature caliente;
class Temperature heatsup;
// Kozy.cpp
//class Light jacquouilleLaFripouille; // Jour, Nuit, Jour, Nuit
class MyAlarm intruzion;
class MyMood goodMood;
// Zedoor.cpp
DoorProject* ProjetPorte1;
// Weblink.cpp
//class WifiModule weFee; 

//// INIT ////
void setup() {
  Serial.begin(115200);
  // Tempe.cpp
  heatsup.initialize(PIN_TempSensor);
  //caliente.initialize(PIN_TempSensor);  // Initializes the temperature sensor as input
  // Kozy.cpp
  //jacquouilleLaFripouille.initialize(PIN_LightSensor); // Initializes the light sensor as input
  intruzion.initialize();
  goodMood.initialize();
  // Zedoor.cpp
  ProjetPorte1 = new DoorProject();
  ProjetPorte1->initDoorProject(PIN_TouchPin, PIN_ServoPin, CloseDoorAngle);
  // Weblink.cpp
  //weFee.initialize();
}



// the loop function runs over and over again forever
void loop() {  
  // Tempe.cpp
  //caliente.getHeatLevel(PIN_TempSensor);
  // Kosy.cpp
  //jacquouilleLaFripouille.getLightLevel(pinLightSensor);
  //intruzion.alarmOn();
  if (heatsup.getHeatLevel(PIN_TempSensor) > 28.0) goodMood.posey();
  // Zedoor.cpp
  ProjetPorte1->runDoorProject(OpenDoorAngle, CloseDoorAngle, TimerOpenDoor1, TimerOpenDoor2);
  ProjetPorte1->afficheInfos();
  // Weblink.cpp
  //weFee.boucleWifi();
}
