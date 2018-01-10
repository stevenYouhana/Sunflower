#include "Arduino.h"
#include "Motor.h"
#include "InitFlower.h"
namespace InitFlower{
  Motor* localMotor;
  void SETUPF(Motor m){
    localMotor = &m;
    localMotor->toSetup_LED();
    Serial.println("actually working!");
  }
}
