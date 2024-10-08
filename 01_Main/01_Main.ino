// Import libraries
#include <Stepper.h>
#include <Servo.h>

// Define Arduino Pins
#define BUTTONPIN 2    // Pin where the push button is connected
#define CUPSERVOPIN 3 // continuous servo motor
#define FANRELAYPIN 22 // relay for fan

#define RAIL_ENA_PIN1 32 // enable pins for rail stepper motor
#define RAIL_ENA_PIN2 33
#define RAIL_ENB_PIN1 30
#define RAIL_ENB_PIN2 31

#define FAN_ENA_PIN1 36 // enable pins for fan stepper motor
#define FAN_ENA_PIN2 37
#define FAN_ENB_PIN1 34
#define FAN_ENB_PIN2 35

// Define 15 states for the finite state machine
enum State {
  STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, STATE_6, STATE_7, STATE_8,
  STATE_9, STATE_10, STATE_11, STATE_12, STATE_13, STATE_14, STATE_15
};  
State currentState = STATE_1;
void executeState1();
void executeState2();
void executeState3();
void executeState4();

// 02_PowerControl
void setupRelay();

// 03_StepperMotorControl
void setupRailStepperMotor();
void setupFanStepperMotor();
void moveRailStepperMotorBackwards();
void moveRailStepperMotorForward();
void moveFanStepperMotorUp();
void moveFanStepperMotorDown();

// 03_ServoMotorControl
void setupServoMotor();
void cupServoStart();
void cupServoStop();
Servo cupServo;  // create continuous servo object
unsigned long timer; 
static const unsigned long timeout = 7500; // loop ends after specified duration
int servoCounter = 0;  

// 05_Ui
void setupUi();
void readButtonInput();

// 06_Fan

void setup() {

  setupRelay();
  setupRailStepperMotor();
  setupFanStepperMotor();
  setupServoMotor();
  setupUi(); 
  
  // Initialize the serial port:
  Serial.begin(9600);

  Serial.println();
  Serial.println("===============");
  Serial.println("Set up complete");

}

void loop() {
  // Handle the current state
  handleState();
}


// Function to handle the logic for each state
void handleState() {
  switch (currentState) {
    case STATE_1:
      executeState1();
      break;
    case STATE_2:
      executeState2();
      break;
    case STATE_3:
      executeState3();
      break;
    case STATE_4:
      executeState4();
      break;
    case STATE_5:
      // Handle logic for STATE_15
      currentState = STATE_15;  // Reset to initial state
      break;
    case STATE_6:
      // Handle logic for STATE_15
      currentState = STATE_15;  // Reset to initial state
      break;
    case STATE_7:
      // Handle logic for STATE_15
      // Additional code here
      currentState = STATE_15;  // Reset to initial state
      break;
    case STATE_15:
      // Handle logic for STATE_15
      // Additional code here
      currentState = STATE_15;  // Reset to initial state
      break;
    default:
      // Handle unknown state
      currentState = STATE_15;  // Reset to initial state
      break;
  }
  changeState();
}

// Function to change the state
void changeState() {
  // Cycle through states: STATE_1 -> STATE_2 -> STATE_3 -> ... -> STATE_15 -> STATE_1
  switch (currentState) {
    case STATE_1:
      currentState = STATE_2;
      break;
    case STATE_2:
      currentState = STATE_3;
      break;
    case STATE_3:
      currentState = STATE_4;
      break;
    case STATE_4:
      currentState = STATE_5;
      break;
    case STATE_5:
      currentState = STATE_6;
      break;
    case STATE_6:
      currentState = STATE_7;
      break;
    case STATE_7:
      currentState = STATE_8;
      break;
    case STATE_8:
      currentState = STATE_9;
      break;
    case STATE_9:
      currentState = STATE_10;
      break;
    case STATE_10:
      currentState = STATE_11;
      break;
    case STATE_11:
      currentState = STATE_12;
      break;
    case STATE_12:
      currentState = STATE_13;
      break;
    case STATE_13:
      currentState = STATE_14;
      break;
    case STATE_14:
      currentState = STATE_15;
      break;
    case STATE_15:
      currentState = STATE_1;
      break;
  }
}
