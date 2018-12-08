/*
This program will maintain the Air temp within a user given range
The temp is regulated by an AC unit that is turned on when the temp is too high
The AC remains on till a user set temp is reached, the AC then turns of after a user given amount of time
The lights switch between on and off time durations
the exhaust fan is on if the AC is off
the intake fan is always on (hardwired)
the ciruclation fans are always on (hardwired)
the pump is always on (hardwired)
The continuous circulation of water through the 3 chambers keeps the water oxygenated

grow chamber user must manually refresh the system with new bacteria once every 2 weeks
---the code could display an "refresh filter" message after a 2 week time lapse ---
---a water cooler for cooling the system water is required for best results in future---
---in cold climates, a water heater will be necessary---
---a humidifier can be attached to the unit to respond to the humidity sensor---
--- cameras can be mounted internally in humidity proof containers---
---the program can take pics at once a day rate---

UTILITY
This unit allows 24 potted plants to be grown with proper lighting, air temp ( and humidity), hydration,
oxygenation, air circulation autonomously
user need only refresh bacteria and observe progress

TO DO
add the humidity sensor
add an lcd library and lcd output code - display avg temp, temp1, & temp2; screen 2 display LED status timer
add humidity sensor responsive humidifier
add live stream camera and timed pic cloud upload
*/
/********************************************************************/


/*rough grow chamber control program*/


//Libraries
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
//relay control variables
const int iN1 = 2;//LEDS
const int iN2 = 4;//AC
const int iN3 = 5;//Exhaust Fan
const int iN4 = 6;//Humidifier
/********************************************************************/
int acStatus = 0;
unsigned long acTimer;//used to reset the timer to current millis
unsigned long ledTimer;//used to switch LED status (same as previousMillis)
unsigned long lcdTimer;//used to switch display lcdStages 
const long ledOn = 50400000;//14 hours
const long ledOff = 36000000;//10 hours
const long acDelay = 2760000;//approximately 45 minutes
const long lcdDelay = 10000;//10 second posting
const long startTimer = 60000;
boolean ledKey = 0;
int stage;
int lcdStage;
/********************************************************************/
char array1[]="Root Culture LLC               "; //the string to print on the LCD
char array2[]="Test Print             "; //the string to print on the LCD
int tim = 500; //the value of delay time
// initialize the library with the numbers of the interface pins
/********************************************************************/
void setup() {
  //Serial & LCD setup
  Serial.begin(9600);
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight
  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left  corner.
  //Serial & LCD print update 
  Serial.println("System On");
  
  //start up the library
  sensors.begin();
  //setup the output pins for the relay
  pinMode(iN1, OUTPUT);//LEDS
  pinMode(iN2, OUTPUT);//AC
  pinMode(iN3, OUTPUT);//Exhaust Fan
  pinMode(iN4, OUTPUT);//Humidifier
  digitalWrite(iN2, HIGH);//start with the AC off
  digitalWrite(iN1, HIGH);//default with LEDs off
  stage = 2;
  acTimer = 0;
  ledTimer = 0;
}
/********************************************************************/
void loop() {
  // put your main code here, to run repeatedly:
  getTemp();//post temp to Serial monitor
  tempAvg();//average the temp and post to Serial monitor
  LEDs();//8.5 hour start with lights off
  smartAC();//Turn the AC on/off in response to temp changes
  exhaustFan();//Turn exhaust fan on/off in response to AC
  lcdOutput();
  /*The Circulation fans, intake fan, and pump are always on*/
  }

/*BELOW ARE THE FUNCTIONS CALLED IN THE LOOP*/
/********************************************************************/
void getTemp(){
  //call the ds18b20 functions and post the temp to the Serial monitor
  ds18b20_1();
  ds18b20_2();
}

void ds18b20_1(){
  //send the command to get the temperature
  sensors.requestTemperatures();
  Serial.print("Temp1; ");
  Serial.println(sensors.getTempCByIndex(0));//0 refers to the first IC on the wire
  
}

void ds18b20_2(){
  //send the command to get the temperature
  sensors.requestTemperatures();
  Serial.print("Temp2: ");
  Serial.println(sensors.getTempCByIndex(1));//1 refers to the second IC on the wire
}

int tempAvg(){
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

void LEDs(){
  unsigned long currentMillis = millis();
  
  if(stage == 0){//LED ON timer 16 hours
    if(currentMillis - ledTimer >= ledOn){//If the LEDs have been on past the on time
      ledTimer = currentMillis;//updates the global variable to millis(), this resets the timer
      digitalWrite(iN1, HIGH);//turn the LEDs off
      stage = 1;//switch to the LED OFF timer stage
    }
    else{
      Serial.print("LED ON remaining: ");
      Serial.print(ledOn - (currentMillis - ledTimer));
      digitalWrite(iN1, LOW);//keep the LEDs on if the time is not up yet 
    }
  }
  else if (stage == 1){//LED OFF timer 8 hours
    if(currentMillis - ledTimer >= ledOff){//If the LED off time is up
      ledTimer = currentMillis;//reset the timer on the LEDs
      digitalWrite(iN1, LOW);//turn the LEDs on
      stage = 0;//switch to the LED on timer stage
    }
    else{
      digitalWrite(iN1, HIGH);//keep the LEDs off if the time is not up yet
      Serial.print("LED OFF remaining: ");
      Serial.print(ledOff - (currentMillis - ledTimer));
    }
  }
  else if(stage == 2){
    if(currentMillis - ledTimer < startTimer){
      Serial.print("LED start time remaining: ");
      Serial.print(startTimer - (currentMillis - ledTimer));
      if(ledKey == 0){
        digitalWrite(iN1, HIGH);//LEDs off
      }
      else if(ledKey == 1){
        digitalWrite(iN1, LOW); //LEDs on
      }
    }
    else if (currentMillis - ledTimer >= startTimer ){
      ledTimer = currentMillis;//reset the timer
      if(ledKey == 0){
        stage = 0;
      }
      else{
        stage = 1;
      }
    }
  }
 }

  void smartAC(){
    //Best temp for indoor tomatoes is 23.8 degC - 29.4 degC
    //Therefore the AC should turn on if the temp exceeds 29.4 degC
    int currentTemp;
    currentTemp = tempAvg();
    if(acStatus == 0){ //Idle
      if(currentTemp <= 29.4){
      digitalWrite(iN2, HIGH);//temp is ok AC OFF
      }
      else{
        acStatus = 1;
        digitalWrite(iN2, LOW);//temp is too high AC ON
      }
    }
    else if(acStatus == 1){// AC response mode
     if(currentTemp <= 28.5){// optimum temp range resotred, switch to idle
      acStatus = 2;
      acTimer = millis();
     }
     else{// remain active till optimum temp range restored
      digitalWrite(iN2, LOW);
     }
    }
    else if(acStatus == 2){// Delayed restore to idle
      if(millis() - acTimer < acDelay){// if the delay is not over
        digitalWrite(iN2, LOW);//keep the AC on
      }
      else{
        digitalWrite(iN2, HIGH);//return to idle
        acStatus = 0; //reset the AC status to 0 (temp is in acceptable range, AC OFF)
      }
    }
  }

void exhaustFan(){//responds to the AC status
  boolean key;
  key = digitalRead(iN2);
  if(key == HIGH){//AC OFF
    digitalWrite(iN3, LOW);//turn on the exhaust
  }
  else{
    digitalWrite(iN3, HIGH);//if AC is ON keep the fan off
  }
}

int ledTimeRemaining(){
  unsigned long remT;
  unsigned long currentMillis = millis();
  unsigned long currentTime = currentMillis - ledTimer;
  if(stage == 0){
    remT = ledOn - currentTime;
    return remT;
  }
  else if(stage == 1){
    remT = ledOff - currentTime;
    return remT;
  }
  else if(stage == 2){
    remT = startTimer - currentTime;
    return remT;
  }
}


void lcdOutput(){
  unsigned long currentMillis = millis();
  if(lcdStage == 0){
    if(currentMillis - lcdTimer < lcdDelay){
      lcd.setCursor(0,0);
      lcd.print("temp 1: ");
      lcd.print(sensors.getTempCByIndex(0));//0 refers to the first IC on the wire
      lcd.setCursor(0,1);
      lcd.print("temp 2: ");
      lcd.print(sensors.getTempCByIndex(1));//0 refers to the first IC on the wire
    /*
    }
    else{
      lcd.clear();
      lcd.print("Root Culture LLC");
      lcdStage = 1;
      lcdTimer = currentMillis;
    }
  }
  else if(lcdStage == 1){
    if(currentMillis - lcdTimer < lcdDelay){
      lcd.setCursor(0,0);
      lcd.print("Root Culture LLC");
    }
    else{
      lcd.clear();
      lcd.print("temp avg: ");
      lcd.print(tempAvg());
      lcdStage = 2;
      lcdTimer = currentMillis;
    }
  }
  else if(lcdStage == 2){
    if(currentMillis - lcdTimer < lcdDelay){
      lcd.setCursor(0,0);
      lcd.print("temp avg: ");
      lcd.print(tempAvg());
    }
    else{
      lcd.clear();
      lcdStage = 3;
      lcdTimer = currentMillis;
    }
  }
  else if(lcdStage == 3){
    if(currentMillis - lcdTimer < lcdDelay){
      lcd.setCursor(0,0);
      if(stage == 0){
        lcd.print("LED ON: ");
        lcd.print(ledTimeRemaining());
      }
      else if(stage == 1){
        lcd.print("LED OFF: ");
        lcd.print(ledTimeRemaining());
      }
      else if(stage == 2){
        lcd.print("LED STRT: ");
        lcd.print(ledTimeRemaining());
      }
    }
    else{
      lcd.clear();
      lcdStage = 0;
      lcdTimer = currentMillis;
    }*/
  }
}
}

