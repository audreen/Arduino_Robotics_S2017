//labeling the motors
int motor1_1 = 2;
int motor1_2 = 4;
int motor2_1 = 8;
int motor2_2 = 9;
int motor1_Speed = 6;
int motor2_Speed = 10;
const int trigPin = 12;
const int echoPin = 11;

void setup() {
  // initialize pinModes for motors
  pinMode (motor1_1, OUTPUT);
  pinMode (motor1_2, OUTPUT);
  pinMode (motor1_Speed, OUTPUT);
  pinMode (motor2_1, OUTPUT);
  pinMode (motor2_2, OUTPUT);
  pinMode (motor2_Speed, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //these are my analogWrites
  analogWrite (motor1_Speed, 255);
  analogWrite (motor2_Speed, 255);

  //this is my Serial Begin
  Serial.begin(9600);

  //  digitalWrite(motor2_1, LOW);
  //  digitalWrite(motor2_2, HIGH);

}

//void loop () {}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  //NEW/DISTANCE SENCOR CODE START
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  //measures distance
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.print(" cm ");
  //This will go to the left if the distance is greater than or equal to 10 and if sensorValue is greater than sensorValue2, if not it will go right 
  if (distance >= 10) {
    int sensorValue = analogRead(A1);
    int sensorValue2 = analogRead (A0);
    Serial.print("sV: ");
    Serial.print(sensorValue);
    Serial.print(" sV2: ");
    Serial.print(sensorValue2);
    if (sensorValue < sensorValue2) {
      Serial.print(" forward ");
      left();
    } else { // sensrovalue2 must be greater thant s
      right();
    } // end of sensor value comparing
  } // end of distance > 10
  else if (distance > 0) {
    Serial.print(" backward ");
    dontgo();
    delay(500);
    backward();
    delay(2000);
    right();
    delay(2000);  
  }

Serial.println();

}

void left() {
  digitalWrite (motor1_1, HIGH);
  digitalWrite (motor1_2, LOW);
  digitalWrite (motor2_1, HIGH);
  digitalWrite (motor2_2, LOW);
}
void right() {
  digitalWrite (motor1_1, LOW);
  digitalWrite (motor1_2, HIGH);
  digitalWrite (motor2_1, LOW);
  digitalWrite (motor2_2, HIGH);
}

void forward() {
  digitalWrite (motor1_1, LOW);
  digitalWrite (motor1_2, HIGH);
  digitalWrite (motor2_1, HIGH);
  digitalWrite (motor2_2, LOW);
}
void dontgo() {
  digitalWrite (motor1_1, LOW);
  digitalWrite (motor1_2, LOW);
  digitalWrite (motor2_1, LOW);
  digitalWrite (motor2_2, LOW);
}

void backward() {
  digitalWrite (motor1_1, HIGH);
  digitalWrite (motor1_2, LOW);
  digitalWrite (motor2_1, LOW);
  digitalWrite (motor2_2, HIGH);
}
