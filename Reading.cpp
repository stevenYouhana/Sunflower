#include "Arduino.h"
#include "Reading.h"
//CLASS RENAMED FROM ReadingLogic to Reading
Reading::Reading(int* _averages) {
	this-> _averages = _averages;
}
//NOW VOID since this class is being used as composition for FlowerRotation
void Reading::findTopThree() {
  int tempHighest = 3;
  int tempSecond = 2;
  int tempThird = 1;
	/*
   Reference for _averagesay _topThree[6] :
  * _topThree[0]: Index of highest average
  * _topThree[1]: Index of second highest average
  * _topThree[2]: Index of third highest average
  * _topThree[3]: Value of highest average
  * _topThree[4]: Value of second highest average
  * _topThree[5]: Value of third highest average
*/
  for (int i = 0; i < 4; i++) {
      if (_averages[i] >= tempThird) {
          tempThird = _averages[i];
          _topThree[2] = i;
          _topThree[5] = _averages[i];
      }
      if (_averages[i] >= tempSecond) {
          tempThird = tempSecond;
          _topThree[2] = _topThree[1];
          _topThree[5] = tempThird;
          tempSecond = _averages[i];
          _topThree[1] = i;
          _topThree[4] = _averages[i];
      }
      if (_averages[i] >= tempHighest) {
          tempSecond = tempHighest;
          _topThree[1] = _topThree[0];
          _topThree[4] = tempSecond;
          tempHighest = _averages[i];
          _topThree[0] = i;
          _topThree[3] = _averages[i];
      }
  }
  // Check if _topThree two readings are from adjacent sensors
  // If not adjacent, take the third highest
  if ((_topThree[0] == 0 && _topThree[1] == 2 ) || (_topThree[0] == 1 && _topThree[1] == 3) || (_topThree[0] == 2 && _topThree[1] == 0) || (_topThree[0] == 3 && _topThree[1] == 1)) {
      _topThree[1] = _topThree[2];
  }
}
