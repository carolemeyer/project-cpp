#include "includes.h"


class Temperature {
    public :
        void printTemperature(void);
    private:
        const int B = 4275;               // B value of the thermistor
        const int R0 = 100000;            // R0 = 100k
        const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
};
