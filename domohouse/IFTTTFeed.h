#ifndef IFTTT_H
#define IFTTT_H

#include "includes.h"
#include <stdint.h>
#include "../generic/common.h"
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       "1234"
#define WLAN_PASS       "tegm1526"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   
#define AIO_USERNAME    "nidish75"
#define AIO_KEY         "aio_xSDu89ZKPpUwS5WoZogKCEIipyaI"



class IFTTTFeed{
    public:
        // Constructeurs et destructeurs
        IFTTTFeed();
        ~IFTTTFeed();

        // Fonctions annexes
        WiFiClient* clientWifi;
        Adafruit_MQTT_Client* mqtt;
        Adafruit_MQTT_Publish* publisher;
        Adafruit_MQTT_Subscribe* subscriber;

        std::string readFeed();
        void connectToFeed();
        void notifyFeed();
};


#endif 
