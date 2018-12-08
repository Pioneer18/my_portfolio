//Some parts of our code are based on Arduino’s 
//AC phase controlling tutorial and 
//we re-used some part of that code as it is including comments.


// AC Phase control is accomplished using the internal 
// hardware timer1 in the arduino
//
// Timing Sequence
// * timer is set up but disabled
// * zero crossing detected on pin 2
// * timer starts counting from zero
// * comparator set to "delay to on" value
// * counter reaches comparator value
// * comparator ISR turns on triac gate
// * counter set to overflow - pulse width
// * counter reaches overflow
// * overflow ISR truns off triac gate
// * triac stops conducting at next zero cross


// The hardware timer runs at 16MHz. Using a
// divide by 256 on the counter each count is 
// 16 microseconds.  1/2 wave of a 60Hz AC signal
// is about 520 counts (8,333 microseconds).


#include <avr/io.h>
#include <avr/interrupt.h>
#include <SPI.h>
#include <PID_v1.h>
#include "Adafruit_MAX31855.h"
#include "SoftwareSerial.h"
#include <LCD16x2.h>
#include <Wire.h>


#define DETECT 2  //zero cross detect
#define GATE  9   //triac gate pwm pin 
#define PULSE 4   //trigger pulse width (counts)
int i =483;

#define DO   3
#define CS   4
#define CLK  5
Adafruit_MAX31855 thermocouple(CLK, CS, DO);

LCD16x2 lcd;
int buttons;

double currentTemperature;

//Define Variables we'll be connecting to
double setPoint, Input, Output;
//Specify the links and initial tuning parameters
double Kp=2, Ki=6, Kd=1;
PID myPID(&Input, &Output, &setPoint, Kp, Ki, Kd, DIRECT);

void setup(){
  
  Serial.begin(9600);
  
  pinMode(DETECT, INPUT);     //zero cross detect
  digitalWrite(DETECT, HIGH); //enable pull-up resistor //LOW IS ACTUALLY HIGH
  pinMode(GATE, OUTPUT);      //triac gate control
  setPoint = 35;     // set the default temperature as the setPoint
  
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0, 449);
  
  Wire.begin();
  lcd.lcdClear();
  setDefaultLCD();
  
  // set up Timer1 
  //(see ATMEGA 328 data sheet pg 134 for more details)
  OCR1A = 100;      //initialize the comparator
  TIMSK1 = 0x03;    //enable comparator A and overflow interrupts
  TCCR1A = 0x00;    //timer control registers set for
  TCCR1B = 0x00;    //normal operation, timer disabled


  // set up zero crossing interrupt
  attachInterrupt(0,zeroCrossingInterrupt, RISING);  //should be pin 2  
    //IRQ0 is pin 2. Call zeroCrossingInterrupt 
    //on rising signal

}  

//Interrupt Service Routines

void zeroCrossingInterrupt(){ //zero cross detect   
  TCCR1B=0x04; //start timer with divide by 256 input
  TCNT1 = 0;   //reset timer - count from zero
}
/**********************************************************************************/
//I switched the gate commands
ISR(TIMER1_COMPA_vect){ //comparator match
  digitalWrite(GATE,HIGH);  //set triac gate to high - which is actually low
  TCNT1 = 65536-PULSE;      //trigger pulse width
}

ISR(TIMER1_OVF_vect){ //timer1 overflow
  digitalWrite(GATE,LOW); //turn off triac gate
  TCCR1B = 0x00;          //disable timer stopd unintended triggers
}
/**********************************************************************************/
void loop(){ 

buttons = lcd.readButtons();
 if(!(buttons & 0x08)){ 
   lcd.lcdClear();
    lcd.lcdGoToXY(3,1); 
    lcd.lcdWrite("Change Target");
    lcd.lcdGoToXY(7,2); 
    lcd.lcdWrite(setPoint);
    lcd.lcdGoToXY(10,2); 
    lcd.lcdWrite("C");
    listenButtons();
  }

double c = thermocouple.readCelsius();
   if (isnan(c)) {
     Serial.println("Something wrong with thermocouple!");
     i=450;
   } else {
     currentTemperature = c;
     displayCurrent();
     Serial.print("C = "); 
     Serial.print(c);
     

    Input = c;
    myPID.Compute();
    Serial.print(Output);
    i = 450-Output;
     
   }
      
   Serial.print(" i=");
   Serial.println(i);
  
   OCR1A = i;
   delay(400);
   
                           
}


void listenButtons(){
  int setPoint_temp = setPoint;
  int b = 1;
  delay(500);
  while(b){
    buttons = lcd.readButtons();
   if(!(buttons & 0x01)){ 
      setPoint_temp++;
      lcd.lcdGoToXY(7,2); 
      lcd.lcdWrite(setPoint_temp);
    }
    if(!(buttons & 0x02)){ 
      setPoint_temp--;
      lcd.lcdGoToXY(7,2); 
      lcd.lcdWrite(setPoint_temp);
    }
    if(!(buttons & 0x04)){ 
      b=0;
      setPoint= setPoint_temp;
      setDefaultLCD();
    } 
    if(!(buttons & 0x08)){ 
      b=0;
      setDefaultLCD();
    } 
    delay(200);    
  }
}

void displayCurrent(){
  lcd.lcdGoToXY(10,1);
  lcd.lcdWrite(currentTemperature,2);
}

void setDefaultLCD(){
  lcd.lcdClear();
  lcd.lcdGoToXY(2,1); 
  lcd.lcdWrite("Current:");
  lcd.lcdGoToXY(10,1);
  lcd.lcdWrite(currentTemperature,2);
  lcd.lcdGoToXY(15,1);
  lcd.lcdWrite("C");
  lcd.lcdGoToXY(3,2); 
  lcd.lcdWrite("Target:");
  lcd.lcdGoToXY(10,2);
  lcd.lcdWrite(setPoint,2);
  lcd.lcdGoToXY(15,2);
  lcd.lcdWrite("C");
}


