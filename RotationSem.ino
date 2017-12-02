#include <StandardCplusplus.h>
#include <vector>

using std::vector;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
const int READING_INTERVAL = 5;
const int COMPARE_INTERVAL = 20;

int sensors[4][10];
int averages[4];

void setup(){
  Serial.begin(9600);
  Serial.println("start...");
  for(int i=2; i<6; i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
//  for(int i=2; i<6; i++){
//    digitalWrite(i,HIGH);
//    delay(100);
//    digitalWrite(i,LOW);
//  }
  popSensor();
   //ADD AVS TO AVERAGES 
   for(int i=0; i<4; i++){
    averages[i] = getAverage(sensors[i]);
    Serial.print("Average: ");
    Serial.println(averages[i]);
   }
   int topAves[2];
   getTopTwo(averages, topAves);
   Serial.print("TOP BIRDS: ");
   Serial.println(topAves[0]);
   Serial.println(topAves[1]);
   ledFollow(topAves[0],topAves[1]);
}

void popSensor(){
  for(int s=0; s<4; s++){
    for(int r=0; r<10; r++){
      sensors[s][r] = mappedReading(analogRead(s));  
    }
  }
  delay(5);
}

int getAverage(int sensor[10]){
  int average = 0;
  for(int i=0; i<10; i++){
    average += sensor[i];
  }
  return average/10;
}

int mappedReading(int reading){
  return map(reading,0,1023,0,255);
}

int *getTopTwo(int avs[4], int top[2]){
    int tempHighest = 2;
    int tempSecond = 1;
    for (int i = 0; i < 4; i++) {
        if (avs[i] >= tempSecond) {
            tempSecond = avs[i];
            top[1] = i;
        }
        if (avs[i] >= tempHighest) {
            tempSecond = tempHighest;
            top[1] = top[0];
            tempHighest = avs[i];
            top[0] = i;
        }
    }
    return top;
}
void ledFollow(int first, int second){
  lightsOff();
  digitalWrite(second+2,HIGH);  //led pins startin from 2
  digitalWrite(first+2,HIGH);
  delay(500);
  digitalWrite(first+2,LOW);
  delay(500);
}
void lightsOff(){
  for(int i=2; i<6; i++){
    digitalWrite(i,LOW);
  }
}

