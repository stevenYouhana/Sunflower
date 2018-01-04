#include "FlowerRotation.h"
#include "Reading.h"
#include "Motor.h"
#include "StandardCplusplus.h"
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
//------------------Logic------------------
//adjustFlower(int) USED IN MAIN
void FlowerRotation::adjustFlower(){
  //set _angle
  if(map4096_90(rotationAngle(_reading->getFirstValue(),
    _reading->getSecondValue())) <= 90){
    _motor->toAngle(_angle);
  }
}
int FlowerRotation::map4096_90(float angle){
  //mapRange(double a1,double a2,double b1,double b2,double s)
  const int MAX_STEPS = 4096;
  return (static_cast<int>(angle)) * MAX_STEPS/90;
}
float FlowerRotation::rotationAngle(int top, int second){
  const int LEG_A_BIG_TRIANGLE = 10; //Random, can totally be changed
  const int LEG_B_BIG_TRIANGLE = 10;
  const float HYPOTENUSE_BIG_TRIANGLE = sqrt(pow(LEG_A_BIG_TRIANGLE, 2) + pow(LEG_B_BIG_TRIANGLE, 2));
  float LEG_A_SMALL_TRIANGLE = HYPOTENUSE_BIG_TRIANGLE / 2;
  int READING_DIFF = top - second;
  float DIFF_PERCENTAGE = (READING_DIFF / 1023) * 100;
  float LEG_A_SMALLER_TRIANGLE = (LEG_A_SMALL_TRIANGLE / 100) * DIFF_PERCENTAGE;
  float HYPOTENUSE_SMALLER_TRIANGLE = sqrt(pow(LEG_A_SMALL_TRIANGLE, 2) + pow(LEG_A_SMALLER_TRIANGLE, 2));
  // Angle refers to the angle of rotation from the midpoint of Top Sensor and Second Sensor
  // This angle is in radians
  return asin(LEG_A_SMALLER_TRIANGLE * sin(90) / HYPOTENUSE_SMALLER_TRIANGLE);
}
//NOT USED HERE
float FlowerRotation::RadToDeg(float angle) {
  return ((angle * 180) / M_PI);
}
//TESTING METHOD
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
