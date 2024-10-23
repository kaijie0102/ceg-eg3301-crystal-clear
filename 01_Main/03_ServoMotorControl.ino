Servo cupServoL;  // pin 3 create continuous servo object
Servo cupServoR;  // pin 4 create continuous servo object
Servo fanServoL; // pin 33
Servo fanServoR; // pin 35
// unsigned long timer; 
// static const unsigned long timeout = 7500; // loop ends after specified duration
// int servoCounter = 0;  

int SPINNING_SPEED = 70; // 90 to stop, 0 fastest
int pos = 125;
int done;

void setupServoMotor() {
  // Servo Motor Setup
  cupServoL.attach(L_CUPSERVO_PIN);
  cupServoR.attach(R_CUPSERVO_PIN);
  fanServoL.attach(L_FANSERVO_PIN);
  fanServoR.attach(R_FANSERVO_PIN); 
}

void cupServoStart(){
  cupServoL.write(0); 
  delay(2000);
  cupServoL.write(SPINNING_SPEED); 
  // cupServoR.write(SPINNING_SPEED); 
  
}

void cupServoStop(){
  cupServoL.write(90);
  // cupServoR.write(90);
}


// void fanServoPanDown(){

// }


void fanServoStart() {
  
  for (pos = 125; pos >= 60; pos -= 1) {
    if (pos == 125 || pos == 60){
      delay(5000);
    }
    fanServoL.write(pos);
    // fanServoR.write(pos);
    // cupServoL.write(pos);
    delay(150);
    if (pos==60 && done!=1){
      pos=125;
      done = 1;
    }
  }
}

