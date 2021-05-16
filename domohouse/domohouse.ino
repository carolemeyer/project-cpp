/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
  https://www.go4expert.com/articles/writing-multithreaded-program-cpp-t29980/
*/

/*
Pour le moment :
-Romain : Servo pour la porte
          Capteur de temperature pour modification d'ambiance
          Matrice de LED pour la Télé
-Carole : Lampes commandées par le wifi
          Actionneurs sonores
-Léa : Door lock (capteur d'empreinte, détecteur de présence...)


Fichiers :
-weblink : wifi, serveur web
-kozy : lumières, musique

-zedoor : servo, capteur mdp
-amongueus : detection intru + alarme
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
*/

#include "includes.h"
#include "tempe.h"
#include "kozy.h"
#include "weblink.h"
#include "zedoor.h"

//class Led blueLed;
//class WifiModule weFee; //Si on veut créer un object avec le constructeur sans argument, ne pas mettre de parentheses
class MyAlarm intruzion;
class MyMood goodMood;

        // Set web server port number to 80
        //WiFiServer server(80);

void setup() {
  Serial.begin(115200);           // pour le debug au printf sur la console
  //blueLed.initialize(PIN_OnBoardBlueLED);         // Initializes the built-in blue led as an output
  //weFee.initialize();
  intruzion.initialize();
  goodMood.initialize();
}

// the loop function runs over and over again forever
void loop() {
  //blueLed.blinkLed();    // Blinks blue built-in led
  //weFee.boucleWifi();
  intruzion.alarmOn();
  goodMood.posey();
}
