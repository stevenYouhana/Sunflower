#ifndef InitFlower_h
#define InitFlower_h

#include "Arduino.h"
#include "Motor.h"

class InitFlower{
  public:
    InitFlower();
    ~InitFlower();
    void SETUP(Motor m);
  private:
    Motor *localMotor;
};
#endif
