#ifndef TestReading_h
#define TestReading_h

#include "Reading.h"

class TestReading {
  public:
    TestReading();
    ~TestReading();
    float totallyFakeAverages[4] = { 40.4, 20.5, 80.2, 120.2 };
    void getTotallyFakeFirstValue();
    void getTotallyFakeSecondSensor();
  private:
    Reading* _reading = nullptr;
};

#endif
