/*
 * Mister.h - library for running the mister
 * Created by Jonathan Sells, January 7th, 2017
 */

#include "Arduino.h"
#ifndef Mister_h
#define Mister_h

class Mister
{
  public:
  Mister(int pin);
  void power(int state);
  private:
  int misterPin;
  int misterState;
  
};
#endif

