#include "Arduino.h"
#include "Motor.h"
#include "InitFlower.h"

InitFlower::InitFlower(int _initLed, int _initSensorReading){
  this-> _initLed = _initLed;
  this-> _initSensorReading = _initSensorReading;

}
void InitFlower::setFlower(){
  digitalWrite(_initLed,HIGH);  //working on it
  if(InitFlower::_motor->getDelayBetweenSteps() != 5){
    InitFlower::_motor->setDelayBetweenSteps(5);
  }
  do{
    InitFlower::_motor->clockwise();
  }
  while(_initSensorReading < TRIG_POINT);
}
Motor* InitFlower::_motor = FlowerRotation::getMotor();
