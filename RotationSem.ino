<<<<<<< HEAD
#include "TestClass.hpp" 
=======


>>>>>>> dev
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

const int READING_INTERVAL = 10000;
const int COMPARE_INTERVAL = 20000;
int sensors[4][10];
int averages[4];
<<<<<<< HEAD
int** topAves = new int*[2];
TestClass ts;
=======
int* topAves = new int[2];
>>>>>>> dev

void setup(){
  Serial.begin(9600);
  Serial.println("start...");
  for(int i=2; i<6; i++){
    pinMode(i,OUTPUT);
  }
  Serial.println(ts.showNum());
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
   Serial.println(topAves[0]);
   Serial.println(topAves[1]);
   Serial.println("TOP VALUES: ");
   Serial.println(topAves[2]);
   Serial.println(topAves[3]);
   ledFollow(topAves[0],topAves[1]);
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

int* getTopTwo(int avs[4]){
  for(int i=0; i<4; i++){
    Serial.println("-----5");
    Serial.println(avs[i]);
  }
  boolean find=false;
  boolean flag=true;
<<<<<<< HEAD
  topAves[0][1] = 0;
  topAves[0][0] = 0;
  topAves[1][0] = avs[0];
  topAves[1][1] = avs[0];
  //ARRAY CONFIGURATION
  //topAves[0][0] _1stSensorNo
  //topAves[0][1] _2ndSensorNo
  //topAves[1][0] _1stSensorValue
  //topAves[1][1] _2ndSensorValue
=======
//  int _1stSensorValue = sensors[0];
//  int _2ndSensorValue = sensors[1];
  topAves[0] = 0;
  topAves[1] = 0;
  topAves[2] = avs[0];
  topAves[3] = avs[0];
  //topAves[0] _1stSensorNo
  //topAves[1] _2ndSensorNo
  //topAves[2] _1stSensorValue
  //topAves[3] _2ndSensorValue
>>>>>>> dev
  while(flag){
    for(int i=0; i<4; i++){
      if(avs[i] > topAves[2]){
        Serial.println("-----4");
        find=true;
        topAves[3] = topAves[2];  //value
        topAves[1] = topAves[0];         //sensorNo
        topAves[2] = avs[i];
        topAves[0] = i;
      }
      else if(avs[i] > topAves[3]){
        Serial.println("-----3");
        find=true;
        topAves[1] = i;
        topAves[3] = avs[i];
      }
    }
    if(find){
      Serial.println("-----2");
      //Serial.print("SECOND VAL: "); Serial.println(_2ndSensorValue);
      flag=false;
    }
    else{
      Serial.println("-----1");
      topAves[1] = 1;
      topAves[0] = 1;
      topAves[3] = avs[1];
      topAves[2] = avs[1];
    }
  }
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


