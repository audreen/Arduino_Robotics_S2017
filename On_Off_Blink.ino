int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

// turn the ledPin on
if (sensorValue >= 400) {
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorvalue> milliseconds;
}
else if (sensorValue <= 130) {
  // turn the ledPin off;
  digialWrite(ledPin, LOW);
  // stop the program for <sensorValue> milliseconds;
}
else {
  // blinking pattern
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds;
  digitalWrite(ledPin, LOW);
  // stop the program for <sensorValue> milliseconds;
   }
}
