#include "Arduino.h"
#include "Motor.h"
#include "InitFlower.h"

// InitFlower::InitFlower(int _initLed, int _initSensorReading){
//   this-> _initLed = _initLed;
//   this-> _initSensorReading = _initSensorReading;
//
// }
void InitFlower::setFlower(int step,int _initLed,int _initSensorReading){
  //localMotor = &_motor;
  digitalWrite(_initLed,HIGH);  //working on it
  if(digitalRead(_initLed) == HIGH){
    Serial.println("INIT LED HIGH");
  }
  //setting a recomended speed for pre adjusting flower
  Serial.println("SETFLOWER");
   if(localMotor->getDelayBetweenSteps() != 5){
     localMotor->setDelayBetweenSteps(5);
   }
   localMotor->toSetup_LED(_initSensorReading,TRIG_POINT, step);
  //  if(_initSensorReading < TRIG_POINT){
  //    Serial.println(_initSensorReading);
  //    if(_initSensorReading >= TRIG_POINT){
  //      _setupComplete = true;
  //      Serial.println("setup complete!");
  //    }
  //    localMotor->toSetup_LED(_initSensorReading, TRIG_POINT, step);
  // }
}
Motor* InitFlower::localMotor = NULL;
int InitFlower::_initSensorReading = 0;
boolean InitFlower::_setupComplete = false;
