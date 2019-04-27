// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pressure Sensor Set-up
int rawPressure = 0;
float rawVoltage = 0.0;
float pressure = 0.0;

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Pressure: ");
  lcd.setCursor(13, 1);
  lcd.print("kPa");
}

void loop() {
  int rawPressure = analogRead(A5);
  float rawVoltage = fmap(rawPressure, 0, 1023, 0.0, 5.0);
  pressure = 1/0.0018*(rawVoltage/5-0.0352);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print(pressure);
  lcd.print("     ");
  delay(500);
  Serial.println(rawPressure);
  // print the number of seconds since reset:
  
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
