#ifndef KOZY_H
#define KOZY_H

#include "includes.h"
#define LED 2 // Built-in LED

class Light : public Sensor, public Digital {
    public :
      virtual void initialize(int pinNb);
      int getLightLevel(int pinNb);

    private :
      int value = 0;

    protected :
      int pinNb;
};

#endif
