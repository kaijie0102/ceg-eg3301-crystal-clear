Servo cupServoL;  // pin 3 create continuous servo object
Servo cupServoR;  // pin 4 create continuous servo object
Servo fanServoL; // pin 33
Servo fanServoR; // pin 35
// unsigned long timer; 
// static const unsigned long timeout = 7500; // loop ends after specified duration
// int servoCounter = 0;  

int SPINNING_SPEED = 80; // 90 to stop, 0 fastest
int pos;

void setupServoMotor() {
  // Servo Motor Setup
  cupServoL.attach(L_CUPSERVO_PIN);
  cupServoR.attach(R_CUPSERVO_PIN);
  fanServoL.attach(L_FANSERVO_PIN);
  fanServoR.attach(R_FANSERVO_PIN);
  
}


void cupServoStart(){
  // cupServoL.write(SPINNING_SPEED); 
  cupServoL.write(SPINNING_SPEED); 
  
  delay(3000);
  // cupServoL.write(90);
  // cupServoL.write(90);
}

void cupServoStop(){
  cupServoL.write(90);
}

void fanServoStart() {
  for (pos = 0; pos <= 180; pos += 1) {
    // fanServoL.write(pos);
    fanServoR.write(pos);
    // cupServoL.write(pos);
    delay(15);
    if (pos==180){
      pos=0;
    }
  }
}

