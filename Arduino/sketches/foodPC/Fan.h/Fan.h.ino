/*
 * Fan.h - library for running the mister
 * Created by Jonathan Sells, January 7th, 2017
 */

#include "Arduino.h"
#ifndef Fan_h
#define Fan_h

class Fan
{
  public:
  Fan(int pin);
  void power(int state);
  private:
  int fanPin;
  int fanState;
  
};
#endif

