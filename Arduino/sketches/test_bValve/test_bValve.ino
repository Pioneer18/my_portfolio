const int iN3 = 2; //& iN1
const int iN4 = 4; //& iN2
const int button = 5;
const int cycleRate = 10000;//10 second on off time
unsigned long timer; 

void setup() {
  // put your setup code here, to run once:
  pinMode(iN3, OUTPUT);
  pinMode(iN4, OUTPUT);
  // pinMode(iN2, OUTPUT);
  // pinMode(iN1, OUTPUT);
  //NOTE THAT HIGH = OFF AND LOW = ON
  digitalWrite(iN4,HIGH);//OFF
  digitalWrite(iN3, HIGH);//OFF
  //digitalWrite(iN2, HIGH);
  //digitalWrite(iN1, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  digitalWrite(iN3, LOW);//open
  delay(7000);
  digitalWrite(iN3, HIGH);
  delay(7000);
  digitalWrite(iN4, LOW);//close
  delay(7000);
  digitalWrite(iN4, HIGH);

 /* digitalWrite(iN2, LOW);
  delay(10000);
  digitalWrite(iN2, HIGH);
  delay(5000);
  digitalWrite(iN1, LOW);
  delay(10000);
  digitalWrite(iN1, HIGH);
  delay(10000);*/
  


}
