#include "kozy.h"

void Kozy::blinkOnBrdLED(void) {
    digitalWrite(LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    delay(10);                      // Wait for a second
    digitalWrite(LED, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(5000);                      // Wait for two seconds (to demonstrate the active low LED)
}
