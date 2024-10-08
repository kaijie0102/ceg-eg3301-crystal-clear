// Import libraries
#include <Stepper.h>

void setupRailStepperMotor() {
  // put your setup code here, to run once:
  // Stepper Motor Setup
  pinMode(RAIL_ENA_PIN1, OUTPUT);
  pinMode(RAIL_ENA_PIN2, OUTPUT);
  pinMode(RAIL_ENB_PIN1, OUTPUT);
  pinMode(RAIL_ENB_PIN2, OUTPUT);

  railStepper.setSpeed(60);// set the speed at 60 rpm
}


void setupFanStepperMotor() {
  pinMode(FAN_ENA_PIN1, OUTPUT);
  pinMode(FAN_ENA_PIN2, OUTPUT);
  pinMode(FAN_ENB_PIN1, OUTPUT);
  pinMode(FAN_ENB_PIN2, OUTPUT);
  
  fanStepper.setSpeed(60);// set the speed at 60 rpm
}

void moveRailStepperMotorBackwards() {
  railStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
}

void moveRailStepperMotorForward() {
  railStepper.step(-stepsPerRevolution * totalRevolutionsForMovement);
}

void moveFanStepperMotorUp() {
  digitalWrite(FAN_ENA_PIN1, HIGH);
  digitalWrite(FAN_ENA_PIN2, HIGH);
  digitalWrite(FAN_ENB_PIN1, HIGH);
  digitalWrite(FAN_ENB_PIN2, HIGH);
  fanStepper.step(-stepsPerRevolution * totalRevolutionsForMovement);
  digitalWrite(FAN_ENA_PIN1, LOW);
  digitalWrite(FAN_ENA_PIN2, LOW);
  digitalWrite(FAN_ENB_PIN1, LOW);
  digitalWrite(FAN_ENB_PIN2, LOW);
}

void moveFanStepperMotorDown() {
  digitalWrite(FAN_ENA_PIN1, HIGH);
  digitalWrite(FAN_ENA_PIN2, HIGH);
  digitalWrite(FAN_ENB_PIN1, HIGH);
  digitalWrite(FAN_ENB_PIN2, HIGH);
  fanStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
  digitalWrite(FAN_ENA_PIN1, LOW);
  digitalWrite(FAN_ENA_PIN2, LOW);
  digitalWrite(FAN_ENB_PIN1, LOW);
  digitalWrite(FAN_ENB_PIN2, LOW);
}
