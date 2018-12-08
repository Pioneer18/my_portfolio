// ThingSpeak Updater
// Written by: Thomas Tongue
// Date: July 21st, 2015

#include <ESP8266WiFi.h>
#include <Wire.h>//to control I2C
#include <OneWire.h>//ds18b20
#include <DallasTemperature.h>//ds18b20 
/********************************************************************/
#define ONE_WIRE_BUS 5//Temp sensor bus is on pin 5
OneWire oneWire(ONE_WIRE_BUS);//setup a oneWire reference instance to communicate with any OneWire devices
DallasTemperature sensors (&oneWire);//pass the oneWire reference to Dallas Temperature
/********************************************************************/

const char* ssid     = "FiOS-4ZNFQ";
const char* password = "gin823angry7512fad";
String writeAPIKey   = "3PHTNPOK0GVT1I5A";

const char* thingSpeakAddress = "api.thingspeak.com";
const int updateThingSpeakInterval = 16*1000;

long lastConnectionTime = 0;
boolean lastConnected = false;
int failedCounter=0;

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network
  Serial.print("\n\nConnecting to ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected. IP address: "+WiFi.localIP());
  pinMode(ONE_WIRE_BUS, INPUT);
}



void loop() {
  delay(5000);
  
  String analogValue0 = String(sensors.getTempCByIndex(0), DEC);
  if ((WiFi.status() == WL_CONNECTED) && 
      (millis() - lastConnectionTime > updateThingSpeakInterval))
  {
    updateThingSpeak("field1="+analogValue0);
    Serial.println(analogValue0);
  }
}


void updateThingSpeak(String tsData)
{
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(thingSpeakAddress, httpPort)) {
    failedCounter++;
    Serial.println("Connection to ThingSpeak Failed ("+String(failedCounter, DEC)+")");   
    Serial.println();
    
    lastConnectionTime = millis(); 
    return;
  }
  client.print("POST /update HTTP/1.1\n");
  client.print("Host: api.thingspeak.com\n");
  client.print("Connection: close\n");
  client.print("X-THINGSPEAKAPIKEY: "+writeAPIKey+"\n");
  client.print("Content-Type: application/x-www-form-urlencoded\n");
  client.print("Content-Length: ");
  client.print(tsData.length());
  client.print("\n\n");

  client.print(tsData);
    
  lastConnectionTime = millis();
    
  if (client.connected())
  {
      delay(10);
      Serial.println("Connecting to ThingSpeak...");
      Serial.println();
      
      failedCounter = 0;
      while(client.available()){
        String line = client.readStringUntil('\r');
        Serial.print(line);
      }
  
      Serial.println();
      Serial.println("closing connection");
  }
  else
  {
      failedCounter++;
  
      Serial.println("Connection to ThingSpeak failed ("+String(failedCounter, DEC)+")");   
      Serial.println();
  }
}
