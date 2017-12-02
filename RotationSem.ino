#include <StandardCplusplus.h>
#include <vector>

using std::vector;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
const int READING_INTERVAL = 5;
const int COMPARE_INTERVAL = 20;

vector<vector<int>> sensors(4);
int averages[4];
int average = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("start...");
  for(int i=2; i<6; i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  for(int i=2; i<6; i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }
  popSensor();
   //ADD AVS TO AVERAGES 
   for(int i=0; i<4; i++){
    averages[i] = getAverage(sensors[i]);
    Serial.print("Average: ");
    Serial.println(averages[i]);
   }
}

void popSensor(){
  for(int s=0; s<4; s++){
    for(int r=0; r<10; r++){
      sensors[s][r] = mappedReading(analogRead(s));  
    }
  }
  delay(5000);
}

int getAverage(vector<int> sensor){
  average = 0;
  for(int i : sensor){
    average += sensor[i];
  }
  return average/10;
}

int mappedReading(int reading){
  return map(reading,0,1023,0,255);
}
//
//int *getTopTwo(int avs[4], int top[2]){
//  int tempHighest = 0;
//  int tempSecond = 0;
//
//  if(avs[0] > avs[1]){
//    tempHighest = avs[0];
//    tempSecond = avs[1];
//  }
//  else{
//    tempHighest = avs[1];
//    tempSecond= avs[0];
//  }
//  for(int i=0; i<4; i++){
//    if(avs[i] > tempSecond){
//      tempSecond = avs[i];
//      top[1] = i;
//    }
//    if(avs[i] > tempHighest){
//      tempSecond = tempHighest;
//      tempHighest = avs[i];
//      top[0] = i;
//    }
//  }
//  return top;
//}


