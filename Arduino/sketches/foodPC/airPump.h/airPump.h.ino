/*
 * airPump.h - library for running the mister
 * Created by Jonathan Sells, January 7th, 2017
 */

#include "Arduino.h"
#ifndef airPump_h
#define airPump_h

class airPump
{
  public:
  airPump(int pin);
  void power(int state);
  private:
  int airPumpPin;
  int airPumpState;
  
};
#endif
