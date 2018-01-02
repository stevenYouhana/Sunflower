#include "FlowerRotation.h"
#include "Reading.h"
#include "Motor.h"
#include "Arduino.h"
#include "StandardCplusplus.h"

//This class will need to use both Reading and Motor classes for flower rotation
//This class will be use in .ino (main)
FlowerRotation::FlowerRotation(Reading _reading, Motor _motor){
  this-> _reading = _reading;
  this-> _motor = _motor;
}
void FlowerRotation::rotate(int top, int second){
  _motor.clockwise();
  Serial.println("ROTATE");
  for(int i=0; i<6; i++){
    Serial.println(_reading.getTopThree()[i]);
  }
  //delay(500);
  //_motor.untiClockwise();
  //delay(500);
  int READING_TOP = top;
  int READING_SECOND = second;

  int LEG_A_BIG_TRIANGLE = 10; //Random, can totally be changed
  int LEG_B_BIG_TRIANGLE = 10;
  float HYPOTENUSE_BIG_TRIANGLE = sqrt(pow(LEG_A_BIG_TRIANGLE, 2) + pow(LEG_B_BIG_TRIANGLE, 2));

  float LEG_A_SMALL_TRIANGLE = HYPOTENUSE_BIG_TRIANGLE / 2;
  int READING_DIFF = READING_TOP - READING_SECOND;
  float DIFF_PERCENTAGE = (READING_DIFF / 1023) * 100;
  float LEG_A_SMALLER_TRIANGLE = (LEG_A_SMALL_TRIANGLE / 100) * DIFF_PERCENTAGE;
  float HYPOTENUSE_SMALLER_TRIANGLE = sqrt(pow(LEG_A_SMALL_TRIANGLE, 2) + pow(LEG_A_SMALLER_TRIANGLE, 2));
  // Angle refers to the angle of rotation from the midpoint of Top Sensor and Second Sensor
  // This angle is in radians
  float angle = asin(LEG_A_SMALLER_TRIANGLE * sin(90) / HYPOTENUSE_SMALLER_TRIANGLE);
  
}

float FlowerRotation::convert(float angle) {
  return ((angle * 180) / M_PI);
}
