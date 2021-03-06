#include "kozy.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE MYFRIDGE
// Here we use the STL because what's inside the refrigerator in stored in a list.
///////////////////////////////////////////////////////////////////////////////////////////////////

// Constructor and destructor

MyFridge::MyFridge() {};
MyFridge::~MyFridge() {};

// Public functions 

void MyFridge::initialize(void) {
  Serial.println("\nInitializing the refrigerator with eggs and bacon...");
  delay(2000);
  this->add("eggs");
  delay(1000);
  this->add("bacon");
  delay(3000);
}

void MyFridge::use(void) {
  String inputA = "N";
  String inputB = "N";
  Serial.print("\nDo you want to use the refridgerator ? Y/N ");
  delay(10000);
  if(Serial.available()){
        inputA = Serial.readStringUntil('\n');
        Serial.println(inputA);
  }
  if (inputA == "Y") {
    this->openDoor();
    this->whatsInside();
    Serial.print("Do you want to add something in the refridgerator ? Y/N ");
    delay(10000);
    if(Serial.available()){
      inputB = Serial.readStringUntil('\n');
      Serial.println(inputB);
    }
    if (inputB == "Y") {
      this->add("tomatoes");
      this->add("cucumber");
      this->tidy();
      this->whatsInside();
    }
    delay(10000);
    this->closeDoor();
  }
}

// Private functions 

void MyFridge::whatsInside(void) {
  Serial.print("Inside your refrigerator you have... ");
  for (String ref : frigo) {
    Serial.print(ref);
    Serial.print(" ");
  }
  Serial.print("\n");
}

void MyFridge::tidy(void) {
  Serial.print("Tidying your refrigerator... \n");
  frigo.sort();
}

void MyFridge::empty(void) {
  Serial.print("Emptying your refrigerator... \n");
  list<String>::iterator itdebut = frigo.begin();
  list<String>::iterator itfin = frigo.begin();
  advance(itfin, frigo.size()); //dans la lib STL
  frigo.erase(itdebut, itfin);
}

void MyFridge::add(String item) {
  Serial.print("Adding ");
  Serial.print(item);
  Serial.print("\n");
  frigo.push_back(item);
  nbItems++;
}

void MyFridge::openDoor(void) {
  if (doorOpened == 0) {
    Serial.print("Opening the refrigerator's door... \n");
    doorOpened = 1;
  }
  else {
    Serial.print("The refrigerator's door is already opened... \n");
  }
}

void MyFridge::closeDoor(void) {
  if (doorOpened == 1) {
    Serial.print("Closing the refrigerator's door... \n");
    doorOpened = 0;
  }
  else {
    Serial.print("The refrigerator's door is already closed... \n");
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE LIGHT SENSOR
///////////////////////////////////////////////////////////////////////////////////////////////////

void Light::initialize(int pinNb) {
  pinMode(pinNb, INPUT);
}

void Light::getLightLevel(int pinNb) {
  value = digitalRead(pinNb);
  Serial.print("Light Level = ");
  Serial.println(value);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE LED
///////////////////////////////////////////////////////////////////////////////////////////////////

// Constructor and destructor

Led::Led() {};
Led::~Led() {};

// Operators
Led & Led::operator= (const Led & other) {
  return *this;
}

// Public functions
        
void Led::initialize(int pinNb){
  this->pinNb = pinNb;
  pinMode(pinNb, OUTPUT);       // Initializes the digital pin as an output.
}

void Led::off(){
  digitalWrite(pinNb, LOW); 
}

void Led::blinkLedParty(){
  digitalWrite(pinNb, LOW);         // Turns the LED on
  delay(200);                       // Waits for 0.2 second
  digitalWrite(pinNb, HIGH);        // Turns the LED off by making the voltage HIGH
  delay(200);                       // Waits for 0.2 second
  digitalWrite(pinNb, LOW);         // Turns the LED on
}

void Led::blinkLedFast(){
  digitalWrite(pinNb, LOW);         // Turns the LED on
  delay(400);                       // Waits for 0.4 second
  digitalWrite(pinNb, HIGH);        // Turns the LED off by making the voltage HIGH
  delay(400);                       // Waits for 0.4 second
}

void Led::blinkLedSlow(){
  digitalWrite(pinNb, LOW);         // Turns the LED on
  delay(1000);                      // Waits for a second
  digitalWrite(pinNb, HIGH);        // Turns the LED off by making the voltage HIGH
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
        
void Speaker::initialize(int pinNb){
  this->pinNb = pinNb;
  pinMode(pinNb, OUTPUT);       // Initializes the digital pin as an output.
}

void Speaker::off(){
  digitalWrite(pinNb,LOW);
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
  digitalWrite(pinNb, HIGH);
  delay(1000);
  digitalWrite(pinNb, LOW);
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
     digitalWrite(pinNb,HIGH);
     delayMicroseconds(BassTab[note_index]);
     digitalWrite(pinNb,LOW);
     delayMicroseconds(BassTab[note_index]);
  }
}


void Speaker::alarm(uint8_t note_index){
  int Alarm[]={1112,1711,1112,1711}; //alarm notes
  for(int i=0;i<100;i++){
     digitalWrite(pinNb,HIGH);
     delayMicroseconds(Alarm[note_index]);
     digitalWrite(pinNb,LOW);
     delayMicroseconds(Alarm[note_index]);
  }
}

void Speaker::playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(pinNb, HIGH);
        delayMicroseconds(tone);
        digitalWrite(pinNb, LOW);
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
  greenLed = redLed;  // On a pas de greenLed, mais on fait en sorte d'utiliser la surcharge
                      // d'op??rateur au cas o?? on met une greenLed sur le m??me port
  dropTheMic.initialize(PIN_Buzzer);
}

//fonction de d??clenchement de l'alarme
void MyAlarm::alarmOn(){
  Serial.println("!!! INTRUSION !!! INTRUSION !!! INTRUSION !!!");
  for (int i=0; i<3; i++) {
    redLed.blinkLedFast();  // Blinks red led
    redLed.blinkLedFast();
    dropTheMic.alarmOn();   // Makes alarm noise
  }
}

//fonction d'arr??t de l'alarme
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

//fonction d'initialisation du mood
void MyMood::initialize(){
  whiteLed.initialize(PIN_WhiteLED);
  dropTheMic.initialize(PIN_Buzzer);
}

//fonction de d??clenchement de la party
void MyMood::posey(){
  for (int j=0; j<4; j++) {
    whiteLed.blinkLedParty();  // Blinks white led
    whiteLed.blinkLedFast();
  }
  dropTheMic.singSong();    // Sings a cool song
}
