#ifndef KOZY_H
#define KOZY_H

#include "includes.h"

#define PIN_WhiteLED D5                 // Connects White LED to digital pin D5
#define PIN_RedLED D3                   // Connects Green LED to digital pin D3
#define PIN_OnBoardBlueLED LED_BUILTIN  // BuiltIn Blue LED is already on board
#define PIN_Buzzer D6                   // Connects Buzzer to digital pin D6
//#define PIN_Speaker D3
 
//BUZZER
class Buzzer : public Actuator, public Digital {
    public :
        // Constructeurs
        Buzzer();
        Buzzer(int pin);
        ~Buzzer();
        // Public functions
        int initialize(void);      // Configures the Buzzer on its dedicated pin - to put in the setup
        void bipBuzzer(void);      // Alternatively bips and stops the buzzer for one second - to put in the loop
        void singSong(void);          // Sings a particular song - to put in the loop
    private :
        // Values 
        int pin;
        // Functions 
        void playTone(int tone, int duration);  // Private function called by playNote
        void playNote(char note, int duration); // Private function called by singSong
};



//LED
class Led : public Actuator, public Digital {
    public :
        // Constructeurs
        Led();
        Led(int pin);
        ~Led();
        // Public functions
        int initialize(void);      // Configures the LED on its dedicated pin - to put in the setup
        void blinkLed(void);       // Blinks the LED for one second - to put in the loop
        void alternativeBlink(int pin1, int pin2); // Alternatively blinks one LED and the other - to put in the loop
    private :
        int pin;
        
};


//SPEAKER
/*
class Speaker : public Actuator, public Digital {
    public : 
        // Constructeurs
        Speaker();
        Speaker(int pin);
        ~Speaker();
        // Public functions
        int initialize(void); // Configures the Buzzer on its dedicated pin - to put in the setup
        void soundOn(uint8_t note_index); //Outputs notes through the speaker
    private : 
        int pin;
};
*/



#endif
