/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
  https://www.go4expert.com/articles/writing-multithreaded-program-cpp-t29980/
*/

/*
  Fichiers :
  -weblink : wifi, serveur web
  -kozy : lumières, musique, télé
  -zedoor : servo, capteur mdp
  -amongueus : detection intru + alarme
*/


#include "includes.h"
#include "tempe.h"
#include "kozy.h"
#include "weblink.h"
#include "zedoor.h"

#define pinTempSensor   A0  // Grove - Temperature Sensor connect to A0
#define pinLightSensor  D3  // Light Sensor on D6
#define LedPin          D5
#define pinBuzzer       D6
#define ServoPin        D7
#define TouchPin        D8

// Tempe.cpp
class Temperature caliente;

// Kozy.cpp
class Light jacquouilleLaFripouille;



void setup() {
  Serial.begin(115200);

  jacquouilleLaFripouille.initialize(pinLightSensor);
  caliente.initialize(pinTempSensor);


  // A mettre dans le WebLink (maybe)
  Serial.print("\n\n\n");
  Serial.print("##############################\n");
  Serial.print("Your DomoHouse is starting....\n");
  Serial.print("DomoHouse started !\n");
  Serial.print("##############################\n");

}

void loop() {  
  jacquouilleLaFripouille.getLightLevel(pinLightSensor);
  caliente.getHeatLevel(pinTempSensor);
}
