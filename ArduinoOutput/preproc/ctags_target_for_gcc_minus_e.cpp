# 1 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
/*

  ESP8266 DomoHouse by Romain Choulot, Carole Meyer and Lea Pitault

*/
# 4 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino"
# 5 "c:\\Users\\romai\\Documents\\INSA_4A\\S2\\CPP\\BE\\project-cpp\\domohouse\\domohouse.ino" 2

void setup() {
  pinMode(2, 0x01); // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  printTemperature();
  blinkBlueLed();
}
