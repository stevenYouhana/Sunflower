#include "Arduino.h"
#include "Motor.h"
#include "InitFlower.h"
using namespace InitFlower;

void InitFlower::SETUP(Motor m){
  Motor* localMotor;
  localMotor = &m;
  localMotor->toSetup_LED();
}
