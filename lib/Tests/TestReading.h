#ifndef TestReading_h
#define TestReading_h

#include "Reading.h"

class TestReading {
  public:
    TestReading();
    ~TestReading();
    int totallyFakeAverages[4] = { 40, 20, 80, 120 };
    void getTotallyFakeFirstValue();
    void getTotallyFakeSecondSensor();
  private:
    Reading* _reading = nullptr;
};

#endif
