#include <Arduino.h>
#line 1 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
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
-kozy : lumières, musique, télé

-zedoor : servo, capteur mdp
-amongueus : detection intru + alarme
*/


#include "includes.h"
#include "tempe.h"
#include "kozy.h"
#include "weblink.h"
#include "zedoor.h"

#line 31 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
void setup();
#line 36 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
void loop();
#line 31 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
void setup() {
  pinMode(LED, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
}

void loop() {
  Temperature Temp1;
  Temp1.printTemperature();

  Kozy AmbianceTamisee;
  AmbianceTamisee.blinkOnBrdLED();
}

