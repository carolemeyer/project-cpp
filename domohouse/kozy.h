#ifndef KOZY_H
#define KOZY_H

#include <Arduino.h>
#include "includes.h"

#define LED 2 // Built-in LED

#define PIN_WhiteLED D3            // Connects White LED to digital pin D3
#define PIN_GreenLED D5            // Connects Green LED to digital pin D5
#define PIN_Buzzer D6              // Connects White LED to digital pin D3

//BUZZER
void configBuzzer(int pin);   // Configures the Buzzer on its dedicated pin - to put in the setup
void bipBuzzer(int pin);      // Alternatively bips and stops the buzzer for one second - to put in the loop
void singSong(void);          // Sings a particular song - to put in the loop
void playTone(int tone, int duration);  // Private function
void playNote(char note, int duration); // Private function

//LEDS
void configLED(int pin);      // Configures the LED on its dedicated pin - to put in the setup
void blinkBlueLed(void);      // Blinks the built-in blue LED for one second - to put in the loop
void blinkLed(int pin);       // Blinks the LED for one second - to put in the loop
void alternativeBlink(int pin1, int pin2); // Alternatively blinks one LED and the other - to put in the loop



class Kozy : public Sensor, public Digital {
    public :
        void blinkOnBrdLED(void);
    private :
};

#endif
