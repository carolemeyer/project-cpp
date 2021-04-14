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

#define pinLightSensor D6   // Light Sensor on D6
#define pinTempSensor A0    // Grove - Temperature Sensor connect to A0

class Light jacquouilleLaFripouille; // Jour, Nuit, Jour, Nuit
class Temperature caliente; // VAleur 

void setup() {

  Serial.begin(115200);
  
  jacquouilleLaFripouille.initialize(pinLightSensor);
  caliente.initialize(pinTempSensor);
}

void loop() {

  
  jacquouilleLaFripouille.getLightLevel(pinLightSensor);
  caliente.getHeatLevel(pinTempSensor);

  delay(200);
  
}
