#include "Arduino.h"
#include "Motor_HalfStep.h"

Motor_HalfStep::Motor_HalfStep(int delayBetweenStep,int pin1,
  int pin2,int pin3, int pin4){
  delayBetweenStep = _delayBetweenStep;
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _pin4 = pin4;
}
void Motor_HalfStep::clockwise(){
  //1
  digitalWrite(_pin1,HIGH);
  digitalWrite(_pin2,LOW);
  digitalWrite(_pin3,LOW);
  digitalWrite(_pin4,HIGH);
  delay(_delayBetweenStep);
  //2
  digitalWrite(_pin1,HIGH);
  digitalWrite(_pin2,LOW);
  digitalWrite(_pin3,LOW);
  digitalWrite(_pin4,LOW);
  delay(_delayBetweenStep);
  //3
  digitalWrite(_pin1,HIGH);
  digitalWrite(_pin2,HIGH);
  digitalWrite(_pin3,LOW);
  digitalWrite(_pin4,LOW);
  delay(_delayBetweenStep);
  //4
  digitalWrite(_pin1,LOW);
  digitalWrite(_pin2,HIGH);
  digitalWrite(_pin3,LOW);
  digitalWrite(_pin4,LOW);
  delay(_delayBetweenStep);
  //5
  digitalWrite(_pin1,LOW);
  digitalWrite(_pin2,HIGH);
  digitalWrite(_pin3,HIGH);
  digitalWrite(_pin4,LOW);
  delay(_delayBetweenStep);
  //6
  digitalWrite(_pin1,LOW);
  digitalWrite(_pin2,LOW);
  digitalWrite(_pin3,HIGH);
  digitalWrite(_pin4,LOW);
  delay(_delayBetweenStep);
  //7
  digitalWrite(_pin1,LOW);
  digitalWrite(_pin2,LOW);
  digitalWrite(_pin3,HIGH);
  digitalWrite(_pin4,HIGH);
  delay(_delayBetweenStep);
  //8
  digitalWrite(_pin1,LOW);
  digitalWrite(_pin2,LOW);
  digitalWrite(_pin3,LOW);
  digitalWrite(_pin4,HIGH);
  delay(_delayBetweenStep);
}
void Motor_HalfStep::untiClockwise(){

}
void Motor_HalfStep::stop(){
  digitalWrite(_pin1,LOW);
  digitalWrite(_pin2,LOW);
  digitalWrite(_pin3,LOW);
  digitalWrite(_pin4,LOW);
}
