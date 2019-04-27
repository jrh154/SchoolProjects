#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float lowTemp = 30.0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  sensors.begin();
  // Print a message to the LCD.
  lcd.print("Temp: ");
  lcd.setCursor(0,1);
  lcd.print("Low Temp: ");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  sensors.requestTemperatures();
  float currTemp = sensors.getTempCByIndex(0);
  if (currTemp < lowTemp) {
    lowTemp = currTemp;
  }
  lcd.setCursor(6, 0);
  lcd.print(currTemp);
  lcd.print("        ");
  lcd.setCursor(10, 1);
  lcd.print(lowTemp);
  lcd.print("   ");
  delay(1000);
}
