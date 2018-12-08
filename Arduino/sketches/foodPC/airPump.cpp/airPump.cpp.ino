#include "Arduino.h"
#include "airPump.h"

airPump::airPump(int pin){
  airPumpPin = pin;
  pinMode(pin, OUTPUT);
}

void airPump::power(int state)
{
  airPumpState = state;
  digitalWrite(airPumpPin, airPumpState);
}

