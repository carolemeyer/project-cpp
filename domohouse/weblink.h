#include <Arduino.h>
#include "kozy.h"

// Load Wi-Fi library
#include <ESP8266WiFi.h>

#define SERVER_PORT 80

//WiFi module

class WifiModule {
    public :
        // Constructeurs
        WifiModule();
        ~WifiModule();
        // Public functions
        int initialize(); //Configuration of the Wifi Module
        void boucleWifi(); //Functionning loop for the Wifi Module
    private :
        // Set web server port number to 80
        //WiFiServer server(SERVER_PORT);

        // Assign output variables to GPIO pins
        const int outputA = PIN_WhiteLED;
        const int outputB = PIN_RedLED;
};


       
