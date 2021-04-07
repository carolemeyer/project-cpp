# 1 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
/*

  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault

*/
# 5 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
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
# 24 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
# 25 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino" 2
# 26 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino" 2
# 27 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino" 2
# 28 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino" 2
# 29 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino" 2

void setup() {
  pinMode(2, 0x01); // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  printTemperature();
  blinkBlueLed();
}
