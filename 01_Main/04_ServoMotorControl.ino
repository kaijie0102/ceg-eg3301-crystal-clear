void setupServoMotor() {
  // Servo Motor Setup
  cupServo.attach(CUPSERVOPIN);
}

void cupServoStart(){
  cupServo.write(60);
}

void cupServoStop(){
  cupServo.write(90);
}

