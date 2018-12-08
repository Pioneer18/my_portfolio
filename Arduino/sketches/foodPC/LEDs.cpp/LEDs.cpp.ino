#include "Arduino.h"
#include "LEDs.h"

LEDs::LEDs(int pin, long onTime, long offTime){
  ledPin = pin;
  pinMode(ledPin, OUTPUT);
  ledOnTime = onTime;
  ledOffTime = offTime;
  previousMillis = 0;
  stage = 0;
  ledState = HIGH; // default lights are OFF
}

void LEDs::Update()
{
  unsigned long currentMillis = millis();
    if(stage == 0){
      if(currentMillis - previousMillis <= ledOnTime){// time is not up yet
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        Serial.println("LEDs are ON");
      }
      else{// time is up
        stage = 1;
        previousMillis = currentMillis;
        ledState = HIGH;
        digitalWrite(ledPin, ledState); // turn off the LEDs
      }
    }
}

