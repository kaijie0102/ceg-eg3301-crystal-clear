Servo cupServo;  // create continuous servo object
Servo cupServo2;  // create continuous servo object
Servo fanServo;
Servo fanServo2;
// unsigned long timer; 
// static const unsigned long timeout = 7500; // loop ends after specified duration
// int servoCounter = 0;  

void setupServoMotor() {
  // Servo Motor Setup
  cupServo.attach(CUPSERVOPIN);
  cupServo2.attach(CUPSERVO2PIN);
  fanServo.attach(FANSERVOPIN);
  fanServo2.attach(FANSERVO2PIN);
  
}

int pos;

void cupServoStart(){
  cupServo.write(60);
  cupServo2.write(60);
  
  delay(3000);
}

void cupServoStop(){
  cupServo.write(90);
}

void cupServo2Start() {
  for (pos = 0; pos <= 180; pos += 1) {
    fanServo.write(pos);
    fanServo2.write(pos);
    delay(15);
    if (pos==180){
      pos=0;
    }
  }
}

