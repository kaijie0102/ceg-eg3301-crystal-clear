#include <Servo.h>

Servo myservo;  // create servo object to control a servo


void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  // 0: full speed clockwise8
  // 90: stop
  // 180: full speed counter clockwise
 
  myservo.write(60);                  // sets the servo position according to the scaled value
  // delay(1000);                           // waits for the servo to get there
  // myservo.write(180);
}