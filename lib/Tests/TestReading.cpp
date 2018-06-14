#include "TestReading.h"
#include "Reading.h"
// #include <iostream>

TestReading::TestReading() {
  _reading = new Reading(totallyFakeAverages);
}

TestReading::~TestReading() {
  delete _reading;
}

void TestReading::getTotallyFakeFirstValue() {
  int fakeFirstValue;
  fakeFirstValue = _reading->getFirstValue();
  Serial.print("Totally fake first value is: ");Serial.println(fakeFirstValue);
}

void TestReading::getTotallyFakeSecondSensor() {
  int fakeSecondSensor;
  fakeSecondSensor = _reading->getSecondSensor();
  Serial.print("Totally fake second sensor is: ");Serial.println(fakeSecondSensor);
}
