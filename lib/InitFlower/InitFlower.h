#ifndef InitFlower_h
#define InitFlower_h

#include "Arduino.h"
#include "Motor.h"
#include "FlowerRotation.h"

class InitFlower{
  public:
    // InitFlower(int _initLed, int _initSensorReading);
    // ~InitFlower(){};
    static void setFlower(Motor _motor,int _initLed, int _initSensorReading);
  private:
    //int _initLed = 0;
    static int _initSensorReading;
    static const int TRIG_POINT = 60;
    const int stepDelay = 0;
    static Motor* localMotor;
    static boolean _setupComplete;
};
#endif
