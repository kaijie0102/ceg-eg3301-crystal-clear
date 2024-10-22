// Import libraries
#include <Stepper.h>
#include <Servo.h>

// Define PCB Pins
// General 
#define BUTTONPIN 16   // Pin where the push button is connected
#define CUPSERVOPIN 15 // continuous servo motor
#define CUPSERVO2PIN 14 // continuous servo motor

// Steppers
#define RAIL_DIR_PIN 21
#define RAIL_STEP_PIN 20
#define RAIL_SLEEP_PIN 19
#define FAN_DIR_PIN 5 
#define FAN_STEP_PIN 6 
#define FAN_SLEEP_PIN 7
#define FAN2_DIR_PIN 11
#define FAN2_STEP_PIN 12 
#define FAN2_SLEEP_PIN 13

// Fans
#define INNERFANRELAYPIN 23 // relay for inner fan
#define INNERFAN2RELAYPIN 27 // relay for inner fan
#define OUTERFANRELAYPIN 39 // relay for fan
#define OUTERFAN2RELAYPIN 49 // relay 2 for fan
#define FANSERVOPIN A0
#define FANSERVO2PIN A1

// Water Pumps
#define WATERPUMPRELAYPIN 52// relay for water pump
#define VALVE1RELAYPIN A5 // relay for valve 1
#define VALVE2RELAYPIN A13 // relay for valve 2 
#define VALVE3RELAYPIN A9 // relay for valve 3

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

// Define Arduino Pins FlatSat
// General 
/*
#define BUTTONPIN 2    // Pin where the push button is connected
#define CUPSERVOPIN 3 // continuous servo motor
#define CUPSERVO2PIN 4 // continuous servo motor

// Steppers
#define RAIL_DIR_PIN 5
#define RAIL_STEP_PIN 6
#define RAIL_SLEEP_PIN 7
#define FAN_DIR_PIN 8
#define FAN_STEP_PIN 9 
#define FAN_SLEEP_PIN 10
//#define FAN2_DIR_PIN 11
//#define FAN2_STEP_PIN 12 
//#define FAN2_SLEEP_PIN 13

// Fans
#define INNERFANRELAYPIN 22 // relay for inner fan
#define INNERFAN2RELAYPIN 24 // relay for inner fan
#define OUTERFANRELAYPIN 26 // relay for fan
#define OUTERFAN2RELAYPIN 28 // relay 2 for fan
#define FANSERVOPIN 33
#define FANSERVO2PIN 35

// Water Pumps
#define WATERPUMPRELAYPIN 46// relay for water pump
#define VALVE1RELAYPIN 48 // relay for valve 1
#define VALVE2RELAYPIN 50// relay for valve 2
#define VALVE3RELAYPIN 52 // relay for valve 3
*/

// Define 15 states for the finite state machine
enum State {
  STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, STATE_6, STATE_7, STATE_8,
  STATE_9, STATE_10, STATE_11, STATE_12, STATE_13, STATE_14, STATE_15
};  
State currentState = STATE_1;

// 02_PowerControl
// void setupRelay();

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
void fanServoStart();
void cupServoStop();

// 05_Ui
void setupUi();
void readButtonInput();

// 06_Fan
void setupFanRelay();
void startInternalFans();
void stopInternalFans();

// 07_SolenoidValveControl
void setupSolenoidValve();
void openValve1();
void openValve2();
void openValve3();
void closeValve1();
void closeValve2();
void closeValve3();

// 08_StateControl
void executeState1();
void executeState2();
void executeState3();
void executeState4();

void setup() {

  setupFanRelay();
  setupRailStepperMotor();
  setupFanStepperMotor();
  setupServoMotor();
  setupSolenoidValve();

  setupUi(); 
  
  // Initialize the serial port:
  Serial.begin(9600);

  Serial.println();
  Serial.println("===============");
  Serial.println("Set up complete");

}

void loop() {
  handleState();
}


// Function to handle the logic for each state
void handleState() {
  switch (currentState) {
    case STATE_1: // Start and setup
      executeState1();
      break;
    case STATE_2: // 
      executeState2();
      break;
    case STATE_3:
      executeState3();
      break;
    case STATE_4:
      executeState4();
      break;
    case STATE_5:
      executeTeardown();
      // Handle logic for STATE_15
      // currentState = STATE_15;  // Reset to initial state
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
      // currentState = STATE_2;
      currentState = STATE_1;
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
