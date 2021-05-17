#ifndef ZEDOOR_H
#define ZEDOOR

#include "includes.h"
#include "kozy.h"


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE TOUCHSENSOR
///////////////////////////////////////////////////////////////////////////////////////////////////

class MonTouchSensor : public Sensor, public Digital
{
  public:
    //----------------------------constructeurs----------------------------//
    MonTouchSensor();

    //---------------------------- destructeur ----------------------------//
    ~MonTouchSensor();

    //----------------------------- fonctions -----------------------------//
    virtual void initialize(int pinNb) override;
    boolean getTouch(); //methode propre a la classe N+1 touchSensor
    void affichageEtatTouch();
    int getTimer() ;

  protected:
    int touchPin;
    int timer;
    boolean touchOK;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE SERVOMOTEUR
///////////////////////////////////////////////////////////////////////////////////////////////////

class MonServo : public Actuator, public Digital
{
  public:
    //----------------------------constructeurs----------------------------//
    MonServo();

    //---------------------------- destructeur ----------------------------//
    ~MonServo();

    //----------------------------- fonctions -----------------------------//
    virtual void initialize(int pinNb) override;
    void movePos(int pos);
    int readPos();

  protected:
    Servo myservo;
};


///////////////////////////////////////////////////////////////////////////////////////////////////
//            CLASSE PORTE
///////////////////////////////////////////////////////////////////////////////////////////////////
class MaPorte : private MonServo
{
  public:
    //----------------------------constructeurs----------------------------//
    MaPorte();

    //---------------------------- destructeur ----------------------------//
    ~MaPorte();

    //----------------------------- fonctions -----------------------------//
    void initPorte(int pinServo);
    void movePorte(int pos);
    int getPosPorte();

  protected:
    MonServo cerveau;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//             CLASSE Door_PROJET
///////////////////////////////////////////////////////////////////////////////////////////////////
class DoorProject : private MaPorte, private MonTouchSensor, protected MyAlarm
{
  public:
    //----------------------------constructeurs----------------------------//
    DoorProject();

    //---------------------------- destructeur ----------------------------//
    ~DoorProject();

    //----------------------------- fonctions -----------------------------//
    void initDoorProject(int pinSensor, int pinServo, int posClose);
    void runDoorProject(int posOpen, int posClose, int timer1, int timer2);

    void afficheInfos();
    int getDoorTimer();

    int getDoorTimerOpen();
    void setDoorTimerOpen(int timer);
    void timerAdd();
    void timerSub();
    void setTimerNull();

    int getOldTouch();
    void setOldTouch(int etat);
    int getDoorEtat();
    void setDoorEtat(int doorState);

    int getDoorPos();
    void setDoorPos(int pos);

    boolean getIntrusion();
    void setIntrusion(boolean intru);

  protected:
    MaPorte porte;
    MonTouchSensor touchS;
    int timerDoor;
    int timerOpen;
    int oldTouch;
    int doorClosed;
    MyAlarm alarm;
    boolean intrusion;

};


#endif //ZEDOOR_H
