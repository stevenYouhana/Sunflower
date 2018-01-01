#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor {
  public:
    Motor(int delayBetweenStep,int pin1,
      int pin2,int pin3, int pin4);
    ~Motor(){};
    void clockwise();
    void untiClockwise();
    void kill();
  private:
    int _delayBetweenStep;
    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
    int _stepCounter = 0;
    void _abstractRotation(int step);
};
#endif
