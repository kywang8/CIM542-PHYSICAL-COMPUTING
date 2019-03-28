int switchState = 0;

const int blueLEDPin = 3;
const int greenLEDPin = 4;
const int yellowLEDPin = 5;
const int redLEDPin = 6;

long randNumber;
boolean wasPressed = false;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);


  if (switchState == HIGH) {
    wasPressed = true;
  }

  if (switchState == LOW && wasPressed == true) {
    Serial.println("In here");
    wasPressed = false;
    randNumber = random(0, 4);
    Serial.println(randNumber);
  }

  if (randNumber == 0) {
    digitalWrite(blueLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
  }

  if (randNumber == 1) {
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
  }

  if (randNumber == 2) {
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
  }
  if (randNumber == 3) {
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
  }
}
