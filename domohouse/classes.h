#ifndef CLASSES_H
#define CLASSES_H


//###############################//
//########## Classes N ##########//
//###############################//

class Sensor {
    public :
      virtual int initialize(int pinNb); // Initialise pin

    private :
        int nbSensors;
};


class Actuator {
    public :


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
