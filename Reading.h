#ifndef Reading_h
#define Reading_h

#include "Arduino.h"
//Class RENAMED FROM ReadingLogic to Reading
class Reading{
	public:
		Reading(int* averages);
    ~Reading(){};
		void findTopThree();
	private:
		int*  _averages;
		int _topThree[5];
};
#endif
