#ifndef Reading_h
#define Reading_h

#include "Arduino.h"
//Class RENAMED FROM ReadingLogic to Reading
class Reading{
	public:
		Reading(float averages[4]);
    Reading();
    ~Reading(){};
		float getFirstValue();
		float getSecondValue();
		int getFirstSensor();
		int getSecondSensor();
		void getTopThree();
		float getTops(int);
	private:
		float  _averages[4];
		float _topThreeValues[3];
		int _topThreeIndices[3];
};
#endif
