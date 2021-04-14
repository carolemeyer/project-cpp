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

const auto TouchPin = D5;
const auto LedPin = D3;
const auto ServoPin = D6;

MonTouchSensor* Touch1;
MonServo* Servo1;

void setup() {

  Servo1 = new MonServo(ServoPin);           //setup des pin pour le servomoteur
  Touch1 = new MonTouchSensor(TouchPin, LedPin); //setup des pin pour le touch sensor et la LED
}

void loop() {

  Touch1->useTouchSensor();
  Servo1->moveServo();
  /*Temperature Temp1;
    Temp1.printTemperature();

    Kozy AmbianceTamisee;
    AmbianceTamisee.blinkOnBrdLED();
  */
}
