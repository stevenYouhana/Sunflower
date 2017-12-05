#include <StandardCplusplus.h>
#include <vector>

using std::vector;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

const int READING_INTERVAL = 10000;
const int COMPARE_INTERVAL = 20000;
int sensors[4][10];
int averages[4];
int** topAves = new int*[2];

void setup(){
  Serial.begin(9600);
  Serial.println("start...");
  for(int i=2; i<6; i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  popSensor();
   //ADD AVS TO AVERAGES 
   for(int i=0; i<4; i++){
    Serial.println("-----8");
    averages[i] = getAverage(sensors[i]);
   }
   
   getTopTwo(averages);
   Serial.println("TOP BIRDS: ");
   Serial.println(topAves[0][0]);
   Serial.println(topAves[0][1]);
   Serial.println("TOP VALUES: ");
   Serial.println(topAves[1][0]);
   Serial.println(topAves[1][1]);
   ledFollow(topAves[0][1],topAves[0][0]);
}


void popSensor(){
  Serial.println("-----7");
  for(int s=0; s<4; s++){
    for(int r=0; r<10; r++){
      sensors[s][r] = mappedReading(analogRead(s));
    }
  }
}

int getAverage(int sensor[10]){
  Serial.println("-----6");
  int average = 0;
  for(int i=0; i<10; i++){
    average += sensor[i];
  }
  return average/10;
}

int mappedReading(int reading){
  return map(reading,0,1023,0,255);
}

int** getTopTwo(int avs[4]){
  for(int i=0; i<4; i++){
    Serial.println("-----5");
    Serial.println(avs[i]);
  }
  boolean find=false;
  boolean flag=true;
//  int _1stSensorValue = sensors[0];
//  int _2ndSensorValue = sensors[1];
  topAves[0][1] = 0;
  topAves[0][0] = 0;
  topAves[1][0] = avs[0];
  topAves[1][1] = avs[0];
  //topAves[0][0] _1stSensorNo
  //topAves[0][1] _2ndSensorNo
  //topAves[1][0] _1stSensorValue
  //topAves[1][1] _2ndSensorValue
  while(flag){
    for(int i=0; i<4; i++){
      if(avs[i] > topAves[1][0]){
        Serial.println("-----4");
        find=true;
        topAves[1][1] = topAves[1][0];  //value
        topAves[0][1] = topAves[0][0];         //sensorNo
        topAves[1][0] = avs[i];
        topAves[0][0] = i;
      }
      else if(avs[i] > topAves[1][1]){
        Serial.println("-----3");
        find=true;
        topAves[0][1] = i;
        topAves[1][1] = avs[i];
      }
    }
    if(find){
      Serial.println("-----2");
      //Serial.print("SECOND VAL: "); Serial.println(_2ndSensorValue);
      flag=false;
    }
    else{
      Serial.println("-----1");
      topAves[0][1] = 1;
      topAves[0][0] = 1;
      topAves[1][1] = avs[1];
      topAves[1][0] = avs[1];
    }
  }
  //Serial.print("FIRST VAL: "); Serial.println(_1stSensorValue);
  return topAves;
}
void ledFollow(int second, int first){
  lightsOff();
  digitalWrite(second+2,HIGH);  //led pins startin from 2
  digitalWrite(first+2,HIGH);
  delay(500);
  digitalWrite(first+2 ,LOW);
  delay(500);
}
void lightsOff(){
  for(int i=2; i<6; i++){
    digitalWrite(i,LOW);
  }
}


