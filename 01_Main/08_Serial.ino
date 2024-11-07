// Set up SoftwareSerial on pins 10 and 11
// Nano pin 0(Rx) - Mega Pin 43 (Tx)
// Nano pin 1(Tx) - Mega Pin 41 (Rx)
SoftwareSerial mySerial(41, 43); // RX, TX 

void setupSerial() {
  // Initialize SoftwareSerial at 9600 bps for communication with the Nano
  mySerial.begin(9600);
}

void ledStandbyMode() {
  mySerial.println(1);
}

void ledWashMode() {
  mySerial.println(2);
}

void ledDryMode() {
  mySerial.println(3);
}

void ledCompleteMode() {
  mySerial.println(4);
}

void performSerial(){
  // Send a message to Nano
  mySerial.println(1);
  delay(8000); 

  mySerial.println(2);
  delay(5000); 

  mySerial.println(3);
  delay(5000); 

  mySerial.println(4);
  delay(5000); 
}

