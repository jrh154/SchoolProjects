#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float lowTemp = 30.0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
  Serial.println("Starting up...");
  Serial.println("Beginning Measurements...");
  delay(100);
}

void loop() {
  sensors.requestTemperatures();
  float currTemp = sensors.getTempCByIndex(0);
  if (currTemp < lowTemp) {
    if (currTemp > 0) {
        lowTemp = currTemp;  
    }   
  }
  Serial.print("Current Temperature: ");
  Serial.println(currTemp);
  Serial.print("Low Temperature: ");
  Serial.println(lowTemp);
  delay(1000);
}
