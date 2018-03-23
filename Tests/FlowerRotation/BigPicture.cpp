#include "BigPicture.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;
using::pow;
using::sqrt;
using::asin;

BigPicture::BigPicture(){};
BigPicture::~BigPicture(){}


void BigPicture::update(){	
  rotationAngle(firstValue, secondValue, firstSensor, secondSensor);
  if(newPosition < currentPosition){
    if (currentPosition - newPosition <= 180) {
          //localMotor->toAngleUnticlockwise(angle_steps(static_cast<int>(
          //currentPosition - newPosition)));
    } else {
          //localMotor->toAngleClockwise(angle_steps(static_cast<int>(static_cast<int>(
          //currentPosition - newPosition))));
    }
  }
  else {
    if (newPosition - currentPosition <= 180) {
      //localMotor->toAngleUnticlockwise(angle_steps(static_cast<int>(newPosition - currentPosition)));
    } else {
      //localMotor->toAngleClockwise(angle_steps(static_cast<int>(newPosition - currentPosition)));
    }
  }
  currentPosition = newPosition;
  //delete _reading;	//for real readings
  //_reading = nullptr;
}

void BigPicture::rotationAngle(int top, int second, int topSensor, int secondSensor){
int MINOR_ADJUSTMENT = 0;

  if(((top<=100) & (top>=0)) & ((second<=100) & (second>=0))){
    const int LEG_A_BIG_TRIANGLE = 10; //Random, can totally be changed
    const int LEG_B_BIG_TRIANGLE = 10;
    const float HYPOTENUSE_BIG_TRIANGLE = sqrt(pow(LEG_A_BIG_TRIANGLE, 2) + pow(LEG_B_BIG_TRIANGLE, 2));
    float LEG_A_SMALL_TRIANGLE = HYPOTENUSE_BIG_TRIANGLE / 2;
    float DIFF_PERCENTAGE = top - second; //since the mapped sensor value is to 100 so we can use as %
    float LEG_A_SMALLER_TRIANGLE = (LEG_A_SMALL_TRIANGLE / 100) * DIFF_PERCENTAGE;
    float HYPOTENUSE_SMALLER_TRIANGLE = sqrt(pow(LEG_A_SMALL_TRIANGLE, 2) + pow(LEG_A_SMALLER_TRIANGLE, 2));

    MINOR_ADJUSTMENT = radToDeg(asin(LEG_A_SMALLER_TRIANGLE / HYPOTENUSE_SMALLER_TRIANGLE));
  }
  if ((topSensor == 0 && secondSensor == 1) || (topSensor == 3 && secondSensor == 0 )||
      (topSensor > 0 && topSensor < secondSensor)) {
    newPosition = getTopSensorAngle(topSensor) + 45 - MINOR_ADJUSTMENT;
  } else {
    newPosition = getTopSensorAngle(topSensor) - 45 + MINOR_ADJUSTMENT;
  }
}

float BigPicture::radToDeg(float rad){
    return ((rad * 180) / M_PI);
}

int BigPicture::getTopSensorAngle(int topSensor){
  int ANGLE_TOP_SENSOR = 0;
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
  return ANGLE_TOP_SENSOR;
}

float BigPicture::map90_1024(float angle){
  const int MAX_STEPS = 1024;	//changed from 2048 (full rotation to half)
  return (angle * MAX_STEPS/180);
}

void BigPicture::setFakeReadings(float firstValue, float secondValue, int firstSensor, int secondSensor){
	this-> firstValue = firstValue;
	this-> secondValue = secondValue;
	this-> firstSensor = firstSensor;
	this-> secondSensor = secondSensor;
}

float BigPicture::getNewPosition(){
	return newPosition;
}
float BigPicture::getCurrentPosition(){
	return currentPosition;
}

float BigPicture::currentPosition = 0;
