#include "AS726X.h"
AS726X sensor;
int usrInput = 0;
float calData[5];
int calRun = 0;

void setup() {
  sensor.begin();
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    usrInput = Serial.read();
    if (usrInput == 67 || usrInput == 99) {
        sensor.takeMeasurements();
        calData[0] = sensor.getCalibratedViolet();
        calData[1] = sensor.getCalibratedBlue();
        calData[2] = sensor.getCalibratedGreen();
        calData[3] = sensor.getCalibratedYellow();
        calData[4] = sensor.getCalibratedOrange();
        calData[5] = sensor.getCalibratedRed();
        calRun = 1;
        Serial.println("Calibration successful. Please begin measurements.");
    }
    else if (calRun == 0) {
      Serial.println("Please run a blank standard before taking measurements");
    }
    else if (usrInput == 66 || usrInput == 98) { //blue, B = 66, b = 98
      Serial.print("The blue measurement is: ");
      float reading = blueMeasurement();
      reading = log(reading/calData[0]);
      Serial.println(reading);      
    }
    else if(usrInput == 82 || usrInput == 114) { //red, R = 82, r = 114
      Serial.print("The red measurement is: ");
      float reading = redMeasurement();
      Serial.println(reading);
    }
    else if(usrInput == 79 || usrInput == 111) { //orange, O = 79, o = 111
      Serial.print("The orange measurement is: ");
      float reading = orangeMeasurement();
      Serial.println(reading);
    }
    else if(usrInput == 89 || usrInput == 121) { //yellow, Y = 89, y = 121
      Serial.print("The yellow measurement is: ");
      float reading = yellowMeasurement();
      Serial.println(reading);
    }
  }
}


float blueMeasurement () {
  sensor.takeMeasurements();
  float data = sensor.getCalibratedBlue();
  return data;
}

float redMeasurement () {
  sensor.takeMeasurements();
  float data = sensor.getCalibratedRed();
  return data;
}

float yellowMeasurement () {
  sensor.takeMeasurements();
  float data = sensor.getCalibratedYellow();
  return data;
}

float orangeMeasurement () {
  sensor.takeMeasurements();
  float data = sensor.getCalibratedOrange();
  return data;
}
