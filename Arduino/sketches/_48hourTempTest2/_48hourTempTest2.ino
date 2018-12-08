/*
Jonathan Sells 11/20/17

This program:
1. continuously prints the temp readings to the lcd
2. runs a 48 hour timer function a given number of cycles then quits
3. runs a 10 minute timer and saves sensor readings to a file via gobetwino LOGFIL before each reset
4. the program default starts the system with the cooling system off, and alterantes ON/OFF after each 48 hour cycle 

Areas to clean up:
1.The first log is always one measurement short
2.At the conclusion of the cycles the program seems to spaz out, need to command it to stop instead of crashing

*/

#include <Wire.h>//to control I2C
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>//ds18b20
#include <DallasTemperature.h>//ds18b20 
/********************************************************************/
#define ONE_WIRE_BUS 3//Temp sensor bus is on pin 3
OneWire oneWire(ONE_WIRE_BUS);//setup a oneWire reference instance to communicate with any OneWire devices
OneWire oneWire2(ONE_WIRE_BUS);
DallasTemperature sensors (&oneWire);//pass the oneWire reference to Dallas Temperature
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
/********************************************************************/
int aTemp1;
int aTemp2;
int cycleNum = 0;
int cycleNumEnd = 4;//set the max number of cycles 
int logNum;//indicates number of temperature readings that have been saved
String names[4] = {"LOGONE","LOGTWO","LOGTHREE","LOGFOUR"};
unsigned long _48hourIntervalStart = 0;
unsigned long _10minuteIntervalStart = 0;
/*********************************************************************/
//gobetwino variables
int serInLen = 25;
char serInString[25];
int result;

void setup() {
  Serial.begin(9600);//make sure gobetwino mathces this
  Serial.println("hello");
  randomSeed(analogRead(0));
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
  aTemp2 = sensors.getTempCByIndex(1);
  //print temps to the lcd
  lcd.setCursor(0,0);
  lcd.print("T1: ");
  lcd.print(aTemp1);
  lcd.setCursor(0,1);
  lcd.print("T2: ");
  lcd.print(aTemp2);
  lcd.setCursor(7,0);
  lcd.print("log:");
  lcd.print(logNum);
  lcd.setCursor(7,1);
  lcd.print("48T:");
  lcd.print(cycleNum);
  //call the 48 hour timer function
  _48hourTimer(cycleNum,cycleNumEnd);
  //the 48 hour timer function will call the tempLog function every 10 minutes as long as cycle limit not reached
}

void _48hourTimer(int value1, int value2){// value 1 & 2 are filled by cycleNum and cylceNumEnd
  const long _48hours = 20000;//3 seconds in millis
  const long _10minutes = 5000;//10 seconds in millis
  if(value1 <= value2){
    if(millis() - _48hourIntervalStart < _48hours)//if the 48 hour timer is not up check the 10 minute timer
    {
      if(millis() - _10minuteIntervalStart < _10minutes){//if the 10 minute interval is not up yet
        return;//dont do anything
      }
      else//call function to save temperature readings to an email file
      {
        saveTemp(aTemp1,aTemp2);//will send LOGFIL command
        logNum += 1;//increase the log number count by one
        _10minuteIntervalStart = millis();//reset the timer
      }
    }
    else//if the 48 hour timer is up
    {
      cycleNum += 1;//add 1 to the cylce number
      _48hourIntervalStart = millis();//reset the 48 hour timer
      _10minuteIntervalStart = millis();//reset the 10 minute timer as well
      saveTemp(aTemp1,aTemp2);//complete the final temp log
      logNum +=1;//note that the log number has increased as well
    }
  }
  else
  {
    return;//should continual end the program 
  }
}

void saveTemp(int temp1, int temp2){//arguments passed are from the looped sensors requests
  char buffer[5];
  Serial.print("#S|");//start the command to gobetwino
  Serial.print(names[cycleNum]);
  Serial.print("|[");
  Serial.print(itoa((temp1), buffer, 10));
  Serial.print(";");
  Serial.print(itoa((temp2), buffer, 10));
  Serial.println("]#");
  readSerialString(serInString,1000);
}

//read a string from the serial and store it in an array
//you must supply the array variable - return if timeOut ms passes before the string is read
void readSerialString (char *strArray, long timeOut)
{
  long startTime = millis();
  int i;

  while (!Serial.available()){
    if(millis()-startTime >= timeOut){
      return;
    }
  }
  while(Serial.available() && i , serInLen){
    strArray[i] = Serial.read();
    i++;
  }
}
/*
void printName (){
  Serial.print("#S|");
  Serial.print(names[cycleNum]);
  Serial.print("|[");
}
*/
