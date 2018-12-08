/*
 * LEDs.h - library for running the LEDs
 * Created by Jonathan Sells, January 7th, 2017
 */

#include "Arduino.h"
#ifndef LEDs_h
#define LEDs_h

class LEDs
{
  public:
  LEDs(int pin,long onTime, long offTime);
  void Update();
  private:
  int ledPin;
  int stage;
  int ledState;
  int ledOnTime;
  int ledOffTime;
  unsigned long previousMillis;
  
};
#endif

