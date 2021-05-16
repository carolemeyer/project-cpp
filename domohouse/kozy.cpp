#include "kozy.h"

int Light::initialize(int pinNb) {
  pinMode(pinNb, INPUT);
}


int Light::getLightLevel(int pinNb) {
  value = digitalRead(pinNb);
  Serial.print("Light Level = ");
  Serial.println(value);
}



//-----------BUZZER----------//
int Buzzer::initialize(int pinNb){
  pinMode(pinNb, OUTPUT);
}

void Buzzer::bipBuzzer(void){
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}

void Buzzer::singSong(void){
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

// Private functions

void Buzzer::playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(PIN_Buzzer, HIGH);
        delayMicroseconds(tone);
        digitalWrite(PIN_Buzzer, LOW);
        delayMicroseconds(tone);
    }
}
 
void Buzzer::playNote(char note, int duration) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
 
    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++) {
        if (names[i] == note) {
            playTone(tones[i], duration);
        }
    }
}


//-----------LED----------//
int Led::initialize(int pinNb){
  pinMode(pinNb, OUTPUT);       // Initializes the digital pin as an output.
}

void Led::blinkLed(int pinNb){
    digitalWrite(pinNb, LOW);           // Turns the LED on
    delay(1000);                      // Waits for a second
    digitalWrite(pinNb, HIGH);          // Turns the LED off by making the voltage HIGH
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

//-----------SPEAKER----------//
/*
// Constructeurs

Speaker::Speaker() : pin(PIN_Speaker) {};
Speaker::Speaker(int pin) : pin(pin) {};
Speaker::~Speaker() {};

// Public functions
        
int Speaker::initialize(){
  pinMode(pin, OUTPUT);       // Initializes the digital pin as an output.
  return 0;
}

void Speaker::soundOn(uint8_t note_index){
  int BassTab[]={1911,1702,1516,1431,1275,1136,1012}; //bass 1~7
  for(int i=0;i<100;i++){
     digitalWrite(PIN_Speaker,HIGH);
     delayMicroseconds(BassTab[note_index]);
     digitalWrite(PIN_Speaker,LOW);
     delayMicroseconds(BassTab[note_index]);
  }
}
*/
