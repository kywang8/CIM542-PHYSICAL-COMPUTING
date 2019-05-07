#include <LiquidCrystal.h>


int switchState = 0;
int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;
int switchState4 = 0;

const int mainLEDPin = 30;
const int blueLEDPin = 28;
const int greenLEDPin = 26;
const int yellowLEDPin = 24;
const int redLEDPin = 22;

const int switchPinMain = 2;
const int switchPin1 = 3;
const int switchPin2 = 5;
const int switchPin3 = 4;
const int switchPin4 = 6;

long randNumber;
boolean wasPressed = false;
boolean wasPressed1 = false;
boolean wasPressed2 = false;
boolean wasPressed3 = false;
boolean wasPressed4 = false;

long time1 = 0;
long time2 = 0;

const int rs = 12, en = 13, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

boolean startTimer = false;


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  lcd.begin(16, 2);


  pinMode(switchPinMain, INPUT_PULLUP);
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(switchPin3, INPUT_PULLUP);
  pinMode(switchPin4, INPUT_PULLUP);

  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(mainLEDPin, OUTPUT);
}

void loop() {
  if (startTimer == false) {
    digitalWrite(mainLEDPin, HIGH); 
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);

    lcd.setCursor(0, 0);
    lcd.print("Press the white ");
    lcd.setCursor(0, 1);
    lcd.print("button to start");

    switchState = digitalRead(2);

    //main
    if (switchState == HIGH) {
      wasPressed = true;
    }

    if (switchState == LOW && wasPressed == true) {
      Serial.println("In here");
      wasPressed = false;
      randNumber = random(0, 4);
      Serial.println(randNumber);
      time1 = millis();
      startTimer = true;
      lcd.clear();
      digitalWrite(mainLEDPin, LOW);


    }
  } else{
      Serial.println(randNumber);


    lcd.setCursor(0, 0);
    lcd.print("Press the ");
    lcd.setCursor(0, 1);
    lcd.print("button");

    //0

    switchState1 = digitalRead(switchPin1);

    if (switchState1 == HIGH) {
      wasPressed1 = true;
    }

    if (switchState1 == LOW && wasPressed1 == true) {
      Serial.println("Button 1");
      wasPressed1 = false;

      time2 = millis() - time1;

      if (randNumber == 0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correct! Time:");
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print(time2);
        delay(3000);
        startTimer = false;
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Incorrect! Time: ");
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print(time2);
        delay(3000);
        startTimer = false;

      }
    }

    //1

    switchState2 = digitalRead(switchPin2);

    if (switchState2 == HIGH) {
      wasPressed2 = true;
    }

    if (switchState2 == LOW && wasPressed2 == true) {
      Serial.println("Button 2");
      wasPressed1 = false;

      time2 = millis() - time1;
      Serial.println(time2);

      if (randNumber == 1) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correct! Time: ");
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print(time2);
        delay(3000);
        startTimer = false;
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Incorrect! Time: ");
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print(time2);
        delay(3000);
        startTimer = false;
      }

    }

    //2

    switchState3 = digitalRead(switchPin3);

    if (switchState3 == HIGH) {
      wasPressed3 = true;
    }

    if (switchState3 == LOW && wasPressed3 == true) {
      Serial.println("Button 3");
      wasPressed3 = false;

      time2 = millis() - time1;
      Serial.println(time2);

      if (randNumber == 2) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correct! Time: ");
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print(time2);
        delay(3000);
        startTimer = false;
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Incorrect! Time: ");
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print(time2);
        delay(3000);
        startTimer = false;
      }

    }

    //3

    switchState4 = digitalRead(switchPin4);

    if (switchState4 == HIGH) {
      wasPressed4 = true;
    }

    if (switchState4 == LOW && wasPressed4 == true) {
      Serial.println("Button 4");
      wasPressed4 = false;

      time2 = millis() - time1;
      Serial.println(time2);

      if (randNumber == 3) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correct! Time: ");
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print(time2);
        delay(3000);
        startTimer = false;
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Incorrect! Time: ");
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print(time2);
        delay(3000);
        startTimer = false;
      }
    }

    if (randNumber == 0) {
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(yellowLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
    }

    if (randNumber == 1) {
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(yellowLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
    }

    if (randNumber == 2) {
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(greenLEDPin, HIGH);
      digitalWrite(yellowLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
    }

    if (randNumber == 3) {
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(yellowLEDPin, LOW);
      digitalWrite(redLEDPin, HIGH);
    }


  }




}
