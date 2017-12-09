class ReadingLogic {
	public:
		int* topAves = new int[2];
		int* getTopTwo(int avs[4]){
		  for(int i=0; i<4; i++){
			Serial.println("-----5");
			Serial.println("AVS: ");
			Serial.println(avs[i]);
		  }
		  boolean find=false;
		  boolean flag=true;
		  topAves[0] = 0;
		  topAves[1] = 0;
		  topAves[2] = avs[0];
		  topAves[3] = avs[0];
		  //topAves[0] _1stSensorNo
		  //topAves[1] _2ndSensorNo
		  //topAves[2] _1stSensorValue
		  //topAves[3] _2ndSensorValue
		  while(flag){
			for(int i=0; i<4; i++){
			  if(avs[i] > topAves[2]){
				Serial.println("-----4");
				find=true;
				topAves[3] = topAves[2];  //value
				topAves[1] = topAves[0];  //sensorNo
				topAves[2] = avs[i];
				topAves[0] = i;
			  }
			  else if(avs[i] > topAves[3]){
				Serial.println("-----3");
				find=true;
				topAves[1] = i;
				topAves[3] = avs[i];
			  }
			}
			if(find){
			  Serial.println("-----2");
			  flag=false;
			}
			else{
			  Serial.println("-----1");
			  topAves[1] = 1;
			  topAves[0] = 1;
			  topAves[3] = avs[1];
			  topAves[2] = avs[1];
			}
		  }	
		//delay(5000);
	return topAves;
}
};