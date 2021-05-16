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

#define PIN_WhiteLED D5                 // Connects White LED to digital pin D5
#define PIN_RedLED D3                   // Connects Green LED to digital pin D3
#define PIN_OnBoardBlueLED LED_BUILTIN  // BuiltIn Blue LED is already on board
#define PIN_Buzzer D6                   // Connects Buzzer to digital pin D6


// Tempe.cpp
class Temperature caliente;

// Kozy.cpp
class Light jacquouilleLaFripouille;
class Led blueLed(PIN_OnBoardBlueLED);
class Led redLed(PIN_RedLED);
class Led whiteLed(PIN_WhiteLED);
class Buzzer buzzEclair(PIN_Buzzer); //Si on veut créer un object avec le constructeur sans argument, ne pas mettre de parentheses
//class Led blueLed;
//class WifiModule weFee; //Si on veut créer un object avec le constructeur sans argument, ne pas mettre de parentheses
class MyAlarm intruzion;
class MyMood goodMood;

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
  Serial.begin(115200);

  // Outputs
  blueLed.initialize();   // Initializes the built-in blue led as an output
  redLed.initialize();    // Initializes the red led as an output
  whiteLed.initialize();  // Initializes the white led as an output
  //blueLed.initialize(PIN_OnBoardBlueLED);         // Initializes the built-in blue led as an output
  //weFee.initialize();
  intruzion.initialize();
  goodMood.initialize();


  // Inputs
  caliente.initialize(pinTempSensor); // Initializes the temperature sensor as input
  jacquouilleLaFripouille.initialize(pinLightSensor); // Initializes the light sensor as input


  // A mettre dans le WebLink (maybe)
  Serial.print("\n\n\n");
  Serial.print("##############################\n");
  Serial.print("Your DomoHouse is starting....\n");
  Serial.print("DomoHouse started !\n");
  Serial.print("##############################\n");
}



// the loop function runs over and over again forever
void loop() {  
  jacquouilleLaFripouille.getLightLevel(pinLightSensor);
  caliente.getHeatLevel(pinTempSensor);
  
  //blueLed.blinkLed();    // Blinks blue built-in led
  intruzion.alarmOn();
  goodMood.posey();

  ProjetPorte1->initDoorProject(TouchPin, ServoPin);
  ProjetPorte1->runDoorProject(OpenDoorAngle, CloseDoorAngle, TimerOpenDoor2, TimerOpenDoor3);
  ProjetPorte1->afficheInfos();


}
