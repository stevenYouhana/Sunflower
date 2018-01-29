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

void FlowerRotation::update(int currentPosition, int newPosition){
  if(newPosition < currentPosition){
    //rotate currentPosition - newPosition
    _motor->toAngle(angle_steps(static_cast<int>(currentPosition - newPosition)));
  }
  else{
    //rotate newPosition - currentPosition
    _motor->toAngle(angle_steps(static_cast<int>(newPosition - currentPosition)));
  }
}

float FlowerRotation::angle_steps(float angle){
  const int MAX_STEPS = 2048;
  return (angle * MAX_STEPS/180);
}

float FlowerRotation::rotationAngle(int top, int second){
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
    return radToDeg(asin(LEG_A_SMALLER_TRIANGLE / HYPOTENUSE_SMALLER_TRIANGLE));
  }
  else{
    return 0;
  }
}

float FlowerRotation::radToDeg(float rad) {
  return ((rad * 180) / M_PI);
}
//TESTING METHOD
void FlowerRotation::rotate(){
  FlowerRotation::_motor->clockwise();
}
Motor FlowerRotation::getMotor(){
  //used at .ino to for flowe SETUP()
  Motor m = Motor(_motor->getPin1(),_motor->getPin2(),_motor->getPin3(),_motor->getPin4());
  return m;
}
Motor* FlowerRotation::_motor = NULL;
