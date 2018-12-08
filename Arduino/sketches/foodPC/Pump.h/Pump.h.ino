#include "Arduino.h"

#ifndef Pump_h
#define Pump_h

class Pump
{
  public:
  Pump(int pin, long onTime, long offtime, long pause,String moduleName, int mdoule_id); 
  void Update(); //controls pumps on off cycle and responds to the water sensors - called by module_handler.run();
  void begin(void);//initalizes the module (pump)
  String get(void);//stores the module name, id, and state/data into a message - called by module_handler.updateSerialStream();
  private:
  int pumpPin;
  int waterSensor;
  long pumpOnTime;
  long pumpOffTime;
  long pumpPause;//time for pump to remain off if water sensor is triggered by low water level
  int pumpState;
  unsigned long previousMillis;
  unsigned long previousMillis2;//used to time the pumpPause
  int stage;//determines the cycle stage of the pump - ON stage or OFF stage
  int pauseStatus;//determines if the water sensor has been triggered
  int waterSensorState;
  String value;//takes the place of pumpState in .get method
  void power();//turns pump of or off - called by pump.begin  - called by module_handler.intalizeModules
};

#endif
