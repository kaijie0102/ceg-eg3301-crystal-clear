const int RAIL_LENGTH = 950;
const int CUP_HEIGHT = 4400; // og: 4400 

int stepperStepCount = CUP_HEIGHT+1;
int lStepperDir = 0; // 0 to go down, 1 to go up
int stepperCycleRepCount = 0; // current up-down cycle count
int STEPPER_CYCLE_REPS = 2; // total number of up-down cycles

int STEPPER_DOWN_BURST = 1; // how many steps to move in one go
int STEPPER_DOWN_DELAY = 3500; // how many microseconds per step

int STEPPER_UP_BURST = 10;
int STEPPER_UP_DELAY = 1000; // how many microseconds per step

int stepperHoldCounter = 0;
int STEPPER_HOLD_TIME = 50;

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

    // Hold at the top
    if (stepperStepCount == CUP_HEIGHT+1) {
      if (stepperHoldCounter == STEPPER_HOLD_TIME){
        stepperStepCount--; // -1 to start at CUP_HEIGHT
        stepperHoldCounter = 0;
      } else {
        stepperHoldCounter++;
        delay(100);
      }
    } else { // move stepper if not at the top of the cup
      for (int i=0; i<STEPPER_DOWN_BURST;i++){
        digitalWrite(L_FAN_STEP_PIN, HIGH);
        delayMicroseconds(STEPPER_DOWN_DELAY);
        digitalWrite(L_FAN_STEP_PIN, LOW);
        delayMicroseconds(STEPPER_DOWN_DELAY);
      }
      stepperStepCount = stepperStepCount - STEPPER_DOWN_BURST;
    }
    
    if (stepperStepCount < 0) {
      stepperCycleRepCount++;
      if (stepperCycleRepCount < STEPPER_CYCLE_REPS){
        Serial.println("Proceed to move up");
        stopInnerFans(); // stop fan from blowing
        lStepperDir = 1; // stepper algo not complete, swap direction to go up
      } else {
        return true; // stepper algo is complete
      }
    }    
  } else { // going up
    // Serial.println("up");    

    digitalWrite(L_FAN_DIR_PIN, LOW);
    for (int i=0; i<STEPPER_UP_BURST;i++){
      digitalWrite(L_FAN_STEP_PIN, HIGH);
      delayMicroseconds(STEPPER_UP_DELAY);
      digitalWrite(L_FAN_STEP_PIN, LOW);
      delayMicroseconds(STEPPER_UP_DELAY);
    }
    
    stepperStepCount = stepperStepCount + STEPPER_UP_BURST ;
    if (stepperStepCount >= CUP_HEIGHT) {
      startInnerFans(); // start fans again
      stepperStepCount = CUP_HEIGHT+1; // hold the fan at the top
      lStepperDir = 0; // Swap direction to go down
      Serial.println("Proceed to move down"); 
    }
  }

  return false; // stepper is not done
  
}


