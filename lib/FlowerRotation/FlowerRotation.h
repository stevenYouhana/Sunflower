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
    FlowerRotation(Reading reading, Motor _motor);
    ~FlowerRotation(){};
    void rotate(int top, int second);
    float convert(float angle);
  private:
    Reading _reading;
    Motor _motor;
};
#endif
