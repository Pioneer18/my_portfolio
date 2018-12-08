#include "Arduino.h"
#include "Fan.h"

Fan::Fan(int pin){
  fanPin = pin;
  pinMode(pin, OUTPUT);
}

void Fan::power(int state)
{
  fanState = state;
  digitalWrite(fanPin, fanState);
}

