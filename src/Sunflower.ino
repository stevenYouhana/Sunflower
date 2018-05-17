#include "FlowerRotation.h"
#include "TestReading.h"

//test leds
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

//Placement compass; using Keyes KY 024 Hall Sensor for table placement
const byte KY024 = A1;
int KY024_reader;
const int NORTH = 0;  //FIX
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
  KY024 = 0;
  Serial.begin(9600);
  Serial.println("start...");
  // for(int i=2; i<7; i++){
  //   pinMode(i,OUTPUT);
  // }
  // fr.SETUP_MOTOR(STEP_DELAY,A_1,A_2,B_1,B_2);
  // flowerSet = false;
  delay(5);
}

void loop(){
  tr = TestReading();
  tr.getTotallyFakeFirstValue();
  tr.getTotallyFakeSecondSensor();
  //Placement
  if(analogRead(KY024) >= NORTH) {
    digitalWrite(NORTH_LED,HIGH);
  }
  //check flowerSet if false initFlower else FlowerRotation
<<<<<<< HEAD
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
=======
  // while(!flowerSet){
  //   if(mappedReading((analogRead(initSensor))) < 25){
  //     Serial.println("setting flower...");
  //     Serial.println(mappedReading(analogRead(initSensor)));
  //     fr.setFlower();
  //   }
  //   else{
  //     flowerSet = true;
  //     break;
  //   }
  // }
  // Serial.println("Normal operation...");
  // Serial.println(mappedReading(analogRead(initSensor)));
  // //Normal opperation
  // popSensor();
  //  //ADD AVS TO AVERAGES
  //  for(int i=0; i<4; i++){
  //   averages[i] = getAverage(sensors[i]);
  //   Serial.print("av:   ");
  //   Serial.println(averages[i]);
  //    // ledFollow(Reading.returnTopThree()[0],
  //    //  Reading.returnTopThree()[1]);
  //   }
  //
  // fr = FlowerRotation(averages);
  // fr.update();
  delay(6000);
>>>>>>> origin/test-reading
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
