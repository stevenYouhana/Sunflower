#include "Arduino.h"
#include "Motor.h"
#include "InitFlower.h"

InitFlower::InitFlower(){
  localMotor = new Motor();
}

InitFlower::~InitFlower(){
  delete localMotor;
}
void InitFlower::SETUP(Motor m){
  *localMotor = m;
  localMotor->setDelayBetweenSteps(15);
  localMotor->toSetup_LED();

}
