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

class Led blueLed(PIN_OnBoardBlueLED);
class Led redLed(PIN_RedLED);
class Led whiteLed(PIN_WhiteLED);
//class Buzzer buzzEclair(PIN_Buzzer); //Si on veut créer un object avec le constructeur sans argument, ne pas mettre de parentheses
class Speaker dropTheMic(PIN_Speaker);
//class WifiModule weFee;

void setup() {
  Serial.begin(115200);         // pour le debug au printf sur la console
  //blueLed.initialize();         // Initializes the built-in blue led as an output
  //redLed.initialize();          // Initializes the red led as an output
  //whiteLed.initialize();        // Initializes the white led as an output
  //buzzEclair.initialize();
  dropTheMic.initialize();
  //weFee.initialize();
}

// the loop function runs over and over again forever
void loop() {
  //blueLed.blinkLed();    // Blinks blue built-in led
  //redLed.blinkLed();     // Blinks red led
  //whiteLed.blinkLed();   // Blinks white led
  //dropTheMic.musicOn();
  //dropTheMic.alarmOn();
  //buzzEclair.bipBuzzer();
  //buzzEclair.singSong();


}
