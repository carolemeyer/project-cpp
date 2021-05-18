#ifndef KOZY_H
#define KOZY_H

#include "includes.h"
#include <list>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE FRIDGE
///////////////////////////////////////////////////////////////////////////////////////////////////
class MyFridge {
public:
  MyFridge();
  ~MyFridge();
  void initialize(void);
  void use(void);
private:
  int doorOpened = 0;
  int nbItems = 0;
  list <String> frigo;
  // Private functions
  void whatsInside(void);
  void tidy(void);
  void empty(void);
  void add(String item);
  void openDoor(void);
  void closeDoor(void);
};


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE LIGHT SENSOR
///////////////////////////////////////////////////////////////////////////////////////////////////
class Light : protected Sensor, protected Digital {
    public :
      virtual void initialize(int pinNb);
      void getLightLevel(int pinNb);

    private :
      int value = 0;
};


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE LED
///////////////////////////////////////////////////////////////////////////////////////////////////
class Led : protected Actuator, protected Digital {
    public :
        // Constructors
        Led();
        //Led(int pin);
        ~Led();
        // Public functions
        virtual void initialize(int pinNb);         // Configures the LED on its dedicated pin - to put in the setup
        void off(void);                             // Sets the output to 0
        void blinkLedParty(void);                   // Blinks the LED for 0.2 second - to put in the loop
        void blinkLedFast(void);                    // Blinks the LED for 0.4 second - to put in the loop
        void blinkLedSlow(void);                    // Blinks the LED for one second - to put in the loop
        void alternativeBlink(int pin1, int pin2);  // Alternatively blinks one LED and the other - to put in the loop

        Led & operator= (const Led & other);
};


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SPEAKER
///////////////////////////////////////////////////////////////////////////////////////////////////
class Speaker : protected Actuator, protected Digital {
    public : 
        // Constructors
        Speaker();
        ~Speaker();
        // Public functions
        virtual void initialize(int pinNb); // Configures the Buzzer on its dedicated pin - to put in the setup
        void off(void);            // Sets the output to 0
        void musicOn(void);        // Outputs notes through the speaker
        void alarmOn(void);        // Outputs two notes repeatedly through the speaker
        void bipBuzzer(void);      // Alternatively bips and stops for one second - to put in the loop
        void singSong(void);       // Sings a particular song - to put in the loop
        void singMario(void);      // Sings a Mario song - to put in the loop
    private : 
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
class MyAlarm : protected Speaker, protected Led {
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
    Led greenLed;    
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE MOOD
// Gives the possibility to bring a good ambiance in the living room with good music and party lights. 
///////////////////////////////////////////////////////////////////////////////////////////////////
class MyMood : protected Speaker, protected Led {
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
