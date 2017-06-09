#include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(13);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A1);
  int sensorValue2 = analogRead(A0);
  if ( sensorValue > sensorValue2 ) {
    myservo.write(0);
  }
  else {
    if ( sensorValue == sensorValue2 ) {
      myservo.write(90);
    }
    else {

      myservo.write(180);
    }
  }

}
