/*
 * tankHeater.cpp - Library for running the tank heater
 * need to add code to make it temp responsive
 */
#include "Arduino.h"
#include "tankHeater.h"

tankHeater::tankHeater(int pin){
  heaterPin = pin;
  pinMode(pin, OUTPUT);
}

void tankHeater::power(int state)
{
  heaterState = state;
  digitalWrite(heaterPin, heaterState);
}

