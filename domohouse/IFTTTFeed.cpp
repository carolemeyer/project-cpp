#include "IFTTTFeed.h"

IFTTTFeed::IFTTTFeed(){
  clientWifi = new WiFiClient();
  mqtt = new Adafruit_MQTT_Client(clientWifi, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
  subscriber = new Adafruit_MQTT_Subscribe(mqtt, AIO_USERNAME "/feeds/smart-home");

  mqtt->subscribe(subscriber);
  connectToFeed();
}

IFTTTFeed::~IFTTTFeed(){}

void IFTTTFeed::connectToFeed(){

  // Stop if already connected.
  if (mqtt->connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");
  int8_t ret;
  uint8_t retries = 3;
  while ((ret = mqtt->connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt->connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt->disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}

// Fonction a appeler et checker si retour == "1"
std::string IFTTTFeed::readFeed(){
  connectToFeed();
  Adafruit_MQTT_Subscribe *subscription = mqtt->readSubscription(1000);
  if (subscription == subscriber) {
    // Retourne la valeur lue sur le feed
    return ((char *)subscriber->lastread);
  }
  return "";
}

void IFTTTFeed::notifyFeed(){
   connectToFeed();
   // Pour publier sur le feed : publisher->publish(1);  --- c'est l'autre équipe qui le fait
}
