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

    private :


    protected :
      // Valeur du pin
      int pinNb;
  

};


class Analog {
    public :


    private :


};


#endif
