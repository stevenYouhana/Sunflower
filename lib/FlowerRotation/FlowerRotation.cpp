#include "FlowerRotation.h"
#include "Reading.h"
#include "Motor.h"
#include "StandardCplusplus.h"
#include "Arduino.h"

//This class will need to use both Reading and Motor classes for flower rotation
//This class will be use in .ino (main)
FlowerRotation::FlowerRotation(int* averages){
  _reading = new Reading(averages);
  //_motor->toAngle(50);  //TEST
}

void FlowerRotation::SETUP_MOTOR(int delayBetweenStep,int pin1,
  int pin2,int pin3, int pin4){
  _motor = new Motor(delayBetweenStep,pin1,pin2,pin3,pin4);
}
//------------------Logic------------------
//adjustFlower(int) USED IN MAIN
void FlowerRotation::adjustFlower(){
  //confirm angle is no larger than 90 then pass that value to the motor function
  if(rotationAngle(_reading->getFirstValue(),
    _reading->getSecondValue()) <= 90){
    _motor->toAngle(static_cast<int>(map90_1024(rotationAngle(
        _reading->getFirstValue(),_reading->getSecondValue()))));
  }
}
float FlowerRotation::map90_1024(float angle){
  //mapRange(double a1,double a2,double b1,double b2,double s)
  const int MAX_STEPS = 1024;
  return (angle * MAX_STEPS/90);
}
float FlowerRotation::rotationAngle(int top, int second){
  if((top<=100 & top>=0) & (second<=100 & second>=0)){
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
  Serial.println("ROTATE");
  for(int i=0; i<6; i++){
    Serial.println(_reading->getTopThree()[i]);
  }
}
Motor* FlowerRotation::getMotor(){
  return _motor;
}
Motor* FlowerRotation::_motor = NULL;
