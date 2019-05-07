int switchState = 0;
const int blueLEDPin = 3;
const int greenLEDPin = 4;
const int yellowLEDPin = 5;
const int redLEDPin = 6;

void setup() {
  Serial.begin(9600);

  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
 switchState = digitalRead(2); 

if(switchState == LOW){   //button not pressed
  digitalWrite(blueLEDPin, LOW);
  digitalWrite(greenLEDPin, LOW);
  digitalWrite(yellowLEDPin, LOW);
  digitalWrite(redLEDPin, LOW);
} else {
  digitalWrite(blueLEDPin, HIGH);
  delay(500);
  digitalWrite(greenLEDPin, HIGH);
  delay(500);
  digitalWrite(yellowLEDPin, HIGH);
  delay(500);
  digitalWrite(redLEDPin, HIGH);
  delay(500\');
}
}
