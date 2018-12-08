/*
 * module_hanlder.h - this library contains the sensorActuator class that will contain the .begin, .set, .get
 * methods used by the subclasses for each module
 */
#include "Arduino.h"

#ifndef module_handler.h
#define module_handler.h

class sensorActuator {
  public:
  //public functions used by all the sub-classes
  /**
   * \brief Called once at beginning of program to initalize modules.
   */
  virtual void begin(void) = 0;

  /**
   * \brief Called once per loop iteration to get data from sensors and actuators to be displayed
   * via serial, lcd, and thingSpeak
   */
  virtual String get(void) = 0;
};
/**
 * \brief Called once to initalize all the modules
 */

void intializeModules();

/**
 * \brief Called once per loop iteration to send all sensor and actuator data to the serial monitor
 */
void updateSerialStream();//should be about the same as the updateStreamMessage method that the pfc used

/**
 * \brief Called once per loop iteration to run the module.update() methods for a given amount of time (#of days)
 */
void runModules();

/**
 * \brief Constantly checking serial monitor for user commands that will overide the default schedule as specified
 */
void updateIncomingCommands();

#endif


