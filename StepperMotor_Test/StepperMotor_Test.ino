// Include the Arduino Stepper Library
#include <Stepper.h>

/////// FUNCTIONS ////////
// Stepper(steps, pin1, pin2, pin3, pin4) - creates a new instance
// setSpeed(rpms)-  speed at which the motor should turn in rotations per minute (positive long)
// step(steps) - the number of steps to turn the motor. Positive integer to turn one direction, negative integer to turn the other.
///////////////////////////

//// PROPERTIES OF NEMA17 /////
// step angle of 1.8 degrees //
// rated voltage 12V //////////
///////////////////////////////


const int stepsPerRevolution = 200; 
Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7); // rail stepper


void setup()
{
  myStepper.setSpeed(60); // set the speed at 60 rpm
  Serial.begin(9600); // initialize the serial port
}

void loop() 
{
  // one revolution clockwise
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution); 
  delay(500);

  // one revolution anticlockwise
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
