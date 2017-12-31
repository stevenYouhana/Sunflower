#include "Arduino.h"
#include "Motor_HalfStep.h"
/*
This Motor has a Gear ratio of 64, and Stride Angle 5.625° so this motor has 4096 Steps.
 steps = Number of steps in One Revolution * Gear ratio
 steps= (360°/5.625°)*64"Gear ratio" = 64 * 64 =4096
 */
Motor_HalfStep::Motor_HalfStep(int delayBetweenStep,int pin1,
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

void Motor_HalfStep::_abstractRotation(int step){
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
void Motor_HalfStep::clockwise(){ Serial.println("CLOCKWISE");
  //full round
  while(_stepCounter <= 4096){
    for(int i=0; i<8; i++){
      _abstractRotation(i);
      _stepCounter++;
      delay(_delayBetweenStep);
    }
  }
  Serial.println(_delayBetweenStep);
  kill();
}
void Motor_HalfStep::untiClockwise(){ Serial.println("UNTICLOCKWISE");
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
void Motor_HalfStep::kill(){
  digitalWrite(_pin1,LOW);
  digitalWrite(_pin2,LOW);
  digitalWrite(_pin3,LOW);
  digitalWrite(_pin4,LOW);
  this -> _stepCounter = 0;
}
