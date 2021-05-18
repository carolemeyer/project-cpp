#ifndef TEMPE_H
#define TEMPE_H

#include "includes.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE TEMPERATURE
///////////////////////////////////////////////////////////////////////////////////////////////////
class Temperature : public Sensor, public Analog {
    public :
        // Constructors
        Temperature();
        // Destructor
        ~Temperature();

        // Other functions
        virtual void initialize(int pinNb) override;
        float getHeatLevel(int pinNb);

    private :
        int value = 0;
        const int B = 4275;               // B value of the thermistor
        const int R0 = 100000;            // R0 = 100k
};


#endif
