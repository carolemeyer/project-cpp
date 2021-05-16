#ifndef KOZY_H
#define KOZY_H

#include "includes.h"
 
//BUZZER
class Buzzer : public Actuator, public Digital {
    public :
        // Public functions
        int initialize(int pinNb);      // Configures the Buzzer on its dedicated pin - to put in the setup
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
        // Public functions
        int initialize(int pinNb);      // Configures the LED on its dedicated pin - to put in the setup
        void blinkLed(int pinNb);       // Blinks the LED for one second - to put in the loop
        void alternativeBlink(int pin1, int pin2); // Alternatively blinks one LED and the other - to put in the loop
    private :
        int pinNb;
        
};


// Light sensor
class Light : public Sensor, public Digital {
    public :
      int initialize(int pinNb);
      int getLightLevel(int pinNb);

    private :
      int value = 0;

    protected :
      int pinNb;
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
