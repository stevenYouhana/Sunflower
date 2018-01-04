#ifndef FlowerRotation_h
#define FlowerRotation_h

#include "Arduino.h"
#include "Reading.h"
#include "Motor.h"
/*This class uses <Reading> to use the sensor data
  for rotating the flower in the appropriate angle
*/
class FlowerRotation {
  public:
    FlowerRotation(int* average);
    ~FlowerRotation(){};
    void adjustFlower();
    void rotate();
    static void SETUP_MOTOR(int delayBetweenStep,int pin1,
      int pin2,int pin3, int pin4);
  private:
    Reading* _reading;
    static Motor* _motor;
    float rotationAngle(int top, int second);
    float radToDeg(float angle);
    int map4096_90(float angle);
};
#endif
