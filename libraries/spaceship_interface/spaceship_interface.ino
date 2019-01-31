// set up global variables

// variables for the LEDs
const int redLed1=5;
const int redLed2=4;
const int greenLed=3;

//variable for the switch
const int switchPin=2;

void setup() {
  // declare the LED pins as outputs
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed, OUTPUT);

  //declare the switch pin as an input
  pinMode(switchPin, INPUT);
}

void loop() {
  // create a local variable to hold the state of the switch.
  // Unlike the global variables above this is created and 
  // destroyed every time the loop() runs
  int switchState;

  // read the value of the switch
  // digitalRead() checks to see if there is voltage on pin
  switchState=digitalRead(switchPin);

  // if the button is not pressed, blink the red LEDs
  if(switchState == LOW){
      // digitalWrite() is the function that pulls an OUTPUT pin
      // to 5V or 0V

  //turn the green LED off
  digitalWrite(greenLed, LOW);

  //alternately turn the red lights on/off
  digitalWrite(redLed1, HIGH);
  digitalWrite(redLed2, LOW);

  // a delay() stops the program at the current place for the #
  // of milliseconds you decide. 1000ms = 1 sec. 250ms = 1/4 sec
  delay(250);

  digitalWrite(redLed1, LOW);
  digitalWrite(redLed2, HIGH);
  delay(250);
  }


// if the switch is not LOW (button pressed) the code below runs
  else{
    //turn the red LEDs off
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);

    //turn the green LED on
    digitalWrite(greenLed, HIGH);
  }
}
