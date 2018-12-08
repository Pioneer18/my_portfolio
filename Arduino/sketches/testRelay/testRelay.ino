
const int pinOut = 8;       //relay pin

void setup() {
  // put your setup code here, to run once:
  pinMode(pinOut, OUTPUT);
  digitalWrite(pinOut, HIGH); //sart with the realy turned off

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinOut, LOW);
  delay(5000); //wait 5 seconds
  digitalWrite(pinOut, HIGH);
  delay(5000);//wait another 5
}
