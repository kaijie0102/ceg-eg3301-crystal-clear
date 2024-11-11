// Import libraries
#include <Stepper.h>
#include <Servo.h>
#include <SoftwareSerial.h>


// Define PCB Pins
// General 
#define BUTTON_PIN 16   // Pin where the push button is connected
#define BUTTON_LED_PIN 18 //  button led
#define L_CUPSERVO_PIN 15 // Label: Cup Servo 1
#define R_CUPSERVO_PIN 14 // Label: Fan Servo 2

// Stepper motors
#define RAIL_DIR_PIN 21
#define RAIL_STEP_PIN 20
#define RAIL_SLEEP_PIN 19
#define L_FAN_DIR_PIN 11 
#define L_FAN_STEP_PIN 12 
#define L_FAN_SLEEP_PIN 13 
#define R_FAN_DIR_PIN 5
#define R_FAN_STEP_PIN 6 
#define R_FAN_SLEEP_PIN 7

// Fans
#define L_INNER_FAN_PIN 39// 23 // relay for left inner fan
#define R_INNER_FAN_PIN 49//27 // relay for right inner fan
#define L_OUTER_FAN_PIN 23//39 // relay for left outer fan
#define R_OUTER_FAN_PIN 27//49 // relay for right outer fan

// Fan servo motors
#define L_FANSERVO_PIN A1 // Label: Fan Servo 1
#define R_FANSERVO_PIN A0 // Label: Fan Servo 2

// Water Pumps
#define WATER_PUMP_PIN 52// relay for water pump
#define VALVE_1_PIN A5 // relay for valve 1
#define VALVE_2_PIN A13 // relay for valve 2 
#define VALVE_3_PIN A9 // relay for valve 3

// Define 15 states for the finite state machine
enum State {
  STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, STATE_6, STATE_7, STATE_8,
  STATE_9, STATE_10, STATE_11, STATE_12, STATE_13, STATE_14, STATE_15
};  
State currentState = STATE_1;

// 02_StepperMotorControl
void setupRailStepperMotor();
void setupFanStepperMotor();
void moveRailStepperMotorBackwards();
void moveRailStepperMotorForward();
void moveLeftFanStepperMotorUp();
void moveRightFanStepperMotorUp();
void moveFanStepperMotorsUp();
void moveLeftFanStepperMotorDown();
void moveRightFanStepperMotorDown();
bool moveLeftStepperInSteps();
bool moveFanStepperInSteps();

// 03_ServoMotorControl
void setupServoMotor();
void cupServoStart();
void fanServoStart();
void cupServoStop();
bool moveLeftServoInSteps();
bool moveFanServoInSteps();

// 04_Ui
void setupUi();
void readButtonInput();
void ledOn();
void ledOff();

// 05_Fan
void setupFanRelay();
void startInnerFans();
void startOuterFans();
void stopInnerFans();
void stopOuterFans();

// 06_SolenoidValveControl
void setupSolenoidValve();
void openValve1();
void openValve2();
void openValve3();
void closeValve1();
void closeValve2();
void closeValve3();
void onInnerPump();
void offInnerPump();

// 07_StateControl
void executeState1();
void executeState2();
void executeState3();
void executeState4();
void executeWashingOnly();
void executeDryingOnly();
void executeInitialisation();
void executeMoveToWashingCompartment();
void executeWashingCycle();
void executeEndWashingCycle();
void executeWaterRegeneration();
void executeMoveToDryingCompartment();
void executeSetupDryingPhase();
void executeDryingPhase();
void executeEndDryingPhase();
void executeTeardown();
void resetVariables();

// 08_Serial
void setupSerial();
void ledStandbyMode();
void ledWashMode();
void ledDryMode();
void ledCompleteMode();
void performSerial();

void setup() {

  setupFanRelay();
  setupRailStepperMotor();
  setupFanStepperMotor();
  setupServoMotor();
  setupSolenoidValve();
  setupUi(); 
  setupSerial();
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
      executeTeardown();
      break;
    case STATE_15:
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
  // Cycle through states: STATE_1 -> STATE_2 -> STATE_3 -> STATE_1
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
      currentState = STATE_15;
      break;
    case STATE_15:
      currentState = STATE_1;
      break;
  }
}