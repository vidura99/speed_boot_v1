#define WINDOW_SIZE 5

float  a =       640.3; 
float  b =   0.0001617;  
float  c =      -515.3; 
float  d =    -0.01515;

int readSharpSensor_Left() {
  int sensorValue = analogRead(sharp_Left);  // Read analog value
  int averageValue = Moving_Average(sensorValue);
  return averageValue;
}

int readSharpSensor_Middle() {
  int sensorValue = analogRead(sharp_Middle);  // Read analog value
  int averageValue = Moving_Average(sensorValue);
  return averageValue;
}

int readSharpSensor_Right() {
  int sensorValue = analogRead(sharp_Right);  // Read analog value
  int averageValue = Moving_Average(sensorValue);
  return averageValue;
}



int Moving_Average(int sensorValue) {

  int linearSensorVal = interPlot(sensorValue);
  //int linearSensorVal = sensorValue;

  static int INDEX = 0;
  static int SUM = 0;
  static int READINGS[WINDOW_SIZE];
  int AVERAGED = 0;

  SUM = SUM - READINGS[INDEX];       // Remove the oldest entry from the sum
  READINGS[INDEX] = linearSensorVal;     // Add the newest reading to the window
  SUM = SUM + linearSensorVal;           // Add the newest reading to the sum
  INDEX = (INDEX + 1) % WINDOW_SIZE; // Increment the index, wrap if necessary

  AVERAGED = SUM / WINDOW_SIZE;      // Divide the sum by the window size

 return AVERAGED;
}

int interPlot(int data){
  float f = a*exp(b*data) + c*exp(d*data);
  return f;
}
