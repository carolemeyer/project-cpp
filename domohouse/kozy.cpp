#include "kozy.h"

//BUZZER
void configBuzzer(int pin){
  pinMode(pin, OUTPUT);
}

void bipBuzzer(int pin){
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}

int length = 15;         // the number of notes 
char notes[] = "ccggaagffeeddc ";
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void singSong(void){
    for(int i = 0; i < length; i++) {
        if(notes[i] == ' ') {
            delay(beats[i] * tempo);
        } else {
            playNote(notes[i], beats[i] * tempo);
        }
        delay(tempo / 2);    /* delay between notes */
    }
}

/* play tone */
void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(PIN_Buzzer, HIGH);
        delayMicroseconds(tone);
        digitalWrite(PIN_Buzzer, LOW);
        delayMicroseconds(tone);
    }
}
 
void playNote(char note, int duration) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
 
    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++) {
        if (names[i] == note) {
            playTone(tones[i], duration);
        }
    }
}

//LEDS
void configLED(int pin){
  pinMode(pin, OUTPUT);       // Initializes the digital pin as an output.
}

void blinkBlueLed(void){
    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    delay(1000);                      // Wait for a second
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}

void blinkLed(int pin){
    digitalWrite(pin, LOW);           // Turns the LED on
    delay(1000);                      // Waits for a second
    digitalWrite(pin, HIGH);          // Turns the LED off by making the voltage HIGH
    delay(1000);                      // Waits for a second
}

void alternativeBlink(int pin1, int pin2){
    digitalWrite(pin1, LOW);          
    digitalWrite(pin2, HIGH);
    delay(1000);                      
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);          
    delay(1000); 

void Kozy::blinkOnBrdLED(void) {
    digitalWrite(LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    delay(10);                      // Wait for a second
    digitalWrite(LED, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(5000);                      // Wait for two seconds (to demonstrate the active low LED)
}
