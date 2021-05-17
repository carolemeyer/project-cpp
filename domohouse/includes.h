#ifndef INCLUDES_H
#define INCLUDES_H

// Arduino & ESP
#include <Arduino.h>
#include <Esp.h>

// I/O
#include <iostream>

// Classes N
#include "classes.h"

// Other functions
#include <math.h>

//Servo
#include <Servo.h>

// Wifi 
//#include <ESP8266WiFi.h>

//// PIN DEFINITIONS ////
#define PIN_TempSensor  A0              // Connect Temperature Sensor to pin A0
//#define PIN_LightSensor D3              // Connect Light Sensor to pin D3
#define PIN_RedLED      D3              // Connect Green LED to digital pin D3
#define PIN_WhiteLED    D5              // Connect White LED to digital pin D5
#define PIN_Buzzer      D6              // Connect Buzzer to digital pin D6
#define PIN_ServoPin    D7              // Connect Servo to digital pin D7
#define PIN_TouchPin    D8              // Connect Touch Sensor to digital pin D8
#define PIN_OnBoardBlueLED LED_BUILTIN  // BuiltIn Blue LED is already on board

//// VARIABLES ////
#define OpenDoorAngle   0
#define CloseDoorAngle  90
#define TimerOpenDoor1  150
#define TimerOpenDoor2  50


#endif
