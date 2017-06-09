void setup(){
  Serial.begin(9600);
}

void loop() {
  int i = 6;
  int j = 10;
  int l = 18;
  int k;

  k = myMultiplyFunction(i, j, l); // k now contains 6
  Serial.println(k);
  delay(500);
}

int myMultiplyFunction(int x, int y, int z){
  int result;
  result = (x + y + z) / 3;
  return result;
}
