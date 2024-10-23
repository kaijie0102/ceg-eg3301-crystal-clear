const int RAIL_LENGTH = 950; // Number of steps per output rotation
const int CUP_HEIGHT = 3850; // Number of steps per output rotation

void setupRailStepperMotor() {
  pinMode(RAIL_DIR_PIN, OUTPUT);
  pinMode(RAIL_STEP_PIN, OUTPUT);
  pinMode(RAIL_SLEEP_PIN, OUTPUT);
}

void setupFanStepperMotor() {
  pinMode(L_FAN_DIR_PIN, OUTPUT);
  pinMode(L_FAN_STEP_PIN, OUTPUT);
  pinMode(L_FAN_SLEEP_PIN, OUTPUT);
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

void moveFanStepperMotorUp() {
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

void moveFanStepperMotorDown() {
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

void moveFanStepperMotorDownSlow() {
  digitalWrite(L_FAN_DIR_PIN, HIGH);
  digitalWrite(L_FAN_SLEEP_PIN, HIGH);
  for(int x = 0; x < CUP_HEIGHT; x++)
	{
		digitalWrite(L_FAN_STEP_PIN, HIGH);
		delayMicroseconds(5000);
		digitalWrite(L_FAN_STEP_PIN, LOW);
		delayMicroseconds(5000);
	}
  digitalWrite(L_FAN_SLEEP_PIN, LOW);
}

void executeCupDryingMode() {
  for (int i=0; i<3; i++){
    moveFanStepperMotorDownSlow();
    delay(1000*(i+1));
    moveFanStepperMotorUp();
  }  
  moveFanStepperMotorDown();
}
