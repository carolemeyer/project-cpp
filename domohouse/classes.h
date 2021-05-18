#ifndef CLASSES_H
#define CLASSES_H


//###############################//
//########## Classes N ##########//
//###############################//

class Sensor {
    public :
      virtual void initialize(int pinNb) = 0; // Initialise pin

    private :
        int nbSensors;
};


class Actuator {
    public :
      virtual void initialize(int pinNb) = 0; // Initialise pin

    private :
        int nbActuators;
};



class Digital {
    public :

    protected :
      // Valeur du pin
      int pinNb;
  

};


class Analog {
    public :


    protected :
      // Valeur du pin
      int pinNb;

};


#endif
