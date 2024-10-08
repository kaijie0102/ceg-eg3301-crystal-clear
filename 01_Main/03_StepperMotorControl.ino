const int totalRevolutionsForMovement = 5; // Modify to increase duration of stepper movement
const int stepsPerRevolution = 200; // Do not modify. Number of steps per output rotation

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
  fanStepper.step(-stepsPerRevolution * totalRevolutionsForMovement);
}

void moveFanStepperMotorDown() {
  fanStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
}
