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

const auto OpenDoorAngle = 180;
const auto CloseDoorAngle = -180;
const auto TimerOpenDoor1 = 400;
const auto TimerOpenDoor2 = 100;
const auto TimerOpenDoor3 = 50;

//MonTouchSensor* Touch1;
//MonServo* Servo1;
//MaPorte* Porte1;
DoorProject* ProjetPorte1;

class Light jacquouilleLaFripouille; // Jour, Nuit, Jour, Nuit
class Temperature caliente; // VAleur
void setup() {
  Serial.begin(38400);
  //Serial.begin(115200);
  //Servo1 = new MonServo();           //setup des pin pour le servomoteur
  //Touch1 = new MonTouchSensor(); //setup des pin pour le touch sensor et la LED
  //Porte1 = new MaPorte();
  ProjetPorte1 = new DoorProject();


  //jacquouilleLaFripouille.initialize(pinLightSensor);
  //caliente.initialize(pinTempSensor);
}

void loop() {


  ProjetPorte1->initDoorProject(TouchPin, ServoPin);
  ProjetPorte1->runDoorProject(OpenDoorAngle, CloseDoorAngle, TimerOpenDoor2, TimerOpenDoor3);
  ProjetPorte1->afficheInfos();


  /*Temperature Temp1;
    Temp1.printTemperature();

    Kozy AmbianceTamisee;
    AmbianceTamisee.blinkOnBrdLED();
  */


  //jacquouilleLaFripouille.getLightLevel(pinLightSensor);
  //caliente.getHeatLevel(pinTempSensor);

  //delay(200);


}
