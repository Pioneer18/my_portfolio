#include <DallasTemperature.h>
#include <OneWire.h>
#define ONE_WIRE_BUS 14
#define TEMPERATURE_PRECISION 11

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const int iN3 = 2;
const int iN4 = 4;
const int button = 5;
//variables that change
volatile int buttonState = 0;//use to read the voltage status of the button
int lastButtonState = 0;//used to determine if the button has been pressed
int buttonPushCounter = 0;// used to switch the valve states if even
int overrideKey = 0;//used to override valve response to temperature

long buttonTimer = 0;//timer begins at 0 of course
long longPressTime = 1000;//one econd for a long press

boolean buttonActive = false;
boolean longPressActive = false;//mark that a long press has initiated

void setup() {
  pinMode(iN3, OUTPUT);
  pinMode(iN4, OUTPUT);
  pinMode(button, INPUT);
  attachInterrupt(digitalPinToInterrupt(button), pinISR, CHANGE);//maybe this should be falling?
  digitalWrite(iN3, HIGH);//seth the relay off
  digitalWrite(iN4, HIGH);//set the relay off
  Serial.begin(115200);//serial for esp8266-12 connection
  delay(10);
}

void loop() {
  sensors.requestTemperatures();
  float interruptTemp = sensors.getTempCByIndex(0);
  if(interruptTemp <= 20 && overrideKey % 2 == 0){
    coldInterrupt();
    Serial.println("cold interrupt");
  }
  if(interruptTemp >= 26.6 && overrideKey == 0){
    hotInterrupt();
    Serial.println("hot interrupt");
  }
  float temp = sensors.getTempCByIndex(0);
  Serial.println("reservoir temp: ");
  Serial.print(temp);
  //respond to the button
  if(buttonState != lastButtonState){
    if(buttonPushCounter % 2 == 0){
      Serial.println("bpc is even ");
      Serial.print(buttonPushCounter);
      //open the ball valves
      digitalWrite(iN3, LOW); 
      digitalWrite(iN4, HIGH);
    }else{
      //close the ball valves
      Serial.println("bpc is odd ");
      Serial.print(buttonPushCounter);
      digitalWrite(iN3, HIGH);
      digitalWrite(iN4, LOW);
    }
  }
  
}
/********************************************************************************************/
//interrupts
void coldInterrupt(){
  digitalWrite(iN3, HIGH);//close the ball valves
  digitalWrite(iN4, LOW);
}

void hotInterrupt(){
  digitalWrite(iN3, LOW);//open the ball valves
  digitalWrite(iN4, HIGH);
}

void pinISR(){
  /*if(digitalRead(button) == HIGH){//the button is pressed and going to ground
    if(buttonActive == false);{//1st time the button is being pressed this cycle
      buttonActive = true;//mark that the button is being held down
      buttonTimer = millis();//start the button held down timer
      //on the next loop we will see if the button has been held long enough for a long press
    }
    //button is still pressed and buton active is true
    //time compare pressed time to longPresTime
    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)){ 
      //make sure that longPressActive is not true or the button will keeping getting pressed
      longPressActive = true;
      overrideKey++;
      Serial.println("overrideKey: ");
      Serial.print(overrideKey);
      //probably exits interrupt here
    }
  }
  //change the override status to an even # to activate override
  //change the override status to an odd 3 to deactivate the override
  //dont change the status of the valves, just change override status
  //button has not been released and long press is active
  //keep looping till button is released
  else{//the button has been released
    if(buttonActive == true){//this is now false
      if(longPressActive = true){//it was a long press
        longPressActive = false;//turn off the long press now that button is released
      }
    }
    else{//it was a quick click
      buttonPushCounter++;//change the state of valves 
    }
  buttonActive = false;//the button has been released*/
  buttonState = digitalRead(button);
  delay(250);
  if(buttonState != lastButtonState){
    //if the state has changed
    if(buttonState == LOW){
      //if the button state is LOW then the button 
      //went from off to on
      buttonPushCounter++;
      Serial.println("on");
      Serial.print(" number of button pushes: ");
      Serial. println(buttonPushCounter);
    }
    else{
      //if the current state is HIGH the the button
      //went from on to off
      Serial.println("off");
    }
    //delay a little bit to avoid bouncing
    delay(50);
  }
  //save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;

  }


