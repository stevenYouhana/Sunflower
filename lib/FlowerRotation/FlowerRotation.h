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
    FlowerRotation(){};
    ~FlowerRotation(){
      //delete _reading;
    };
    void adjustFlower();
    void rotate();
    void update();
    float angle_steps(float angle);
    int getTopSensorAngle(int topSensor);
    static Motor getMotor();
    static void SETUP_MOTOR(int delayBetweenStep,int pin1,
      int pin2,int pin3, int pin4);
    void setFlower();
  private:
    Reading* _reading = nullptr;
    static Motor* _motor;
    void rotationAngle(int top, int second, int topSensor, int secondSensor);
    float radToDeg(float angle);
    float map90_1024(float angle);
    static float currentPosition;
    float newPosition = 0;
};
#endif
