#ifndef Reading_h
#define Reading_h

#include "Arduino.h"
//Class RENAMED FROM ReadingLogic to Reading
class Reading{
	public:
		Reading(int* averages);
    Reading();
    ~Reading(){};
		int getFirstValue();
		int getSecondValue();
		int getFirstSensor();
		int getSecondSensor();
		void getTopThree();
	private:
		int*  _averages = nullptr;
		int _topThree[6];	//[6]?
};
#endif
