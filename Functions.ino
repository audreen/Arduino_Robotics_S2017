const int trigPin = 12;
const int echoPin = 11;
// motors below. m2 means motor 2 and m1 means motor 1
const int m1dir1 = 2;
const int m1dir2 = 4;
const int m1Speed = 6;
const int m2dir1 = 8;
const int m2dir2 = 9;
const int m2Speed = 10;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (m1dir1, OUTPUT);
  pinMode (m1dir2, OUTPUT);
  pinMode (m1Speed, OUTPUT);
  pinMode (m2dir1, OUTPUT);
  pinMode (m2dir2, OUTPUT);

  analogWrite (m1Speed, 255);
  analogWrite (m2Speed, 255);
}

void loop() {

  long duration, distance;

  // Drive trigger pin LOW, HIGH, LOW to send the pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // high for 10 microseconds
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // measure the time to the echo
  // Convert to centimeters
  distance = (duration / 2) / 29.1; // calculate the distance in cm
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range; reading invalid");
  } else {
    // anything left should be a valid distance
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= 11) {
      forward();
    }
    else {
      backward();
    }
  }

}
void forward() {
  digitalWrite (m1dir1, HIGH);
  digitalWrite (m1dir2, LOW);
  digitalWrite (m2dir1, HIGH);
  digitalWrite (m2dir2, LOW);
}

void backward() {
  digitalWrite (m1dir1, LOW);
  digitalWrite (m1dir2, LOW);
  digitalWrite (m2dir1, LOW);
  digitalWrite (m2dir2, LOW);
}
