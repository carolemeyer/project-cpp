#ifndef KOZY_H
#define KOZY_H

#include "includes.h"
#define LED 2 // Built-in LED

class Kozy : public Sensor, public Digital {
    public :
        void blinkOnBrdLED(void);
    private :
};

#endif