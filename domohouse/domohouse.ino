/*
  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault
  Context: 4th year C++ course at INSA de Toulouse 

  Files:
  - classes.h   : definition of the basic classes for sensors and actuators, analog or digital
  - includes.h  : shall include all the libraries we need for this project and define pin numbers and other values
  - weblink     : wifi, web server
  - kozy        : refrigerator, (LED) lights, (Buzzer) music, intrusion alarm
  - zedoor      : servo, door opening sensor
  - IFTTTFeed   : all the code needed to log in, subscribe and track the feed of the neighbours

  Modes: 
  The DomoHouse has two functioning modes. The user can chose between one mode or the other by modifying the 
  line "#define MODE 0" just below.
    >>> NORMAL MODE : to use this mode, please define MODE as 0. 
      In this mode you can: 
        - Use and add something in the refrigerator using the serial monitor
        - Activate lights and nice music depending on the temperature (over 28°C)
        - Open the door by touching the sensor next to it for a short time (about one second)
        - Trigger an intrusion alarm by touching the sensor for too long
    >>> DOMOTIK (WiFi) MODE : to use this mode, please define MODE as 1. 
      In this mode you can take over the house with your phone, once they are connected to the same WiFi network.
      Then, if an intrusion is detected in another team's house, it triggers ours too.
      To connect the house to your phone, please follow these instructions: 
        - Activate the WiFi access point on your phone
        - Enter the network credentials in weblink.cpp as :
            --> const char* ssid     = "name-of-your-wifi-network";
            --> const char* password = "password-of-your-wifi-network";
        - Open the serial monitor, it will give you an IP address
        - Enter this IP address on your favorite browser
        - Congratulations, you accessed the house's dedicated web page!
  
  Specifications and where to find them (in French): 
  - Création de plusieurs classes       : classes.h, module kozy, module tempe, module zedoor
  - Utilisation du mécanisme d'héritage : module kozy, module tempe, module zedoor
  - Redéfinition d'opérateur            : dans la classe Led du module Kosy redéfinition de l'opérateur =
                                          pour les Leds par "Led & operator= (const Led & other);"
  - Utilisation de la STL               : dans la classe MyFridge du module Kosy car le contenu du frigo 
                                          est stocké sous forme de liste
  - Utilisation des exceptions          : dans la fonction choseAngle du module Zedoor
*/

//// OUR OWN FILES ////
#include "includes.h"
#include "tempe.h"
#include "kozy.h"
#include "weblink.h"
#include "zedoor.h"
#include "IFTTTFeed.h"

// HERE YOU DEFINE WHETHER YOU WANT TO USE THE HOUSE IN NORMAL OR DOMOTIK (WIFI) MODE
#define MODE 1 // MODE 0 is Normal mode ; MODE 1 is Domotik (Wifi) mode ;

#if (MODE==0) // NORMAL MODE

//// CLASS INSTANCIATIONS //// //Si on veut créer un object avec le constructeur sans argument, ne pas mettre de parentheses
// Tempe.cpp
class Temperature heatsup;
// Kozy.cpp
//class Light jacquouilleLaFripouille; // Non implementee mais ce fut une possibilité
class MyAlarm intruzion;
class MyMood goodMood;
class MyFridge monFrigo;
// Zedoor.cpp
DoorProject* ProjetPorte1;

//// INIT //// the setup runs once once at the start
void setup() {
  Serial.begin(115200);
  // Writes a nice welcoming message on your serial monitor
  welcome();

  // Here we initilize the class instances we are using in this project
  // Tempe.cpp
  heatsup.initialize(PIN_TempSensor);
  // Kozy.cpp
  intruzion.initialize();
  goodMood.initialize();
  monFrigo.initialize();
  // Zedoor.cpp
  ProjetPorte1 = new DoorProject();
  ProjetPorte1->initDoorProject(PIN_TouchPin, PIN_ServoPin, CloseDoorAngle);

  // Asks you if you want to use the refrigerator on the serial monitor and takes care of the rest
  monFrigo.use();
}

//// LOOP //// the loop function runs over and over again forever
void loop() {  
  // If the temperature is over 28°C, it triggers lights and nice music to go along with this good mood
  // Kosy.cpp
  if (heatsup.getHeatLevel(PIN_TempSensor) > 28.0) goodMood.posey();
  
  // Detects anyone trying to enter through the door, let it be a friendly guest or an intruder
  // Zedoor.cpp
  ProjetPorte1->runDoorProject(OpenDoorAngle, CloseDoorAngle, TimerOpenDoor1, TimerOpenDoor2);
  ProjetPorte1->afficheInfos();
}

#else // DOMOTIK (WIFI) MODE

//// INIT ////

IFTTTFeed* Feed;

void setup() {
  Serial.begin(115200);
  // Writes a nice welcoming message on your serial monitor
  welcome();

  // Here we initilize the web server we are using in the wifi mode
  // Weblink.cpp
  initializeWifi();

  // IFTTFeed.cpp
  Feed = new IFTTTFeed();
}

//// LOOP //// the loop function runs over and over again forever
void loop() {  
  // Starts the Wifi module
  // Weblink.cpp
  startWifi();

  // Read feed
  string value = Feed->readFeed();
}

#endif

void welcome(void) {
  Serial.println("\n\n\n");
  Serial.println("#####################################################");
  Serial.println("##            Welcome to the DomoHouse             ##");
  Serial.println("## By Romain Choulot, Carole Meyer and Lea Pitault ##");
  Serial.println("#####################################################");
}
