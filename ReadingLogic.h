#ifndef ReadingLogic_h
#define ReadingLogic_h

#include "Arduino.h"

class ReadingLogic{
	public:
		ReadingLogic(int* averages);
		int* getTopTwo();

	private:
		int* _averages;
		int* topAves;
};
#endif
