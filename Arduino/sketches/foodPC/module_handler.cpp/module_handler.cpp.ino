
/**
 * module_handler.cpp - this library contains the sensorActuator class that will contain the .begin, .set, .get 
 * methods used by the subclasses for each module
 * 
 * updateSerialStream method uses each modules get method to append all the data into a String that is sent to
 * Serial via comms.send class method. 
 * 
 * also contains module_handler.run which calls the update methods for the modules each loop iteration. 
 * 
 */
#include "Arduino.h"
#include "module_handler.h"

//Declare objects
Pump sumpPumpOne(9, 600000, 2100000, 60000, "AWSP", 1);
Pump sumpPumpTwo(12, 600000, 2100000, 60000, "AWSP", 2);
Mister Mister(7, "AWSM", 1);
LEDs LEDs(8, "ALSL", 1);
Fan Fan(6, "AASF", 1);
airPump airPump(11, "AATP", 1);
fishFeeder fishFeeder(37, "AWFF", 1);
tankHeater tankHeater(5, "AWTH", 1);


void initializeModules(){
  //initialize comms here
  sumpPumpOne.begin();
  sumpPumpTwo.begin();
  Mister.begin();
  LEDs.begin();
  Fan.begin();
  airPump.begin();
  fishFeeder.begin();
  tankHeater.begin();
}
void updateSerialStream(){
  String streammessage = "GTYP\":\"Stream\"'";

  //Get the stream message
  streamMessage += sumpPumpOne.get();
  streamMessage += sumpPumpTwo.get(0;
  streamMessage += Mister.get();
  streamMessage += LEDs.get();
  streamMessage += tankHeater.get();
  streamMessage += Fan.get();
  streamMessage += airPump.get();
  streamMessage += fishFeeder.get();
  //use get method on all sensorActuator modules

  //Return stream message
  streamMessage += "\"GEND\":0";

  //comms.send aka Serial.print message
  Serial.print(streamMessage);
}

