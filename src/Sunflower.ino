#include "FlowerRotation.h"

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
const int initSensor = A5;

bool flowerSet;
FlowerRotation fr;

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
  fr.SETUP_MOTOR(STEP_DELAY,A_1,A_2,B_1,B_2);
  flowerSet = false;
  delay(5);
}

void loop(){
  //check flowerSet if false initFlower else FlowerRotation
  while(!flowerSet){
    if(mappedReading((analogRead(initSensor))) < 25){
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
  Serial.println(mappedReading(analogRead(initSensor)));
  //Normal opperation
  popSensor();
   //ADD AVS TO AVERAGES
   for(int i=0; i<4; i++){
    averages[i] = getAverage(sensors[i]);
    // Serial.print("av:   ");
    // Serial.println(averages[i]);
 //     // ledFollow(Reading.returnTopThree()[0],
 //     //  Reading.returnTopThree()[1]);
    }
  fr = FlowerRotation(averages);
  fr.update();
  delay(10000);
}

void popSensor(){
  for(int s=0; s<4; s++){
    for(int r=0; r<10; r++){
      sensors[s][r] = mappedReading(analogRead(s));
    }
  }
}

int getAverage(int sensor[10]){
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
