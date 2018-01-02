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
    FlowerRotation(Reading reading);
    ~FlowerRotation(){};
    static void rotate();
    static void SETUP_MOTOR(int delayBetweenStep,int pin1,
      int pin2,int pin3, int pin4);
  private:
    static Reading* _reading;
    static Motor* _motor;
};
#endif
