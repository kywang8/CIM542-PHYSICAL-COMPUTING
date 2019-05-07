void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11, HIGH);
  delay(1000);          //1000 milliseconds = 1 second
  digitalWrite(11, LOW);
  delay(1000);
//  digitalWrite(13, HIGH);
//  delay(250);          //1000 milliseconds = 1 second
//  digitalWrite(13, LOW);
//  delay(250);
} 
