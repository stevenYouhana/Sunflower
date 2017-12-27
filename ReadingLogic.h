#ifndef ReadingLogic_h
#define ReadingLogic_h

#include "Arduino.h"

class ReadingLogic{
	public:
		ReadingLogic(int* averages);
    ~ReadingLogic(){};
		int* returnTopThree();
	private:
		int*  _averages;
		int _topThree[5];

};
#endif
