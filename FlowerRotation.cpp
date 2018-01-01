#include "FlowerRotation.h"
#include "Reading.h"
#include "Motor.h"
#include "Arduino.h"

//This class will need to use both Reading and Motor classes for flower rotation
//This class will be use in .ino (main)
FlowerRotation::FlowerRotation(Reading _reading, Motor _motor){
  this-> _reading = _reading;
  this-> _motor = _motor;
}
FlowerRotation::rotate(){

}
