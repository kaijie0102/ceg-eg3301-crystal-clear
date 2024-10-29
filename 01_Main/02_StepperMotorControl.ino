const int RAIL_LENGTH = 950; // Number of steps per output rotation
const int CUP_HEIGHT = 2000; // correct number: 3850
int stepperStepCount = CUP_HEIGHT;
int lStepperDir = 0;
int stepperCount = 0;
int STEPPER_REPS = 2;


void setupRailStepperMotor() {
  pinMode(RAIL_DIR_PIN, OUTPUT);
  pinMode(RAIL_STEP_PIN, OUTPUT);
  pinMode(RAIL_SLEEP_PIN, OUTPUT);
}

void setupFanStepperMotor() {
  pinMode(L_FAN_DIR_PIN, OUTPUT);
  pinMode(L_FAN_STEP_PIN, OUTPUT);
  pinMode(L_FAN_SLEEP_PIN, OUTPUT);
  
  pinMode(R_FAN_DIR_PIN, OUTPUT);
  pinMode(R_FAN_STEP_PIN, OUTPUT);
  pinMode(R_FAN_SLEEP_PIN, OUTPUT);
}

void moveRailStepperMotorBackwards() {
  digitalWrite(RAIL_DIR_PIN, LOW);
  digitalWrite(RAIL_SLEEP_PIN, HIGH);
  for(int x = 0; x < RAIL_LENGTH; x++)
	{
		digitalWrite(RAIL_STEP_PIN, HIGH);
		delayMicroseconds(2000);
		digitalWrite(RAIL_STEP_PIN, LOW);
		delayMicroseconds(2000);
	}
  digitalWrite(RAIL_SLEEP_PIN, LOW);
}

void moveRailStepperMotorForward() {
  digitalWrite(RAIL_DIR_PIN, HIGH);
  digitalWrite(RAIL_SLEEP_PIN, HIGH);
  for(int x = 0; x < RAIL_LENGTH; x++)
	{
		digitalWrite(RAIL_STEP_PIN, HIGH);
		delayMicroseconds(2000);
		digitalWrite(RAIL_STEP_PIN, LOW);
		delayMicroseconds(2000);
	}
  digitalWrite(RAIL_SLEEP_PIN, LOW);

}

void moveLeftFanStepperMotorUp() {
  digitalWrite(L_FAN_DIR_PIN, LOW);
  digitalWrite(L_FAN_SLEEP_PIN, HIGH);
  
  for(int x = 0; x < CUP_HEIGHT; x++)
	{
		digitalWrite(L_FAN_STEP_PIN, HIGH);
		delayMicroseconds(2000);
    digitalWrite(L_FAN_STEP_PIN, LOW);
		delayMicroseconds(2000);
	}
  digitalWrite(L_FAN_SLEEP_PIN, LOW);
}

void moveRightFanStepperMotorUp() {
  digitalWrite(R_FAN_DIR_PIN, LOW);
  digitalWrite(R_FAN_SLEEP_PIN, HIGH);
  for(int x = 0; x < CUP_HEIGHT; x++)
	{
		digitalWrite(R_FAN_STEP_PIN, HIGH);
		delayMicroseconds(2000);
		digitalWrite(R_FAN_STEP_PIN, LOW);
		delayMicroseconds(2000);
	}
  digitalWrite(R_FAN_SLEEP_PIN, LOW);
}

void moveLeftFanStepperMotorDown() {
  digitalWrite(L_FAN_DIR_PIN, HIGH);
  digitalWrite(L_FAN_SLEEP_PIN, HIGH);
  for(int x = 0; x < CUP_HEIGHT; x++)
	{
		digitalWrite(L_FAN_STEP_PIN, HIGH);
		delayMicroseconds(2000);
		digitalWrite(L_FAN_STEP_PIN, LOW);
		delayMicroseconds(2000);
	}
  digitalWrite(L_FAN_SLEEP_PIN, LOW);
}

void moveRightFanStepperMotorDown() {
  digitalWrite(R_FAN_DIR_PIN, HIGH);
  digitalWrite(R_FAN_SLEEP_PIN, HIGH);
  for(int x = 0; x < CUP_HEIGHT; x++)
	{
		digitalWrite(R_FAN_STEP_PIN, HIGH);
		delayMicroseconds(2000);
		digitalWrite(R_FAN_STEP_PIN, LOW);
		delayMicroseconds(2000);
	}
  digitalWrite(R_FAN_SLEEP_PIN, LOW);
}

int moveLeftStepperInSteps() {
  // go down
  if (lStepperDir == 0){
    digitalWrite(L_FAN_DIR_PIN, HIGH);
  
    for (int i=0; i<5;i++){
      digitalWrite(L_FAN_STEP_PIN, HIGH);
      delayMicroseconds(2000);
      digitalWrite(L_FAN_STEP_PIN, LOW);
      delayMicroseconds(2000);
    }
    
    stepperStepCount = stepperStepCount - 5;
    if (stepperStepCount < 0) {
      stepperCount++;
      if (stepperCount < STEPPER_REPS){
        lStepperDir = 1;
      } else {
        return true; // stepper algo is complete
      }
    }    
  } else { // going up
    digitalWrite(L_FAN_DIR_PIN, LOW);
    for (int i=0; i<5;i++){
      digitalWrite(L_FAN_STEP_PIN, HIGH);
      delayMicroseconds(2000);
      digitalWrite(L_FAN_STEP_PIN, LOW);
      delayMicroseconds(2000);
    }
    
    stepperStepCount = stepperStepCount + 5 ;
    if (stepperStepCount >= CUP_HEIGHT) {
      lStepperDir = 0;
    }

    return false; // stepper is not done
  }
  
}


