#include "FlowerRotation.h"
#include "TestReading.h"

//test leds
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

//MOTOR VARS
const byte A_1 = 8;
const byte A_2= 9;
const byte B_1 = 10;
const byte B_2 = 11;
const int STEP_DELAY = 1;
const byte initSensor = A5;

bool flowerSet;

const int READING_INTERVAL = 10000;
const int COMPARE_INTERVAL = 20000;
int sensors[4][10];
float averages[4];

FlowerRotation fr;
// Testing
TestReading tr;

void setup(){
  Serial.begin(9600);
  Serial.println("start...");
  for(int i=2; i<7; i++){
    pinMode(i,OUTPUT);
  }
  fr.SETUP_MOTOR(STEP_DELAY,A_1,A_2,B_1,B_2);
  flowerSet = false;
  delay(5);
}

void loop(){
  //check flowerSet if false initFlower else FlowerRotation

  while(!flowerSet){
    if(mappedReading((analogRead(initSensor))) < 15){
      Serial.println("setting flower...");
      Serial.println(mappedReading(analogRead(initSensor)));
      fr.setFlower();
    }
    else{
      flowerSet = true;
      break;
    }
  }
  Serial.println("Normal operation...");
  //Serial.println(mappedReading(analogRead(initSensor)));
  //Normal opperation
  popSensor();
  //ADD AVS TO AVERAGES
  for(int i=0; i<4; i++){
    averages[i] = getAverage(sensors[i]);
  }
  fr = FlowerRotation(averages);
  fr.update();
  delay(3000);
}
inline byte getAnalogPins(int i){
  switch(i){
    case 1: return A1; break;
    case 2: return A2; break;
    case 3: return A3; break;
    default: return A0; break;
  }
}

void popSensor(){
  for(int s=0; s<4; s++){
    //INSERT DELAY FOR READINGS
    for(int r=0; r<10; r++){
      sensors[s][r] = mappedReading(analogRead(
        getAnalogPins(s)));
    }
  }
}
float getAverage(int sensor[10]){
  int total = 0;
  for(int i=0; i<10; i++){
    total += sensor[i];
  }
  return total/10;
}
//MAPPING TO 100
int mappedReading(int reading){
  return map(reading,0,1023,0,100);
}


//----------------Tests--------------

void testMotor(){

}
