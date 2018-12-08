// Serial Output
// Written by: Thomas Tongue
// Date: July 20th, 2015

const int buttonPin = 0;     // the number of the pushbutton pin
int buttonState=0;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // Write it out to the LED
  Serial.println("Button Value: "+String(buttonState,DEC));
  delay(1000);
}
