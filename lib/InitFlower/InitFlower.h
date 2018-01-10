#ifndef InitFlower_h
#define InitFlower_h

#include "Arduino.h"
#include "Motor.h"

namespace InitFlower{
  void SETUPF(Motor m);
  extern Motor* localMotor;
}
#endif
