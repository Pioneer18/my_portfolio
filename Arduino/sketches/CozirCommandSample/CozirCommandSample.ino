
#include <SoftwareSerial.h>
SoftwareSerial mySerial(15,14);// RX, TX
String firmware = ""; //holds the string of the firmware version returned
void setup() {
  Serial.begin(9600);
  Serial.println("Jsells sensor version testing");
  mySerial.begin(9600); // start the serial connection with the sensor
  Serial.write("Y\r\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    firmware = Serial.read();
    Serial.println(firmware);
  }

}
