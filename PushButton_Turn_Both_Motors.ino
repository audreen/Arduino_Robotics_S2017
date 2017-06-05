// digital pin 7 has a pushbutton attached to it. Give it a name:
const int pushButton = 7;

int m2Speed = 10;
int m2dir1 = 8;
int m2dir2 = 9;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (m2dir1, OUTPUT);
  pinMode (m2Speed, OUTPUT);
  pinMode (m2dir2, OUTPUT);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);

  analogWrite (6, 255);
  analogWrite (m2Speed, 255);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

// the loop function runs over and over again forever
void loop() {

  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability

  if (buttonState == HIGH) {
    digitalWrite (2, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite (4, LOW);
    delay(500);                       // wait for a second

    digitalWrite (m2dir1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite (m2dir2, LOW);
    delay(500);  

    //  digitalWrite (2, LOW);   // turn the LED on (HIGH is the voltage level)
    //  digitalWrite (2, HIGH);
    //  delay(500);
    // Add this if I want it to turn both ways
    //  digitalWrite (2, LOW);   // turn the LED on (HIGH is the voltage level)
    //  digitalWrite (4, HIGH);
    //  delay(500);                       // wait for a second
    //
    //  digitalWrite (2, LOW);   // turn the LED on (HIGH is the voltage level)
    //  digitalWrite (4, LOW);
    //  delay(500);
  }
  else {
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    delay(500);

    digitalWrite (m2dir1, LOW);
    digitalWrite (m2dir2, LOW);
    delay(500);
  }

}
