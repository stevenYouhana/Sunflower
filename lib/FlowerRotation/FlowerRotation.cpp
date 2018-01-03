#include "FlowerRotation.h"
#include "Reading.h"
#include "Motor.h"
#include "Arduino.h"

//This class will need to use both Reading and Motor classes for flower rotation
//This class will be use in .ino (main)
FlowerRotation::FlowerRotation(int* averages){
  _reading = new Reading(averages);
}
void FlowerRotation::SETUP_MOTOR(int delayBetweenStep,int pin1,
  int pin2,int pin3, int pin4){
  _motor = new Motor(delayBetweenStep,pin1,pin2,pin3,pin4);
}
void FlowerRotation::rotate(){
  FlowerRotation::_motor->clockwise();
  Serial.println("ROTATE");
  for(int i=0; i<6; i++){
    Serial.println(_reading->getTopThree()[i]);
  }
  //delay(500);
  //_motor.untiClockwise();
  //delay(500);
}
Motor* FlowerRotation::_motor = NULL;
