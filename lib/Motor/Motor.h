#ifndef Motor_h
#define Motor_h

#include "Arduino.h"


class Motor {
  public:
    Motor(int delayBetweenStep,int pin1,
  int pin2,int pin3, int pin4);
    void toAngle(int angle);
    void clockwise();
    void untiClockwise();
    void kill();
    int getDelayBetweenSteps();
    void setDelayBetweenSteps(int i);
  private:
    int _delayBetweenStep;
    int _pin1 = 0;
    int _pin2 = 0;
    int _pin3 = 0;
    int _pin4 = 0;
    int _stepCounter = 0;
    void _abstractRotation(int step);
};
#endif
