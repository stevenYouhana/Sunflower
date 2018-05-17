#ifndef BigPicture_h
#define BigPicture_h

#include <math.h>

class BigPicture {
public:
	BigPicture();
	~BigPicture();
	void update();
	void rotationAngle(int top, int second, int topSensor, int secondSensor);
	float radToDeg(float rad);
	int getTopSensorAngle(int topSensor);
	float map90_1024(float angle);	//to motor
	
	void setFakeReadings(float v1, float v2, int s1, int s2);
	float getCurrentPosition();
	float getNewPosition();

	//TEST VALUES 
	float firstValue; 
	float secondValue; 
        int firstSensor; 
	int secondSensor;

	static float currentPosition;
   	float newPosition; 
private:
	
};
#endif
