#include "Arduino.h"
#include "Motor.h"
#include "InitFlower.h"

// InitFlower::InitFlower(int _initLed, int _initSensorReading){
//   this-> _initLed = _initLed;
//   this-> _initSensorReading = _initSensorReading;
//
// }S
void InitFlower::setFlower(Motor _motor,int _initLed, int _initSensorReading){
  localMotor = &_motor;
  digitalWrite(_initLed,HIGH);  //working on it
  if(digitalRead(_initLed) == HIGH){
    Serial.println("INIT LED HIGH");
  }
  //setting a recomended speed for pre adjusting flower
  Serial.println("SETFLOWER");
   if(localMotor->getDelayBetweenSteps() != 5){
     localMotor->setDelayBetweenSteps(5);
   }
   if(_initSensorReading < TRIG_POINT){
     Serial.println(_initSensorReading);
     if(_initSensorReading >= TRIG_POINT){
       _setupComplete = true;
       Serial.println("setup complete!");
     }
     localMotor->toSetup(_initSensorReading, TRIG_POINT);
  }
  if(!_setupComplete){
    Serial.println("setup incomplete, please wait...");
    digitalWrite(_initLed,LOW);
    delay(3000);
    setFlower(_motor, _initLed, _initSensorReading);
  }
}
Motor* InitFlower::localMotor = NULL;
int InitFlower::_initSensorReading = 0;
boolean InitFlower::_setupComplete = false;
