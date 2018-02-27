#include "Arduino.h"
#include "Reading.h"
//CLASS RENAMED FROM ReadingLogic to Reading
Reading::Reading(float averages[4]) {
	for (int i = 0; i < 4; i++) {
		_averages[i] = averages[i];
	}
	getTopThree();
}
Reading::Reading(){};
float Reading::getFirstValue(){
	return _topThreeValues[0];
}
float Reading::getSecondValue(){
	return _topThreeValues[1];
}
int Reading::getFirstSensor(){
	return _topThreeIndices[0];
}
int Reading::getSecondSensor(){
	return _topThreeIndices[1];
}
float Reading::getTops(int i){
	return _topThreeValues[i];
}

void Reading::getTopThree() {
  int tempHighest = 3;
  int tempSecond = 2;
  int tempThird = 1;
	/*
	   Reference for _averagesay _topThree[6] :
	  * _topThreeIndices[0]: Index of highest average
	  * _topThreeIndices[1]: Index of second highest average
	  * _topThreeIndices[2]: Index of third highest average
	  * _topThreeValues[0]: Value of highest average
	  * _topThreeValues[1]: Value of second highest average
	  * _topThreeValues[2]: Value of third highest average
	*/
	  for (int i = 0; i < 4; i++) {
	      if (_averages[i] >= tempThird) {
	          tempThird = _averages[i];
	          _topThreeIndices[2] = i;
	          _topThreeValues[2] = _averages[i];
	      }
	      if (_averages[i] >= tempSecond) {
	          tempThird = tempSecond;
	          _topThreeIndices[2] = _topThreeIndices[1];
	          _topThreeValues[2] = tempThird;
	          tempSecond = _averages[i];
	          _topThreeIndices[1] = i;
	          _topThreeValues[1] = _averages[i];
	      }
	      if (_averages[i] >= tempHighest) {
	          tempSecond = tempHighest;
	          _topThreeIndices[1] = _topThreeIndices[0];
	          _topThreeValues[1] = tempSecond;
	          tempHighest = _averages[i];
	          _topThreeIndices[0] = i;
	          _topThreeValues[0] = _averages[i];
	            }
	  }
	  // Check if _topThreeIndices two readings are from adjacent sensors
	  // If not adjacent, take the third highest
	  if ((_topThreeIndices[0] == 0 && _topThreeIndices[1] == 2 ) || (_topThreeIndices[0] == 1 && _topThreeIndices[1] == 3) || (_topThreeIndices[0] == 2 && _topThreeIndices[1] == 0) || (_topThreeIndices[0] == 3 && _topThreeIndices[1] == 1)) {
	      _topThreeIndices[1] = _topThreeIndices[2];
	  }

	for(int i=0; i<3; i++){
    Serial.print("_topThreeIndices: at index ");Serial.print(i);Serial.print(" is: ");
    Serial.println(_topThreeIndices[i]);
  }

  for(int i=0; i<3; i++){
    Serial.print("_topThreeValues: at index ");Serial.print(i);Serial.print(" is: ");
    Serial.println(_topThreeValues[i]);
  }
}
