et C/*
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

void setup() {
  //Serial.begin(9600);         // pour le debug au printf sur la console
  //configLED(LED_BUILTIN);     // Initializes the LED_BUILTIN pin as an output
  //configLED(PIN_WhiteLED);
  //configLED(PIN_GreenLED);
  //configBuzzer(PIN_Buzzer);
  configWifi();
  
  pinMode(LED, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
}

void loop() {

  //blinkBlueLed();           // Blinks blue LED built-in
  //blinkLed(PIN_WhiteLED);          // Blinks green LED
  //blinkLed(PIN_GreenLED);
  //printTemperature();
  //bipBuzzer(PIN_Buzzer);
  //singSong();
  boucleWifi();

  Temperature Temp1;
  Temp1.printTemperature();

  Kozy AmbianceTamisee;
  AmbianceTamisee.blinkOnBrdLED();
}
