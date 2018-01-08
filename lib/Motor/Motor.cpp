#include "Arduino.h"
#include "Motor.h"
/*
This Motor has a Gear ratio of 64, and Stride Angle 5.625° so this motor has 4096 Steps.
 steps = Number of steps in One Revolution * Gear ratio
 steps= (360°/5.625°)*64"Gear ratio" = 64 * 64 =4096
 */
 //This is class will be used in .ino (main) only to for setup
Motor::Motor(int delayBetweenStep,int pin1,
  int pin2,int pin3, int pin4){
  _delayBetweenStep = delayBetweenStep;
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _pin4 = pin4;
  //set minimum delay value
  if(_delayBetweenStep <= 0){
    _delayBetweenStep = 1;
  }
}
Motor::Motor(int pin1,int pin2,int pin3, int pin4){
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _pin4 = pin4;
}
void Motor::_abstractRotation(int step){
  switch (step) {
    case 0:
      //1001
      digitalWrite(_pin1,HIGH);
      digitalWrite(_pin2,LOW);
      digitalWrite(_pin3,LOW);
      digitalWrite(_pin4,HIGH);
      break;
    case 1:
      //1000
      digitalWrite(_pin1,HIGH);
      digitalWrite(_pin2,LOW);
      digitalWrite(_pin3,LOW);
      digitalWrite(_pin4,LOW);
      break;
    case 2:
      //1100
      digitalWrite(_pin1,HIGH);
      digitalWrite(_pin2,HIGH);
      digitalWrite(_pin3,LOW);
      digitalWrite(_pin4,LOW);
      break;
    case 3:
      //0100
      digitalWrite(_pin1,LOW);
      digitalWrite(_pin2,HIGH);
      digitalWrite(_pin3,LOW);
      digitalWrite(_pin4,LOW);
      break;
    case 4:
      //0110
      digitalWrite(_pin1,LOW);
      digitalWrite(_pin2,HIGH);
      digitalWrite(_pin3,HIGH);
      digitalWrite(_pin4,LOW);
      break;
    case 5:
      //0010
      digitalWrite(_pin1,LOW);
      digitalWrite(_pin2,LOW);
      digitalWrite(_pin3,HIGH);
      digitalWrite(_pin4,LOW);
      break;
   case 6:
      //0011
      digitalWrite(_pin1,LOW);
      digitalWrite(_pin2,LOW);
      digitalWrite(_pin3,HIGH);
      digitalWrite(_pin4,HIGH);
      break;
    case 7:
      //0001
      digitalWrite(_pin1,LOW);
      digitalWrite(_pin2,LOW);
      digitalWrite(_pin3,LOW);
      digitalWrite(_pin4,HIGH);
      break;
  }
}
void Motor::toAngle(int steps){
  Serial.print("toAngle(): "); Serial.println(steps);
  while(_stepCounter <= steps){
    for(int i=0; i<8; i++){
      _abstractRotation(i);
      _stepCounter++;
      delay(_delayBetweenStep);
    }
  }
  kill();
}
void Motor::clockwise(){ Serial.println("CLOCKWISE");
  //full round
  while(_stepCounter <= 4096){
    for(int i=0; i<8; i++){
      _abstractRotation(i);
      _stepCounter++;
      delay(_delayBetweenStep);
    }
  }
  Serial.print("Delay: ");
  Serial.println(_delayBetweenStep);
  kill();
}
void Motor::untiClockwise(){ Serial.println("UNTICLOCKWISE");
  //full round
  while(_stepCounter <= 4096){
    for(int i=7; i>=0; i--){
      _abstractRotation(i);
      _stepCounter++;
      delay(_delayBetweenStep);
    }
  }
  Serial.println(_delayBetweenStep);
  kill();
}
void Motor::toSetup(int sensorReading,const int TRIG_POINT){
  while(_stepCounter<=4096 && sensorReading<=TRIG_POINT){
    for(int i=7; i>=0; i--){
      Serial.println(sensorReading);
      _abstractRotation(i);
      _stepCounter++;
      delay(_delayBetweenStep);
    }
  }
  kill();
}
void Motor::kill(){
  digitalWrite(_pin1,LOW);
  digitalWrite(_pin2,LOW);
  digitalWrite(_pin3,LOW);
  digitalWrite(_pin4,LOW);
  this-> _stepCounter = 0;
}
int Motor::getDelayBetweenSteps(){
  return _delayBetweenStep;
}
void Motor::setDelayBetweenSteps(int i){
  _delayBetweenStep = i;
}
int Motor::getPin1(){
  return _pin1;
}
int Motor::getPin2(){
  return _pin2;
}
int Motor::getPin3(){
  return _pin3;
}
int Motor::getPin4(){
  return _pin4;
}
