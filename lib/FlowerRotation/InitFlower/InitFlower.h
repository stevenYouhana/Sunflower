#ifndef InitFlower_h
#define InitFlower_h

#include "Arduino.h"
#include "Motor.h"
#include "FlowerRotation.h"

class InitFlower : public FlowerRotation {
  public:
    InitFlower(int _initLed, int _initSensorReading);
    ~InitFlower(){};
    static void setFlower();
  private:
    int _initLed = 0;
    static int _initSensorReading;
    static const int TRIG_POINT = 60;
    static Motor* _motor;
    const int stepDelay = 0;
};
#endif
