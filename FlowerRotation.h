#ifndef FlowerRotation_h
#define FlowerRotation_h

#include "Arduino.h"
/*This class uses <Reading> to use the sensor data
  for rotating the flower in the appropriate angle
*/
class FlowerRotation {
  public:
    FlowerRotation(Reading reading, Motor _motor)
    void rotate();
  private:
    Reading _reading;
};
#endif
