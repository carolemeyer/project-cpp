/*
 * Author: Meyer Carole
 * Date: April 2021
 * Last rev: May 2021
 */

#ifndef KOZY_H
#define KOZY_H

#include "includes.h"

// #define PIN_WhiteLED D3                 // Connects White LED to digital pin D5
// #define PIN_RedLED D5                   // Connects Green LED to digital pin D3
// #define PIN_OnBoardBlueLED LED_BUILTIN  // BuiltIn Blue LED is already on board
// #define PIN_Speaker D6                  // Connects Speaker to digital pin D6
 

// //BUZZER
// class Buzzer : public Actuator, public Digital {
//     public :
//         // Public functions
//         int initialize(int pinNb);      // Configures the Buzzer on its dedicated pin - to put in the setup
//         void bipBuzzer(void);      // Alternatively bips and stops the buzzer for one second - to put in the loop
//         void singSong(void);          // Sings a particular song - to put in the loop
//     private :
//         // Values 
//         int pin;
//         // Functions 
//         void playTone(int tone, int duration);  // Private function called by playNote
//         void playNote(char note, int duration); // Private function called by singSong
// };


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE LED
///////////////////////////////////////////////////////////////////////////////////////////////////
class Led : public Actuator, public Digital {
    public :
        // Constructors
        Led();
        //Led(int pin);
        ~Led();
        // Public functions
        int initialize(int pinNb);                  // Configures the LED on its dedicated pin - to put in the setup
        void off(void);                             // Sets the output to 0
        void blinkLedParty(void);                   // Blinks the LED for 0.2 second - to put in the loop
        void blinkLedFast(void);                    // Blinks the LED for 0.4 second - to put in the loop
        void blinkLedSlow(void);                    // Blinks the LED for one second - to put in the loop
        void alternativeBlink(int pin1, int pin2);  // Alternatively blinks one LED and the other - to put in the loop
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
///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SPEAKER
///////////////////////////////////////////////////////////////////////////////////////////////////
class Speaker : public Actuator, public Digital {
    public : 
        // Constructors
        Speaker();
        ~Speaker();
        // Public functions
        int initialize(int pinNb);      // Configures the Buzzer on its dedicated pin - to put in the setup
        void off(void);            // Sets the output to 0
        void musicOn(void);        // Outputs notes through the speaker
        void alarmOn(void);        // Outputs two notes repeatedly through the speaker
        void bipBuzzer(void);      // Alternatively bips and stops for one second - to put in the loop
        void singSong(void);       // Sings a particular song - to put in the loop
        void singMario(void);      // Sings a particular song - to put in the loop
    private : 
        int pin;
        // Private functions 
        void sound(uint8_t note_index); // One note at a time
        void alarm(uint8_t note_index); // Alarm one note at a time
        void playTone(int tone, int duration);  // Private function called by playNote
        void playNote(char note, int duration); // Private function called by singSong
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE ALARME
// Gives the possibility to make a light-and-sound alarm go off or shut it down. 
///////////////////////////////////////////////////////////////////////////////////////////////////
class MyAlarm : private Speaker, private Led {
  public:
    //---------------------------- constructor ----------------------------//
    MyAlarm();

    //---------------------------- destructor -----------------------------//
    ~MyAlarm();

    //----------------------------- functions -----------------------------//
    void initialize();
    void alarmOn();
    void alarmOff();

  protected:
    Speaker dropTheMic;
    Led redLed;    
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE MOOD
// Gives the possibility to bring a good ambiance in the living room with good music and party lights. 
///////////////////////////////////////////////////////////////////////////////////////////////////
class MyMood : private Speaker, private Led {
  public:
    //---------------------------- constructor ----------------------------//
    MyMood();

    //---------------------------- destructor -----------------------------//
    ~MyMood();

    //----------------------------- functions -----------------------------//
    void initialize();
    void posey();

  protected:
    Speaker dropTheMic;
    Led whiteLed;    
};



#endif
