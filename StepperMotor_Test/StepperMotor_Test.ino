///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// A4988 Stepper Motor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int sleepPin = 4;
const int enablePin = 5;
const int stepsPerRevolution = 200;

void setup()
{
	// Declare pins as Outputs
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
  pinMode(sleepPin,OUTPUT);


}
void loop()
{
  
  // digitalWrite(sleepPin, HIGH);
	// Set motor direction clockwise
	digitalWrite(dirPin, HIGH);
	// Spin motor slowly
	for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(1000);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(1000);
	}

  digitalWrite(sleepPin, LOW);
	delay(5000); // Wait a second
  digitalWrite(sleepPin, HIGH);
	
	// // Set motor direction counterclockwise
	// digitalWrite(dirPin, LOW);

	// // Spin motor quickly
	// for(int x = 0; x < stepsPerRevolution; x++)
	// {
	// 	digitalWrite(stepPin, HIGH);
	// 	delayMicroseconds(1000);
	// 	digitalWrite(stepPin, LOW);
	// 	delayMicroseconds(1000);
	// }
	// delay(1000); // Wait a second
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// L298N Stepper Motor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// // Include the Arduino Stepper Library
// #include <Stepper.h>

// /////// FUNCTIONS ////////
// // Stepper(steps, pin1, pin2, pin3, pin4) - creates a new instance
// // setSpeed(rpms)-  speed at which the motor should turn in rotations per minute (positive long)
// // step(steps) - the number of steps to turn the motor. Positive integer to turn one direction, negative integer to turn the other.
// ///////////////////////////

// //// PROPERTIES OF NEMA17 /////
// // step angle of 1.8 degrees //
// // rated voltage 12V //////////
// ///////////////////////////////

// #define RAIL_ENA_PIN1 32 // enable pins for rail stepper motor
// #define RAIL_ENA_PIN2 33
// #define RAIL_ENB_PIN1 30
// #define RAIL_ENB_PIN2 31
// #define RAIL_PIN1 4
// #define RAIL_PIN2 6
// #define RAIL_PIN3 5
// #define RAIL_PIN4 7

// #define FAN_ENA_PIN1 36 // enable pins for fan stepper motor
// #define FAN_ENA_PIN2 37
// #define FAN_ENB_PIN1 34
// #define FAN_ENB_PIN2 35
// #define FAN1_PIN1 8
// #define FAN1_PIN2 9 
// #define FAN1_PIN3 10
// #define FAN1_PIN4 11


// const int stepsPerRevolution = 200; 
// const int totalRevolutionsForMovement = 5;
// Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7); // rail stepper
// // Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // fan stepper


// void setup()
// {
//   myStepper.setSpeed(60); // set the speed at 60 rpm
//   Serial.begin(9600); // initialize the serial port
// }

// void loop() 
// {
//   // one revolution clockwise
//   Serial.println("clockwise");
//   digitalWrite(RAIL_ENA_PIN1, HIGH);
//   digitalWrite(RAIL_ENA_PIN2, HIGH);
//   digitalWrite(RAIL_ENB_PIN1, HIGH);
//   digitalWrite(RAIL_ENB_PIN2, HIGH);
//   // digitalWrite(FAN_ENA_PIN1, HIGH);
//   // digitalWrite(FAN_ENA_PIN2, HIGH);
//   // digitalWrite(FAN_ENB_PIN1, HIGH);
//   // digitalWrite(FAN_ENB_PIN2, HIGH);
//   myStepper.step(stepsPerRevolution*totalRevolutionsForMovement); 
  
//   delay(500);

//   // one revolution anticlockwise
//   Serial.println("counterclockwise");
//   myStepper.step(-stepsPerRevolution*totalRevolutionsForMovement);
//   digitalWrite(RAIL_ENA_PIN1, LOW);
//   digitalWrite(RAIL_ENA_PIN2, LOW);
//   digitalWrite(RAIL_ENB_PIN1, LOW);
//   digitalWrite(RAIL_ENB_PIN2, LOW);
//   // digitalWrite(FAN_ENA_PIN1, LOW);
//   // digitalWrite(FAN_ENA_PIN2, LOW);
//   // digitalWrite(FAN_ENB_PIN1, LOW);
//   // digitalWrite(FAN_ENB_PIN2, LOW);
//   delay(10000);
// }
