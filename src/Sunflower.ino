#include "FlowerRotation.h"
#include "InitFlower.h"
#include "Motor.h"

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

//MOTOR VARS
const int A_1 = 8;
const int A_2= 9;
const int B_1 = 10;
const int B_2 = 11;
const int STEP_DELAY = 1;
const int initSensor = 'A5';
int step = 0;

const int READING_INTERVAL = 10000;
const int COMPARE_INTERVAL = 20000;
int sensors[4][10];
int averages[4];

void setup(){
  Serial.begin(9600);
  Serial.println("start...");
  for(int i=2; i<7; i++){
    pinMode(i,OUTPUT);
  }
  FlowerRotation::SETUP_MOTOR(STEP_DELAY,A_1,A_2,B_1,B_2);
  delay(5);
}
Motor m(STEP_DELAY,A_1,A_2,B_1,B_2);
void loop(){

  //setFlower(int step,int _initLed,int _initSensorReading)

  //ledTest();
  //popSensor();
//   //ADD AVS TO AVERAGES
//    for(int i=0; i<4; i++){
//     Serial.println("-----8");
//     averages[i] = getAverage(sensors[i]);
//     Serial.print("av:   ");
//     Serial.println(averages[i]);
//    }
//     // ledFollow(Reading.returnTopThree()[0],
//     //  Reading.returnTopThree()[1]);
// //ROTATION CALLS
//   FlowerRotation fr(averages);
  if(step>6){
    step = 0;
  }
  Serial.println(analogRead(A5));
  if(analogRead(A5) < 200){
    m._abstractRotation(step);
    step++; Serial.println("STEP:  ");Serial.println(step);
  }
  //delay(500);
  //delay(COMPARE_INTERVAL);
}

void popSensor(){
  //Serial.println("-----7");
  for(int s=0; s<4; s++){
    for(int r=0; r<10; r++){
      sensors[s][r] = mappedReading(analogRead(s));
    }
  }
}

int getAverage(int sensor[10]){
  //Serial.println("-----6");
  int average = 0;
  for(int i=0; i<10; i++){
    average += sensor[i];
  }
  return average/10;
}
//MAPPING TO 100
int mappedReading(int reading){
  return map(reading,0,1023,0,100);
}

void ledFollow(int second, int first){
  lightsOff();
  Serial.println("TOP BIRDS");
  Serial.println(first);Serial.println(second);
  digitalWrite(second+2,HIGH);  //led pins startin from 2
  digitalWrite(first+2,HIGH);
  delay(10);
  digitalWrite(first+2,LOW);
  delay(10);
}
void lightsOff(){
  for(int i=2; i<6; i++){
    digitalWrite(i,LOW);
  }
}
//----------------Tests--------------
void ledTest(){
  for(int i=2; i<6; i++){
    digitalWrite(i,HIGH);
    delay(10);
    digitalWrite(i,LOW);
  }
}
void testMotor(){

}
