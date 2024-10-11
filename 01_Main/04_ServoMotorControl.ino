Servo cupServo;  // create continuous servo object
// unsigned long timer; 
// static const unsigned long timeout = 7500; // loop ends after specified duration
// int servoCounter = 0;  

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

