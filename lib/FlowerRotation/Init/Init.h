#ifndef Init_h
#define Init_h

#include "Arduino.h"
#include "Motor.h"

class InitFlower{
  public:
    InitFlower(int _initLed, int _initSensor);
    ~InitFlower(){};
  private:
    int _initLed;
    int _initSensor;
};
#endif
