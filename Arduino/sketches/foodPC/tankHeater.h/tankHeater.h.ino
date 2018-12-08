/*
 * tankHeater.h - library for running the mister
 * Created by Jonathan Sells, January 7th, 2017
 */

#include "Arduino.h"
#ifndef tankHeater_h
#define tankHeater_h

class tankHeater
{
  public:
  tankHeater(int pin);
  void power(int state);
  private:
  int heaterPin;
  int heaterState;
  
};
#endif
