//constant variables
const int pumpPin1 = 8;
const int pumpPin2 = 4;
const int buttonPin1 = 7;
const int buttonPin2 = 8;
int ps1 = HIGH; //current state of the output pin OFF
int ps2 = HIGH; //current state of the output pin OFF
int bs1; //current reading from input pin
int bs2; //current reading from input pin
boolean lbs1 = LOW;
boolean lbs2 = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin1, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  // set inital pump state
  digitalWrite(pumpPin1, ps1); //off
  digitalWrite(pumpPin2, ps2); //off
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
  if(reading1 != lbs1){
    lastDebounceTime = millis();
  }
  if((millis() - lastDebounceTime) > debounceDelay){
    if(reading1 != bs1){
      bs1 = reading1;
      if(bs1 == HIGH){
        ps1 = !ps1;
      }
    }
  }
  digitalWrite(pumpPin1, ps1);
  lbs1 = reading1;
}
