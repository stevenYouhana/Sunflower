#ifndef Motor_h
#define Motor_h

#include "Arduino.h"


class Motor {
  public:
    Motor(int delayBetweenStep,byte pin1,
  byte pin2, byte pin3, byte pin4);
    Motor(byte pin1, byte pin2, byte pin3, byte pin4);
    Motor(){};
    void toAngleClockwise(int angle);
    void toAngleUnticlockwise(int steps);
    void clockwise();
    void untiClockwise();
    void toSetup_LED();
    void kill();
    int getDelayBetweenSteps();
    void setDelayBetweenSteps(int i);
    byte getPin1();
    byte getPin2();
    byte getPin3();
    byte getPin4();
  private:
    int _delayBetweenStep;
    byte _pin1 = 0;
    byte _pin2 = 0;
    byte _pin3 = 0;
    byte _pin4 = 0;
    int _stepCounter = 0;
    void _abstractRotation(int step);
};
#endif
