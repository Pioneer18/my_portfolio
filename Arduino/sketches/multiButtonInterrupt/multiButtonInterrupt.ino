//the loop will be doing only printing to serial
//an interrupt will respond to a quick click by switching the state of the ball valves to open or closed
//the interrupt will change the override status for a long press
//serail monitor will display override status, button counter, valve status

//constants
const int iN3 = 2;
const int iN4 = 4;
const int button = 5;
//dynamic variables
int buttonPushCounter = 0;
volatile int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(iN3, OUTPUT);
  pinMode(iN4, OUTPUT);
  pinMode(button, OUTPUT);
  digitalWrite(iN3, HIGH);
  digitalWrite(iN4, HIGH);
  Serial.begin(115200);//esp8266 baud rate
  attachInterrupt(digitalPinToInterrupt(button), pinISR, CHANGE);
  Serial.println("setup complete");
}

void loop() {
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

void pinISR(){
  buttonState = digitalRead(button);
  if(buttonState != lastButtonState){
    //the button has been pressed
    if(buttonState == LOW){//button is being pressed
      buttonPushCounter++;
      Serial.println("button clicks: ");
      Serial.print(buttonPushCounter);
    }
    else{
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;
}

