#include "Arduino.h"
#include "ReadingLogic.h"

ReadingLogic::ReadingLogic(int* averages) {
	_averages = averages;
}

int* ReadingLogic::getTopTwo(){
  for(int i=0; i<4; i++){
	Serial.println("-----5");
	Serial.println("_averages: ");
	Serial.println(_averages[i]);
  }
  boolean find=false;
  boolean flag=true;
  topAves[0] = 0;
  topAves[1] = 0;
  topAves[2] = _averages[0];
  topAves[3] = _averages[0];
  //topAves[0] _1stSensorNo
  //topAves[1] _2ndSensorNo
  //topAves[2] _1stSensorValue
  //topAves[3] _2ndSensorValue
  while(flag){
		for(int i=0; i<4; i++){
		  if(_averages[i] > topAves[2]){
			Serial.println("-----4");
			find=true;
			topAves[3] = topAves[2];  //value
			topAves[1] = topAves[0];  //sensorNo
			topAves[2] = _averages[i];
			topAves[0] = i;
		  }
		  else if(_averages[i] > topAves[3]){
			Serial.println("-----3");
			find=true;
			topAves[1] = i;
			topAves[3] = _averages[i];
		  }
		}
		if(find){
		  Serial.println("-----2");
		  flag=false;
		}
		else{
		  Serial.println("-----1");
		  topAves[1] = 1;
		  topAves[0] = 1;
		  topAves[3] = _averages[1];
		  topAves[2] = _averages[1];
		}
  }
//delay(5000);
return topAves;
}
