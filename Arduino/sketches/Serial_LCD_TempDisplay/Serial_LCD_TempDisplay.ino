#include <Wire.h>//to control I2C
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>//ds18b20
#include <DallasTemperature.h>//ds18b20 
/********************************************************************/
#define ONE_WIRE_BUS 10//Temp sensor bus is on pin 11
OneWire oneWire(ONE_WIRE_BUS);//setup a oneWire reference instance to communicate with any OneWire devices
//OneWire oneWire2(ONE_WIRE_BUS);
DallasTemperature sensors (&oneWire);//pass the oneWire reference to Dallas Temperature
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
/********************************************************************/
int aTemp1; 
/*********************************************************************/

void setup() {
  Serial.begin(9600);//make sure gobetwino mathces this
  delay(5000);
  sensors.begin();//initialize the temp sensors
  lcd.init();//intializes the lcd
  lcd.backlight();//turn on the lcd backlight
  lcd.clear();//clears the lcd and positions the cursor in the upper-left corner.
  //Serail & lcd print update
  Serial.println("system on");
  lcd.setCursor(0,0);
  lcd.print("system on");
  delay(5000);//wait 5 seconds to say system on
  lcd.clear();//wipe lcd
}

void loop() {
  //save temp readings into variables to be passed as arguments to tempLog()
  sensors.requestTemperatures();//always request a new temperature
  aTemp1 = sensors.getTempCByIndex(0);
  Serial.print("Temp: ");
  Serial.print(aTemp1);
  Serial.println(" Celsisus");
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(aTemp1);
  delay(5000);
}
