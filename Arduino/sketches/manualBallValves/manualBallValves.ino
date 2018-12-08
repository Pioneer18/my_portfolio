//relay pins
const int iN3 = 2;//open
const int iN4 = 4;//close
const int button = 5;//button to open/close the ball valves
//variables that change
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(iN3, OUTPUT);
  pinMode(iN4, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(iN3, HIGH);
  digitalWrite(iN4, HIGH);
  Serial.begin(9600);//serial to monitor button states
}

void loop() {
  //read the push button input
  buttonState = digitalRead(button);

  //compare the buttonState to the lastButtonState
  if(buttonState != lastButtonState){
    //if the state has changed
    if(buttonState == LOW){
      //if the button state is LOW then the button 
      //went from off to on
      buttonPushCounter++;
      Serial.println("on");
      Serial.print(" number of button pushes: ");
      Serial. println(buttonPushCounter);
    }
    else{
      //if the current state is HIGH the the button
      //went from on to off
      Serial.println("off");
    }
    //delay a little bit to avoid bouncing
    delay(50);
  }
  //save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;



  //open and close the ball valves
  //checking the modulo (remainder of a number
  //will check if the number is even or odd)
  //this way we know if the button has been clicked
  if(buttonPushCounter % 2 == 0){
    //open the ball valves
    digitalWrite(iN3, LOW); 
    digitalWrite(iN4, HIGH);
  }else{
    //close the ball valves
    digitalWrite(iN3, HIGH);
    digitalWrite(iN4, LOW);
  }
}
