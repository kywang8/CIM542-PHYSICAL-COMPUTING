#include <Servo.h>

int ledpin1 = 3;
int counter = 0;

long prevMillis = 0;
int interval = 10;

boolean flipFlop = false;

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  // pinMode(ledpin1, OUTPUT);
myservo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
//  analogWrite(ledpin1, counter);
myservo.write(counter);

  //every ten milliseconds, do this
  if(millis() - prevMillis > interval){
    prevMillis = millis();

    if(flipFlop == false){
      counter = counter + 1;
    }else{
      counter = counter - 1;
    }
  }
  
  if(counter >= 180){
    //counter = 0; 
    flipFlop = true;
}

  if(counter <= 0){
    flipFlop = false;
  }
 }
