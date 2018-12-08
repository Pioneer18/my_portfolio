#include "Arduino.h"
#include "Mister.h"

Mister::Mister(int pin){
  misterPin = pin;
  pinMode(pin, OUTPUT);
}

void Mister::power(int state)
{
  misterState = state;
  digitalWrite(misterPin, misterState);
}

