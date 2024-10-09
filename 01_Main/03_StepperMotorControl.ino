const int RAIL_LENGTH = 1000; // Do not modify. Number of steps per output rotation
const int CUP_HEIGHT = 500; // Do not modify. Number of steps per output rotation

void setupRailStepperMotor() {
  pinMode(RAIL_DIR_PIN, OUTPUT);
  pinMode(RAIL_STEP_PIN, OUTPUT);
  pinMode(RAIL_SLEEP_PIN, OUTPUT);
}


void setupFanStepperMotor() {
  pinMode(FAN_DIR_PIN, OUTPUT);
  pinMode(FAN_STEP_PIN, OUTPUT);
  pinMode(FAN_SLEEP_PIN, OUTPUT);
}

void moveRailStepperMotorBackwards() {
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

void moveRailStepperMotorForward() {
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

void moveFanStepperMotorUp() {
  digitalWrite(FAN_DIR_PIN, LOW);
  digitalWrite(FAN_SLEEP_PIN, HIGH);
  for(int x = 0; x < CUP_HEIGHT; x++)
	{
		digitalWrite(FAN_STEP_PIN, HIGH);
		delayMicroseconds(2000);
		digitalWrite(FAN_STEP_PIN, LOW);
		delayMicroseconds(2000);
	}
  digitalWrite(FAN_SLEEP_PIN, LOW);
}

void moveFanStepperMotorDown() {
  digitalWrite(FAN_DIR_PIN, HIGH);
  digitalWrite(FAN_SLEEP_PIN, HIGH);
  for(int x = 0; x < CUP_HEIGHT; x++)
	{
		digitalWrite(FAN_STEP_PIN, HIGH);
		delayMicroseconds(2000);
		digitalWrite(FAN_STEP_PIN, LOW);
		delayMicroseconds(2000);
	}
  digitalWrite(FAN_SLEEP_PIN, LOW);
}
