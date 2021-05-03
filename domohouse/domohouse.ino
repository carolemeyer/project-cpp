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

const auto TouchPin = D8;
const auto LedPin = D3;
const auto ServoPin = D7;

MonTouchSensor* Touch1;
MonServo* Servo1;

class Light jacquouilleLaFripouille; // Jour, Nuit, Jour, Nuit
class Temperature caliente; // VAleur
void setup() {
  Serial.begin(115200);
  Servo1 = new MonServo();           //setup des pin pour le servomoteur
  Touch1 = new MonTouchSensor(); //setup des pin pour le touch sensor et la LED




  //jacquouilleLaFripouille.initialize(pinLightSensor);
  //caliente.initialize(pinTempSensor);
}

void loop() {


  //Touch1->useTouchSensor();
  Touch1->initialize(TouchPin);
  Servo1->initialize(ServoPin);

  Touch1->getTouch();
  Touch1->AffichageEtatTouch();
  Touch1->getTimer();
  if  (Touch1->getTimer()>700) {
    Servo1->MovePos(180);
  }
  else if (Touch1->getTimer()==0){
    Servo1->MovePos(-180);
  }



  /*Temperature Temp1;
    Temp1.printTemperature();

    Kozy AmbianceTamisee;
    AmbianceTamisee.blinkOnBrdLED();
  */


  //jacquouilleLaFripouille.getLightLevel(pinLightSensor);
  //caliente.getHeatLevel(pinTempSensor);

  //delay(200);


}
