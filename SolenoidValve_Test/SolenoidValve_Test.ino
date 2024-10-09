// Code to Open and close an NC valve in 5 seconds gap.
int valvepin = 2;

void setup() {
  pinMode(valvepin, OUTPUT);
}

void loop() {
  //Opens the valve for 5 seconds
  digitalWrite(valvepin, HIGH);
  delay(5000);
  //Close the valve for 5 seconds
  digitalWrite(valvepin, LOW);
  delay(5000);
}
