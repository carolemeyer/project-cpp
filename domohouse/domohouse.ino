/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
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

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  printTemperature();
  blinkBlueLed();
}
