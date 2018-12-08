


//This code has intentionally has been written to be overly lengthy and includes unnecessary steps. 
//Many parts of this code can be truncated. This code was written to be easy to understand.
//Code efficiency was not considered. Modify this code as you see fit.    
//This code will output data to the Arduino serial monitor. Type commands into the Arduino serial monitor to control the pH circuit.
//set the var Arduino_only to equal 1 to watch the Arduino take over control of the pH circuit.


//As of 11/6/14 the default baud rate has changed to 9600.
//The old defaul baud rate was 38400.


#include <SoftwareSerial.h>      //we have to include the SoftwareSerial library, or else we can't use it.  
//define what pin Tx is going to be.

SoftwareSerial PH_Sensor(2, 3); //define how the soft serial port is going to work. 
SoftwareSerial DO_Sensor(4, 5);



char DO_data[20];                  //we make a 20 byte character array to hold incoming data from the pH. 
char ph_data[20];                  //we make a 20 byte character array to hold incoming data from the pH. 
char computerdata[20];             //we make a 20 byte character array to hold incoming data from a pc/mac/other. 
byte received_from_computer=0;     //we need to know how many characters have been received.                                 
byte received_from_sensor_PH=0;       //we need to know how many characters have been received.
byte received_from_sensor_DO=0; 
byte arduino_only=0;               //if you would like to operate the pH Circuit with the Arduino only and not use the serial monitor to send it commands set this to 1. The data will still come out on the serial monitor, so you can see it working.  
byte startup=0;                    //used to make sure the Arduino takes over control of the pH Circuit properly.
float ph=0;                        //used to hold a floating point number that is the pH. 
byte string_received=0;            //used to identify when we have received a string from the pH circuit.
float sat_float=0;                 //used to hold a floating point number that is the percent saturation.
char *DO;                          //char pointer used in string parsing 
char *sat;


void setup(){
     Serial.begin(9600);          //enable the hardware serial port
     PH_Sensor.begin(9600);        //enable the software serial port
     DO_Sensor.begin(9600);
     
     if(startup==0){                
          PH_Sensor.print("c,0\r");  
          DO_Sensor.print("c,0\r");  
          delay(50);                
          PH_Sensor.print("c,0\r");   
          delay(50);              
          DO_Sensor.print("c,0\r");  
          delay(50);    
          PH_Sensor.print("I,0\r");  
          PH_Sensor.listen();
          delay(50);               
          DO_Sensor.print("I,0\r");   
          DO_Sensor.listen();
          delay(50);    
          startup=1;                 
      }
      
      }
 
 
  

void loop()
{ 
  
  if (Serial.available() > 0)
    {
      received_from_computer=Serial.readBytesUntil(13,computerdata,20); //
      computerdata[received_from_computer]=0; 

      PH_Sensor.listen();
         PH_Sensor.print(computerdata);           
         PH_Sensor.print('\r');     
         received_from_sensor_PH=PH_Sensor.readBytesUntil(13,ph_data,20); 
         ph_data[received_from_sensor_PH]=0;  
         string_received=1;     
          Serial.print("pH: ");//a flag used when the Arduino is controlling the pH Circuit to let us know that a complete string has been received.
         Serial.println(ph_data);          //lets transmit that data received from the pH Circuit to the serial monitor
         
             if(string_received==1)
             { 
               DO_Sensor.print(computerdata);           
                   DO_Sensor.print('\r'); 
                   DO_Sensor.listen();        
                   DO_data[received_from_sensor_DO]=0;     
                   string_received=0;
                   
                   if((DO_data[0] >= 48) && (DO_data[0] <=57))
                   {   //if DO_data[0] is a digit and not a letter
                    pars_data();
                   }
             else
               Serial.println(DO_data);            
               delay(1000);
            }     
     }      
}
 void pars_data()
{
  
  byte i;
  byte pars_flag=0;
  
  for(i=0;i<=received_from_sensor_DO;i++)
      {
        if(DO_data[i]==','){pars_flag=1;}
      }
  

  
  if(pars_flag){ 
  
  DO=strtok(DO_data, ",");           //let's pars the string at each comma.
  sat=strtok(NULL, ",");             //let's pars the string at each comma.
  
 
  Serial.print("DO:");                //We now print each value we parsed sepratly. 
  Serial.println(DO);                 //this is the DO value. 
  //DO_float=atoi(DO);                //Uncomment this line to turn the string into to floating pint value. 
  
  
     
  Serial.print("%sat:");               //We now print each value we parsed sepratly. 
  Serial.println(sat);                 //this is the %sat value. 
  //sat_float=atoi(sat);               //Uncomment this line to turn the string into to floating pint value.
  }

  else                                //if the output is ony DO and not DO + % sat  
  {
   Serial.print("DO :");              //print out "DO:"  
   Serial.println(DO_data);          //printout that DO in Mg/L 
  }


} 

  
