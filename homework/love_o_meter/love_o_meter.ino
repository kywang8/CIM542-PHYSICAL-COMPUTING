//variable for the temperature sensor
const int sensorPin = A0;
const float baselineTemp = -17.0;

void setup() {
  // open a serial port to display values
  Serial.begin(9600);
  //set the LED pins as outputs
  for(int x=2; x<5; x++){
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }
}

void loop() {
  // read the value on the Analog In pin and store it in variable
  int sensorVal=analogRead(sensorPin);
  //send the 10-bit sensor value out the serial port
  Serial.print(sensorVal);
  Serial.print(" ADC, ");
  //convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  //send the voltage level out the Serial port
  Serial.print(voltage);
  Serial.print(" Volts, ");
  //convert the voltage to temp in C degrees
  //the sensor reports 10 mv per degree w/ 500 mV offset to degrees ((voltage - 500mV) times 100)
  float temperature = (voltage - .5) *100;
  Serial.print(temperature);
  Serial.println(" degrees C ");
  //using the baseline temp as a starting point, increment the # of LEDs that are on for every 2 degrees of increase
  //if the current temp is lower than the baseline turn off all LEDs
  if(temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+4  && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
delay(1);
}
