#include "FlowerRotation.h"
#include "InitFlower.h"
#include "Reading.h"
#include "Motor.h"
#include "Arduino.h"
#include <cmath>

using::pow;
using::sqrt;
using::asin;

using namespace InitFlower;
//This class will need to use both Reading and Motor classes for flower rotation
//This class will be use in .ino (main)

FlowerRotation::FlowerRotation(int* averages){
  _reading = new Reading(averages);
}

void FlowerRotation::SETUP_MOTOR(int delayBetweenStep,int pin1,
  int pin2,int pin3, int pin4){
  _motor = new Motor(delayBetweenStep,pin1,pin2,pin3,pin4);
}
void FlowerRotation::setFlower(){
  SETUP(_motor);
}
//------------------Logic------------------

void FlowerRotation::update(){
  rotationAngle(_reading->getFirstValue(),_reading->getSecondValue(),
    _reading->getFirstSensor(),_reading->getSecondSensor());
    Serial.print("FirstSensor: ");Serial.println(_reading->getFirstSensor());
    Serial.print("SecondSensor: ");Serial.println(_reading->getSecondSensor());
  if(newPosition < currentPosition){
    //rotate currentPosition - newPosition
    if (currentPosition - newPosition < 180) {
      Serial.print("ANTI: "); Serial.println(newPosition);
      _motor->toAngleUnticlockwise(angle_steps(static_cast<int>(currentPosition - newPosition)));
    } else {
      _motor->toAngleClockwise(angle_steps(static_cast<int>(currentPosition - newPosition)));
      Serial.print("CLOCK: "); Serial.println(newPosition);
    }
}
  else {
    //rotate newPosition - currentPosition
    if (newPosition - currentPosition < 180) {
      _motor->toAngleUnticlockwise(angle_steps(static_cast<int>(newPosition - currentPosition)));
      Serial.print("ANTI: "); Serial.println(newPosition);
    } else {
      _motor->toAngleClockwise(angle_steps(static_cast<int>(newPosition - currentPosition)));
      Serial.print("CLOCK: "); Serial.println(newPosition);
    }
  }
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
  Serial.print("topSensor"); Serial.println(topSensor);
  switch (topSensor) {
    case 1:
      ANGLE_TOP_SENSOR = 90;
      break;
    case 2:
      ANGLE_TOP_SENSOR = 180;
      break;
    case 3:
      ANGLE_TOP_SENSOR = 270;
      break;
    default:
      ANGLE_TOP_SENSOR = 0;
  }
  Serial.print("ANGLE_TOP_SENSOR: "); Serial.println(ANGLE_TOP_SENSOR);
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
  Serial.print("getTopSensorAngle(topSensor): "); Serial.println(getTopSensorAngle(topSensor));
  Serial.print("MINOR_ADJUSTMENT: "); Serial.println(MINOR_ADJUSTMENT);
  if (topSensor == 0 && secondSensor == 1 || (topSensor > 0 && topSensor < secondSensor)) {
    newPosition = getTopSensorAngle(topSensor) + 45 - MINOR_ADJUSTMENT;
  } else {
    newPosition = getTopSensorAngle(topSensor) - 45 + MINOR_ADJUSTMENT;
  }
}

float FlowerRotation::radToDeg(float rad) {
  return ((rad * 180) / M_PI);
}
//TESTING METHOD
void FlowerRotation::rotate(){
  //reassin motor
  FlowerRotation::_motor->clockwise();
}
Motor FlowerRotation::getMotor(){
  //used at .ino to for flowe SETUP()
  Motor m = Motor(_motor->getPin1(),_motor->getPin2(),_motor->getPin3(),_motor->getPin4());
  return m;
}
Motor* FlowerRotation::_motor = nullptr;
float FlowerRotation::currentPosition = 0;
