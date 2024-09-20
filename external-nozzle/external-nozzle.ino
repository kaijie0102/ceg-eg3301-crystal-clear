#include <Servo.h>

// Create a Servo object
Servo myServo;

int servoPin = 5;  // Define the pin to which the servo is connected
int angle = 0;     // Variable to store the servo angle
int stepDelay = 200;

void setup() {
  // Attach the Servo object to the defined pin
  myServo.attach(servoPin);
  delay(2000);  // Wait for 2 seconds to allow everything to stabilize

  myServo.write(0);
}

void loop() {
  // myServo.write(angle);
  /*
  // Move the servo from 0 to 45 degrees
  for (angle = 0; angle <= 45; angle++) {
    myServo.write(angle);  // Set the servo position
    delay(stepDelay);             
  }

  // Move the servo from 180 to 0 degrees
  for (angle = 45; angle >= 0; angle--) {
    myServo.write(angle);  // Set the servo position
    delay(stepDelay);             
  }*/
}
