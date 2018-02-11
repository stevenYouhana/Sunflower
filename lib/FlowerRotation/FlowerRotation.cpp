#include "FlowerRotation.h"
#include "InitFlower.h"
#include "Reading.h"
#include "Motor.h"
#include "Arduino.h"
#include <cmath>

using::pow;
using::sqrt;
using::asin;

//This class will need to use both Reading and Motor classes for flower rotation
//This class will be use in .ino (main)

FlowerRotation::FlowerRotation(int* averages){
  _reading = new Reading(averages);
}
FlowerRotation::~FlowerRotation(){

   delete localMotor;
   //_reading = nullptr;
   localMotor = nullptr;
}
void FlowerRotation::SETUP_MOTOR(int del,int p1,
  int p2,int p3, int p4){
  _motor = Motor(del,p1,p2,p3,p4);
  pin1 = p1;
  pin2 = p2;
  pin3 = p3;
  pin4 = p4;
  delayBetweenStep = del;
}
void FlowerRotation::setFlower(){
  InitFlower init;
  init.SETUP(_motor);  //InitFlower
}
//------------------Logic------------------

void FlowerRotation::update(){
  localMotor = new Motor(delayBetweenStep,pin1,pin2,pin3,pin4);
  for(int i=0; i<6; i++){
    Serial.print("\nFR/getTops: ");
    Serial.println(_reading->getTops(i));
  }
  rotationAngle(_reading->getFirstValue(),_reading->getSecondValue(),
    _reading->getFirstSensor(),_reading->getSecondSensor());
    //Serial.print("\nFirstSensor: ");Serial.println(_reading->getFirstSensor());
    //Serial.print("SecondSensor: ");Serial.println(_reading->getSecondSensor());
  if(newPosition < currentPosition){
    //rotate currentPosition - newPosition
    if (currentPosition - newPosition <= 180) {
      Serial.print("\nANTI: "); Serial.println(static_cast<int>(currentPosition - newPosition));
      localMotor->toAngleUnticlockwise(angle_steps(static_cast<int>(
          currentPosition - newPosition)));
    } else {
      Serial.print("\nCLOCK: "); Serial.println(static_cast<int>(currentPosition - newPosition));
      localMotor->toAngleClockwise(angle_steps(static_cast<int>(static_cast<int>(
          currentPosition - newPosition))));
    }
  }
  else {
    //rotate newPosition - currentPosition
    if (newPosition - currentPosition <= 180) {
      Serial.print("\nANTI: "); Serial.println(static_cast<int>(newPosition - currentPosition));
      localMotor->toAngleUnticlockwise(angle_steps(static_cast<int>(newPosition - currentPosition)));
    } else {
      Serial.print("\nCLOCK: "); Serial.println(static_cast<int>(newPosition - currentPosition));
      localMotor->toAngleClockwise(angle_steps(static_cast<int>(newPosition - currentPosition)));
    }
  }
  Serial.println("----------------------------------------------------\n\n");
  currentPosition = newPosition;
  delete _reading;
  _reading = nullptr;
}

float FlowerRotation::angle_steps(float angle){
  const int MAX_STEPS = 2048;
  return (angle * MAX_STEPS/180);
}

int FlowerRotation::getTopSensorAngle(int topSensor) {
  int ANGLE_TOP_SENSOR = 0;
  switch (topSensor) {
    case 1: Serial.println(" switch TOP_SENSOR: 1");
      ANGLE_TOP_SENSOR = 90;
      break;
    case 2: Serial.println("switch TOP_SENSOR: 2");
      ANGLE_TOP_SENSOR = 180;
      break;
    case 3: Serial.println("switch TOP_SENSOR: 3");
      ANGLE_TOP_SENSOR = 270;
      break;
    default: Serial.println("switch TOP_SENSOR: 0");
      ANGLE_TOP_SENSOR = 0;
  }
  //Serial.print("ANGLE_TOP_SENSOR: "); Serial.println(ANGLE_TOP_SENSOR);
  return ANGLE_TOP_SENSOR;
}

void FlowerRotation::rotationAngle(int top, int second, int topSensor, int secondSensor){
  int MINOR_ADJUSTMENT = 0;

  if(((top<=100) & (top>=0)) & ((second<=100) & (second>=0))){
    const int LEG_A_BIG_TRIANGLE = 10; //Random, can totally be changed
    const int LEG_B_BIG_TRIANGLE = 10;
    const float HYPOTENUSE_BIG_TRIANGLE = sqrt(pow(LEG_A_BIG_TRIANGLE, 2) + pow(LEG_B_BIG_TRIANGLE, 2));
    float LEG_A_SMALL_TRIANGLE = HYPOTENUSE_BIG_TRIANGLE / 2;
    float DIFF_PERCENTAGE = top - second; //since the mapped sensor value is to 100 so we can use as %
    float LEG_A_SMALLER_TRIANGLE = (LEG_A_SMALL_TRIANGLE / 100) * DIFF_PERCENTAGE;
    float HYPOTENUSE_SMALLER_TRIANGLE = sqrt(pow(LEG_A_SMALL_TRIANGLE, 2) + pow(LEG_A_SMALLER_TRIANGLE, 2));
    // Angle refers to the angle of rotation from the midpoint of Top Sensor and Second Sensor
    // This angle is in radians
    MINOR_ADJUSTMENT = radToDeg(asin(LEG_A_SMALLER_TRIANGLE / HYPOTENUSE_SMALLER_TRIANGLE));
  }
  Serial.print("\ntopSensor: "); Serial.println(getTopSensorAngle(topSensor));
  Serial.print("\nMINOR_ADJUSTMENT: "); Serial.println(MINOR_ADJUSTMENT);
  if ((topSensor == 0 && secondSensor == 1) || (topSensor == 3 && secondSensor == 0 )||
      (topSensor > 0 && topSensor < secondSensor)) {
    newPosition = getTopSensorAngle(topSensor) + 45 - MINOR_ADJUSTMENT;
  } else {
    newPosition = getTopSensorAngle(topSensor) - 45 + MINOR_ADJUSTMENT;
  }
  // Serial.print("NEW POSITION: "); Serial.println(newPosition);
  // Serial.print("\nCURRENT POSITION: "); Serial.println(currentPosition);
}

float FlowerRotation::radToDeg(float rad) {
  return ((rad * 180) / M_PI);
}
//TESTING METHOD
void FlowerRotation::rotate(){
  //reassign motor
  FlowerRotation::localMotor->clockwise();
}

float FlowerRotation::currentPosition = 0;
