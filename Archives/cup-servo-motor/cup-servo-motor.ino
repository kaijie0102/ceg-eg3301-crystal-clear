// #include <Servo.h>

// Servo myservo;  // create servo object to control a servo


// void setup() {
//   myservo.attach(3);  // attaches the servo on pin 9 to the servo object
// }

// void loop() {

//   // 0: full speed clockwise8
//   // 90: stop
//   // 180: full speed counter clockwise
 
//   myservo.write(60);                  // sets the servo position according to the scaled value
//   // delay(1000);                           // waits for the servo to get there
//   // myservo.write(180);
// }

#include <Servo.h>

Servo myServo; // Create a Servo object to control the servo

void setup() {
  myServo.attach(4); // Attach the servo to pin 9 on the Arduino
}

void loop() {
  Serial.println("Spinnning");
  myServo.write(60);  // Set servo to the neutral position (stops if it's a continuous servo)
  // delay(2000);        // Wait for 2 seconds

  // myServo.write(180); // Rotate the servo clockwise
  // delay(2000);        // Wait for 2 seconds

  // myServo.write(0);   // Rotate the servo counterclockwise
  // delay(2000);        // Wait for 2 seconds
}
