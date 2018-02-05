#include "Arduino.h"
#include "Motor.h"
#include "InitFlower.h"
using namespace InitFlower;

void InitFlower::SETUP(Motor* m){
  m->setDelayBetweenSteps(15);
  m->toSetup_LED();
}
