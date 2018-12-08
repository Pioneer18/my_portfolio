/*
 * Pump.cpp- library for running the pump
 * Created by Jonathan Sells January 6, 2017
 * 
 */
#include "Arduino.h"
#include "Pump.h"

Pump::Pump(int pin, long onTime, long offTime, long pause)
{
  pinMode(pin, OUTPUT);
  pumpPin = pin;
  pumpOnTime = onTime;
  pumpOffTime = offTime;
  pumpPause = pause;
  pumpState = HIGH;// pump is OFF
  previousMillis = 0;
  previousMillis2 = 0;
  stage = 0;
  pauseStatus = 1;
  waterSensorState = LOW;
  waterSensor = 31;
  
}
void Pump::Update()
  {
    //check if the water Sensor is too low and Check the time for switching pump on and off
    unsigned long currentMillis = millis();
    waterSensorState = digitalRead(waterSensor);
    if(pauseStatus == 0){
      if(currentMillis - previousMillis2 < pumpPause){ // time is not up on the pause
      digitalWrite(pumpPin, HIGH); // turn off the pump
      Serial.println("Pump #1 is on a one minute delay");
      }
      else{
        pauseStatus = 1; // time is up, stop the interrupt
      }
    }

    else if(waterSensorState == LOW && pauseStatus == 1){ //if the sensor is floating and the interrupt is offline
      if(stage == 0){// pump of stage
        if(currentMillis - previousMillis <= pumpOnTime){//if time is not up yet
          pumpState = LOW;// turn the pump on
          digitalWrite(pumpPin, pumpState);
          Serial.println("Pump #1 is on");//report status
        }
        else{
          stage = 1;
          previousMillis = currentMillis; //reset the timer
          pumpState = HIGH; // turn the pump off
          digitalWrite(pumpPin, pumpState);
          Serial.println("Pump #1 turned off");
        }
      }
      else if(stage == 1){
        if(currentMillis - previousMillis <= pumpOffTime){
          pumpState = HIGH;
          digitalWrite(pumpPin, pumpState);
          Serial.println("Pump #1 is off");
        }
        else{
          stage = 0;
          pumpState = LOW;// turn the pump on
          digitalWrite(pumpPin, pumpState);
          Serial.println("Pump #1 turned on");
        }
      }
    }
    else if(waterSensorState == 1){
      previousMillis2 = currentMillis;
      pauseStatus = 0;
    }
    
  }

