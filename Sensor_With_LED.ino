const int trigPin = 12;
const int echoPin = 11;
int led = 13;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

long duration, distance;

// Drive trigger pin LOW, HIGH, LOW to send the pulse
digitalWrite(trigPin, LOW);
delayMicroseconds(2); // low for 2 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); // high for 10 microseconds
digitalWrite(trigPin, LOW);

// the pulseIn command waits for a given pin to go HIGH, and then
// reports how long it waited until that happened
duration = pulseIn(echoPin, HIGH); // measure the time to the echo

// Convert to centimeters
distance = (duration / 2) / 29.1; // calculate the distance in cm

// Discard readings that are too large or too small to be reasonable
// It's pretty common for some sensors to give occasional bad readings
// and a good program must take that into account
if (distance >= 200 || distance <= 0) {
  Serial.println("Out of range; reading invalid");
} else {
  // anything left should be a valid distance
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance <= 11) {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else {
    digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
  }
}

delay(500);   // wait before doing it again

}
