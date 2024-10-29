const int RAIL_LENGTH = 950; // Number of steps per output rotation
// const int CUP_HEIGHT = 3850; // Number of steps per output rotation
const int CUP_HEIGHT = 2000; // Number of steps per output rotation

unsigned long previousStepperMicros = 0;
int stepperStepCount = 0;
const unsigned long stepperDelay = 5000; // Delay for each step in microseconds


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

int stepLeftStepperUp() {
  digitalWrite(L_FAN_DIR_PIN, LOW);
  
  for (int i=0; i<5;i++){
    digitalWrite(L_FAN_STEP_PIN, HIGH);
    delayMicroseconds(2000);
    digitalWrite(L_FAN_STEP_PIN, LOW);
    delayMicroseconds(2000);
  }
	
  stepperStepCount = stepperStepCount + 5 ;
  if (stepperStepCount >= CUP_HEIGHT) {
    digitalWrite(L_FAN_SLEEP_PIN, LOW);
    return 1; // Stop stepper when done
  }

  return 0;
}

int stepLeftStepperDown() {
  digitalWrite(L_FAN_DIR_PIN, HIGH);
  
  for (int i=0; i<5;i++){
    digitalWrite(L_FAN_STEP_PIN, HIGH);
    delayMicroseconds(2000);
    digitalWrite(L_FAN_STEP_PIN, LOW);
    delayMicroseconds(2000);
  }
	
  stepperStepCount = stepperStepCount - 5;
  if (stepperStepCount < 0) {
    digitalWrite(L_FAN_SLEEP_PIN, LOW);
    return 2; // Stop stepper when done
  }

  return 1;
}

// void moveFanStepperMotorDownSlow() {
//   digitalWrite(L_FAN_DIR_PIN, HIGH);
//   digitalWrite(L_FAN_SLEEP_PIN, HIGH);
//   for(int x = 0; x < CUP_HEIGHT; x++)
// 	{
// 		digitalWrite(L_FAN_STEP_PIN, HIGH);
// 		delayMicroseconds(5000);
// 		digitalWrite(L_FAN_STEP_PIN, LOW);
// 		delayMicroseconds(5000);
// 	}
//   digitalWrite(L_FAN_SLEEP_PIN, LOW);
// }

// bool leftFanStepperDryingMode(){
//   // Handle stepper motor movement
//   // previousStepperMicros = micros();
//   // unsigned long currentMicros = micros();
//   // if (currentMicros - previousStepperMicros >= stepperDelay) {
//   // previousStepperMicros = currentMicros;
//   digitalWrite(L_FAN_STEP_PIN, HIGH);
//   delayMicroseconds(5000);
//   digitalWrite(L_FAN_STEP_PIN, LOW);
//   delayMicroseconds(5000);

//   stepperStepCount++;
//   if (stepperStepCount >= CUP_HEIGHT) {
//     digitalWrite(L_FAN_SLEEP_PIN, LOW);
//     return true; // Stop stepper when done
//   }

//   return false;
//   // }
  
// }

// void executeCupDryingMode() {
//   for (int i=0; i<3; i++){
//     moveFanStepperMotorDownSlow();
//     delay(1000*(i+1));
//     moveFanStepperMotorUp();
//   }  
//   moveFanStepperMotorDown();
// }

