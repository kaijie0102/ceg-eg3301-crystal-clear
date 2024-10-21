Servo cupServo;  // pin 3 create continuous servo object
Servo cupServo2;  // pin 4 create continuous servo object
Servo fanServo; // pin 33
Servo fanServo2; // pin 35
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
  cupServo.write(0); // pin 3
  cupServo2.write(0); // pin 4
  
  delay(3000);
  // cupServo.write(90);
  // cupServo2.write(90);
}

void cupServoStop(){
  cupServo.write(90);
}

void fanServoStart() {
  for (pos = 0; pos <= 180; pos += 1) {
    // fanServo.write(pos);
    // fanServo2.write(pos);
    // cupServo.write(pos);
    delay(15);
    if (pos==180){
      pos=0;
    }
  }
}

