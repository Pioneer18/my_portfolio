/*
Jonathan Sells  11/19/17

Program goal: Sample and save the temperatures of the air chamber and biofilter reservoirs every 10 minutes for 48 hours.
Two 48 hour trials are completed, one with the AWC on, and one with the AWC off (Air & Water Control).

Summary: The 560 measurements from the two trials are saved into files labled, "AWC ON" and "AWC off". 
The temperature readings are numbered 1-480 and time stamped in the text files.

Purpose: By comparing the temps of the reservoir chambers and the air chamber with and without AWC, we can determine
the AWC system's base temp control effectiveness.

*/

//Libraries

#include <Wire.h>//to conrol I2C
#include <LiquidCrystal_I2C.h>//for LCD output
#include <OneWire.h>//ds18b20
#include <DallasTemperature.h>//ds18b20

/*------------------------------------------------------------------------------------------------------------------------*/
#define ONE_WIRE_BUS 3//Temp sensor bus is on pin 3
OneWire oneWire(ONE_WIRE_BUS);//setup a oneWire reference to DallasTemperature
OneWire oneWire2(ONE_WIRE_BUS);//setup a second oneWire reference to DallasTempearture
DallasTemperature sensores (&oneWire);//pass the oneWire reference to Dallas Temperature
LiquidCrystal_I2C lcd(0x27,16,2);//set the LCD address to 0x27 for a 16 chars and 2 line display

/*------------------------------------------------------------------------------------------------------------------------*/

//Declerations
int cycleNum;//The cycle number starts on 1
int cycleNumEnd;//totla number of cycles is declared when fucntion called
unsigned long fehIntervalStart;//update after each 48 hour period
unsigned long logIntervalStart;//updated after each 10 minute period
int aTemp1 = 0;
int aTemp2 = 0;

/*------------------------------------------------------------------------------------------------------------------------*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  fehFunction(1,3);
  aTemp1 = sensors.getTempCByIndex(0);
  aTemp2 = sensors.getTempCByIndex(1);
  logData(aTemp1, aTemp2);
}

void fehFunction(int cycleNum, int cycleNumEnd){
  const long fehInterval = 172800000;//48 hours in millis
  unsigned long currentMillis = millis();//currentMillis will always be equal to the total millis(); run time
  if(cycleNum < cycleNumEnd){
    unsigned long fehRunTime = currentMillis;
    if(fehRunTime - fehIntervalStart >= fehInterval)
    {
      fehIntervalStart = fehRunTime;//reset the 48 hour timer
      cycleNum += 1;//update the cycle number total
      //call the "saveTemptoFile();" function for the final temp recording
    }
    else{
      break;
    }
  }
  else{
    if(cycleNum > cycleNumEnd){
      String output = ("Test complete", cycleNum, "cycles completed.");
      Serial.print(output);
      exit(EXIT_SUCCESS);//close the program
    }
  }
}

void logData(int temp1, int temp2){
  char buffer[5];
  Serial.print("#S|TEMPLOG|[");
  Serial.print(itoa((temp1), buffer, 10));//the 10 means we want the data as decimal, the buffer i'm not sure yet
  Serial.print(";");
  Serial.print(itoa((temp2), buffer, 10));
  Serial.println("]#");//end of the command to gobetwino
}

void getTemp(){
  //call the ds18b20 functions and post the temp to the Serial monitor
  ds18b20_1();
  ds18b20_2();
}

void ds18b20_1(){
  //send the command to get the temperature
}

void ds18b20_2(){
  //send the command to get the temperature
  sensors.requestTemperatures();
  Serial.print("Temp2: ");
  Serial.println(sensors.getTempCByIndex(1));//1 refers to the second IC on the wire
}

void tempAvg(){
  int average;
  int i;
  float temp1;
  float temp2;
  for(i = 0;i < 5; i++){
    sensors.requestTemperatures();
    temp1 = sensors.getTempCByIndex(0);
    temp2 = sensors.getTempCByIndex(1);
    average += ((temp1 + temp2) / 2);
  }
  average = average / 5;
  Serial.print("Average Temp: ");
  Serial.println(average);//divide by 5 to average the sum of the 5 averages
  return average;
  average = 0;//reset average
}
