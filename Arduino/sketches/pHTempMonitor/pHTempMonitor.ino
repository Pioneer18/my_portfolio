//This code was written to be easy to understand.
//Modify this code as you see fit.
//This code will output data to the Arduino serial monitor.
//Type commands into the Arduino serial monitor to control the pH circuit.
//This code was written in the Arduino 1.8.3 IDE
//An Arduino MEGA was used to test this code.
//This code was last tested 6/2017


#include <Wire.h>//to control I2C
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>                                  //ds18b20
#include <DallasTemperature.h>                        //ds18b20 
#define ONE_WIRE_BUS 9
OneWire oneWire(ONE_WIRE_BUS);                        //setup oneWire instance to communicate with any one wire device
DallasTemperature sensors(&oneWire);                  //pass our oneWire reference to Dallas Temperature
LiquidCrystal_I2C lcd(0x27,16,2);                     //set the lcd address to 0x27 for a 16 char 2 line lcd
String inputstring = "";                              //a string to hold incoming data from the PC
String sensorstring = "";                             //a string to hold the data from the Atlas Scientific product
boolean input_string_complete = false;                //have we received all the data from the PC
boolean sensor_string_complete = false;               //have we received all the data from the Atlas Scientific product
float pH;                                             //used to hold a floating point number that is the pH
int temp1;

//relay stuff
const int buttonPin3 = 11;
const int buttonPin2 = 10;
const int buttonPin = 7;
const int pumpPin = 8;
const int pumpPin2 = 6;

int buttonState = 0;
int buttonState2 = 0;

unsigned long pHadjusted = 0;
unsigned long startKey = 0;
unsigned long harvestTime;

void setup() {                                        //set up the hardware
  lcd.init();                                         //initialze the lcd
  lcd.backlight();                                    //turn on the lcd backlight
  lcd.clear();                                        //clear any garbo that may be on the screen
  lcd.setCursor(0,0);
  lcd.print("Temp and pH");
  delay(4000);
  lcd.clear();
  Serial.begin(9600);                                 //set baud rate for the hardware serial port_0 to 9600
  Serial3.begin(9600);                                //set baud rate for software serial port_3 to 9600
  sensors.begin();                                    //begin the temp sensor
  inputstring.reserve(10);                            //set aside some bytes for receiving data from the PC
  sensorstring.reserve(30);                           //set aside some bytes for receiving data from Atlas Scientific product

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  digitalWrite(pumpPin2, HIGH);
  digitalWrite(pumpPin, HIGH);
}

void buttonCall(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(pumpPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(pumpPin, LOW);
  }
}

void buttonCall2(){
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(pumpPin2, HIGH);
  } else {
    // turn LED off:
    digitalWrite(pumpPin2, LOW);
  }
}

void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC
}


void serialEvent3() {                                 //if the hardware serial port_3 receives a char
  sensorstring = Serial3.readStringUntil(13);         //read the string until we see a <CR>
  sensor_string_complete = true;                      //set the flag used to tell if we have received a completed string from the PC
}


void (*resetFunc)(void)=0;

void harvest(){
  if(millis() - harvestTime >= 86400000){ //if 24 hours have passed
    digitalWrite(pumpPin, LOW);
    delay(25000); //extract for 25 seconds
    harvestTime = millis(); //reset harvestTime for another 24 hours
  }
}


void loop() {                                         //here we go...
  buttonCall();
  buttonCall2();
  tempCall();                                         //display temp to lcd
  harvest();
  if (input_string_complete == true) {                //if a string from the PC has been received in its entirety
    Serial3.print(inputstring);                       //send that string to the Atlas Scientific product
    Serial3.print('\r');                              //add a <CR> to the end of the string
    inputstring = "";                                 //clear the string
    input_string_complete = false;                    //reset the flag used to tell if we have received a completed string from the PC
  }


  if (sensor_string_complete == true) {               //if a string from the Atlas Scientific product has been received in its entirety
    lcd.setCursor(7,0);
    lcd.print("pH:");
    lcd.print(sensorstring);
    Serial.println(sensorstring);                     //send that string to the PC's serial monitor
   /*                                                 //uncomment this section to see how to convert the pH reading from a string to a float 
    if (isdigit(sensorstring[0])) {                   //if the first character in the string is a digit
      pH = sensorstring.toFloat();                    //convert the string to a floating point number so it can be evaluated by the Arduino
      if (pH >= 7.0) {                                //if the pH is greater than or equal to 7.0
        Serial.println("high");                       //print "high" this is demonstrating that the Arduino is evaluating the pH as a number and not as a string
      }
      if (pH <= 6.99) {                               //if the pH is less than or equal to 6.99
        Serial.println("low");                        //print "low" this is demonstrating that the Arduino is evaluating the pH as a number and not as a string
      }
    }
  */
   pH = sensorstring.toFloat();
   if(pH < 7.0 && millis() - pHadjusted >= 180000) {
    digitalWrite(pumpPin2, LOW);
    delay(10000);//wait 20 seconds
    digitalWrite(pumpPin2, HIGH);
    pHadjusted = millis();
   }
  }

  if(temp1 < 0 || temp1 > 100){
    resetFunc();
  }
  sensorstring = "";                                  //clear the string:
  sensor_string_complete = false;                     //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
 
}

void tempCall(){
  sensors.requestTemperatures();                      //sen the command to get the temperatures
  temp1 = sensors.getTempCByIndex(0);
  lcd.setCursor(0,0);
  lcd.print("T: ");
  lcd.print(temp1);
}


