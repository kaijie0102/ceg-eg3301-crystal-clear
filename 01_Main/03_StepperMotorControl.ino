const int totalRevolutionsForMovement = 5; // Modify to increase duration of stepper movement
const int stepsPerRevolution = 200; // Do not modify. Number of steps per output rotation
// Stepper railStepper(stepsPerRevolution, 4, 6, 5, 7); // Create Instance of Stepper library
// Stepper fanStepper(stepsPerRevolution, 8, 9, 10, 11); // Create Instance of Stepper library
Stepper railStepper(stepsPerRevolution, RAIL_PIN1, RAIL_PIN2, RAIL_PIN3, RAIL_PIN4); // Create Instance of Stepper library
Stepper fanStepper(stepsPerRevolution, FAN1_PIN1, FAN1_PIN2, FAN1_PIN3, FAN1_PIN4); // Create Instance of Stepper library

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
  digitalWrite(RAIL_ENA_PIN1, HIGH);
  digitalWrite(RAIL_ENA_PIN2, HIGH);
  digitalWrite(RAIL_ENB_PIN1, HIGH);
  digitalWrite(RAIL_ENB_PIN2, HIGH);
  railStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
  digitalWrite(RAIL_ENA_PIN1, LOW);
  digitalWrite(RAIL_ENA_PIN2, LOW);
  digitalWrite(RAIL_ENB_PIN1, LOW);
  digitalWrite(RAIL_ENB_PIN2, LOW);
}

void moveRailStepperMotorForward() {
  digitalWrite(RAIL_ENA_PIN1, HIGH);
  digitalWrite(RAIL_ENA_PIN2, HIGH);
  digitalWrite(RAIL_ENB_PIN1, HIGH);
  digitalWrite(RAIL_ENB_PIN2, HIGH);
  railStepper.step(-stepsPerRevolution * totalRevolutionsForMovement);
  digitalWrite(RAIL_ENA_PIN1, LOW);
  digitalWrite(RAIL_ENA_PIN2, LOW);
  digitalWrite(RAIL_ENB_PIN1, LOW);
  digitalWrite(RAIL_ENB_PIN2, LOW);
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
