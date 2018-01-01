#ifndef Reading_h
#define Reading_h

#include "Arduino.h"
//Class RENAMED FROM ReadingLogic to Reading
class Reading{
	public:
		Reading(int* averages);
    Reading();
    ~Reading(){};
		int* getTopThree();
	private:
		int*  _averages;
		int _topThree[5];	//[6]?
};
#endif
