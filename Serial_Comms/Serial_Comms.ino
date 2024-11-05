#include <SoftwareSerial.h>

// Set up SoftwareSerial on pins 10 and 11
SoftwareSerial mySerial(41, 43); // RX, TX

void setup() {
  // Initialize Serial Monitor at 9600 bps
  Serial.begin(9600);
  
  // Initialize SoftwareSerial at 9600 bps for communication with the Nano
  mySerial.begin(9600);
}

void loop() {
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
