#include "kozy.h"

// Classe light

void Light::initialize(int pinNb) {
  pinMode(pinNb, INPUT);
}


/*int Light::getLightLevel(int pinNb) {
  value = digitalRead(pinNb);
  Serial.print("Light Level = ");
  Serial.println(value);
}*/



// //-----------BUZZER----------//
// int Buzzer::initialize(int pinNb){
//   pinMode(pinNb, OUTPUT);


//-----------LED----------//
// int Led::initialize(int pinNb){
//   pinMode(pinNb, OUTPUT);       // Initializes the digital pin as an output.
// }

// void Led::blinkLed(int pinNb){
//     digitalWrite(pinNb, LOW);           // Turns the LED on
//     delay(1000);                      // Waits for a second
//     digitalWrite(pinNb, HIGH);          // Turns the LED off by making the voltage HIGH
//     delay(1000);                      // Waits for a second




///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE LED
///////////////////////////////////////////////////////////////////////////////////////////////////

// Constructor and destructor

Led::Led() {};
Led::~Led() {};

// Public functions
        
int Led::initialize(int pinNb){
  pin = pinNb;
  pinMode(pinNb, OUTPUT);       // Initializes the digital pin as an output.
  return 0;
}

void Led::off(){
  digitalWrite(pin, LOW); 
}

void Led::blinkLedParty(){
  digitalWrite(pin, LOW);           // Turns the LED on
  delay(200);                       // Waits for 0.2 second
  digitalWrite(pin, HIGH);          // Turns the LED off by making the voltage HIGH
  delay(200);                       // Waits for 0.2 second
  digitalWrite(pin, LOW);           // Turns the LED on
}

void Led::blinkLedFast(){
  digitalWrite(pin, LOW);           // Turns the LED on
  delay(400);                       // Waits for 0.4 second
  digitalWrite(pin, HIGH);          // Turns the LED off by making the voltage HIGH
  delay(400);                       // Waits for 0.4 second
}

void Led::blinkLedSlow(){
  digitalWrite(pin, LOW);           // Turns the LED on
  delay(1000);                      // Waits for a second
  digitalWrite(pin, HIGH);          // Turns the LED off by making the voltage HIGH
  delay(1000);                      // Waits for a second
}

void Led::alternativeBlink(int pin1, int pin2){
  digitalWrite(pin1, LOW);          
  digitalWrite(pin2, HIGH);
  delay(1000);                      
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);          
  delay(1000); 
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SPEAKER
///////////////////////////////////////////////////////////////////////////////////////////////////

// Constructor and destructor

Speaker::Speaker() {};
Speaker::~Speaker() {};

// Public functions
        
int Speaker::initialize(int pinNb){
  pin = pinNb;
  pinMode(pinNb, OUTPUT);       // Initializes the digital pin as an output.
  return 0;
}

void Speaker::off(){
  digitalWrite(PIN_Speaker,LOW);
}

void Speaker::musicOn(){
    /*sound bass 1~7*/
    for(int note_index=0;note_index<7;note_index++)
    {
        sound(note_index);
        delay(500);
    }
}

void Speaker::alarmOn(){
    /*sound bass 1~7*/
    for(int note_index=0;note_index<4;note_index++)
    {
        alarm(note_index);
        delay(500);
    }
}


void Speaker::bipBuzzer(void){
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}

void Speaker::singSong(void){
    int length = 15;              // the number of notes 
    char notes[] = "ccggaagffeeddc ";
    int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
    int tempo = 300;
    for(int i = 0; i < length; i++) {
        if(notes[i] == ' ') {
            delay(beats[i] * tempo);
        } else {
            playNote(notes[i], beats[i] * tempo);
        }
        delay(tempo / 2);    // delay between notes 
    }
}

void Speaker::singMario(void){
    int length = 25;              // the number of notes 
    char notes[] = "eeeceggcgeabbagegafgecdb ";
    int beats[] = { 1, 1, 1, 1, 1, 4, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2 };
    int tempo = 150;
    for(int i = 0; i < length; i++) {
        if(notes[i] == ' ') {
            delay(beats[i] * tempo);
        } else {
            playNote(notes[i], beats[i] * tempo);
        }
        delay(tempo / 2);    // delay between notes 
    }
}

// Private functions

void Speaker::sound(uint8_t note_index){
  int BassTab[]={1911,1702,1516,1431,1275,1136,1012}; //bass 1~7
  for(int i=0;i<100;i++){
     digitalWrite(PIN_Speaker,HIGH);
     delayMicroseconds(BassTab[note_index]);
     digitalWrite(PIN_Speaker,LOW);
     delayMicroseconds(BassTab[note_index]);
  }
}


void Speaker::alarm(uint8_t note_index){
  int Alarm[]={1112,1711,1112,1711}; //alarm notes
  for(int i=0;i<100;i++){
     digitalWrite(PIN_Speaker,HIGH);
     delayMicroseconds(Alarm[note_index]);
     digitalWrite(PIN_Speaker,LOW);
     delayMicroseconds(Alarm[note_index]);
  }
}

void Speaker::playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(PIN_Speaker, HIGH);
        delayMicroseconds(tone);
        digitalWrite(PIN_Speaker, LOW);
        delayMicroseconds(tone);
    }
}
 
void Speaker::playNote(char note, int duration) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
 
    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++) {
        if (names[i] == note) {
            playTone(tones[i], duration);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE ALARME
///////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------- constructor ---------------------------//

MyAlarm::MyAlarm(): Speaker(), Led() {}

//---------------------------- destructor ----------------------------//

MyAlarm::~MyAlarm() {}

//---------------------------- functions -----------------------------//

//fonction d'initialisation de l'alarme
void MyAlarm::initialize(){
  redLed.initialize(PIN_RedLED);
  dropTheMic.initialize(PIN_Speaker);
}

//fonction de déclenchement de l'alarme
void MyAlarm::alarmOn(){
  for (int i=0; i<3; i++) {
    redLed.blinkLedFast();  // Blinks red led
    redLed.blinkLedFast();
    dropTheMic.alarmOn();   // Makes alarm noise
  }
}

//fonction d'arrêt de l'alarme
void MyAlarm::alarmOff(){
  dropTheMic.off();
  redLed.off();  
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE MOOD
///////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------- constructor ---------------------------//

MyMood::MyMood(): Speaker(), Led() {}

//---------------------------- destructor ----------------------------//

MyMood::~MyMood() {}

//---------------------------- functions -----------------------------//

//fonction d'initialisation de l'alarme
void MyMood::initialize(){
  whiteLed.initialize(PIN_WhiteLED);
  dropTheMic.initialize(PIN_Speaker);
}

//fonction de déclenchement de l'alarme
void MyMood::posey(){
  for (int j=0; j<4; j++) {
    whiteLed.blinkLedParty();  // Blinks white led
    whiteLed.blinkLedFast();
  }
  dropTheMic.singMario();    // Sings a cool song
}
