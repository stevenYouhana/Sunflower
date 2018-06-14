#include <iostream>
#include "BigPicture.h"

using std::endl;
using std::cout;
using std::string;
using std::to_string;

int main(){
	//change const values as test values
	const float firstValue = 44.34;
	const float secondValue = 56.7;
	const int firstSensor = 1;
	const int secondSensor = 0;

	cout<<"-----FLOWER ROTATION TEST-----"<<endl;
	BigPicture bp;
	//setting fake readings
	bp.setFakeReadings(firstValue,
			   secondValue, 
			   firstSensor,
			   secondSensor);
	
	bp.update();

	string out = "Entered values:\nfirst value:  " + to_string(firstValue) + "\tsecond value: "+ to_string(secondValue) +
		"\tfirst sensor: "+to_string(firstSensor) + "\tsecondSensor: "+to_string(secondSensor);
	
	//getting output
	out += "\ncurrent position: " + to_string(bp.getCurrentPosition());
	out += "\nnew position: " + to_string(bp.getNewPosition());	
	
	cout<<out<<endl;

	return 0;
}
