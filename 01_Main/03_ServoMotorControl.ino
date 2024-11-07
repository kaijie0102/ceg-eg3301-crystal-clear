Servo cupServoL;  // pin 3 create continuous servo object
Servo cupServoR;  // pin 4 create continuous servo object
Servo fanServoL; // pin 33
Servo fanServoR; // pin 35  

// settings for the 360 deg cup servo motors
int SPINNING_SPEED = 80; // 90 to stop, 0 fastest

// settings for the fan servo motors
int SERVO_TOP_POS = 120;
int SERVO_BOTTOM_POS = 40;
int servoPos = SERVO_TOP_POS;
int SERVO_DRYING_REPS = 3;
int servoDryingCount;
int lServoDir = 0; // start with top down 
int servoMicroSteps = 0; // every servoMicroSteps, +1 to servoPos, and change angle 
int done = 0; 

void setupServoMotor() {
  // Servo Motor Setup
  cupServoL.attach(L_CUPSERVO_PIN);
  cupServoR.attach(R_CUPSERVO_PIN);
  fanServoL.attach(L_FANSERVO_PIN);
  fanServoR.attach(R_FANSERVO_PIN); 
}

void cupServoStart(){
  for (int i=0; i<SPINNING_SPEED; i+=10) { // slowly go from 0 to 80
    cupServoR.write(i); 
    cupServoL.write(i); 
    delay(200);
  }  
}

void cupServoStop(){
  cupServoL.write(90);
  cupServoR.write(90);
}

void fanServoStart() {
  Serial.println("In servo fan");
  for (servoPos = 125; servoPos >= 60; servoPos -= 1) {
    if (servoPos == 125 || servoPos == 60){
      delay(5000);
    }
    fanServoL.write(servoPos);
    delay(150);
    if (servoPos==60 && done!=1){
      servoPos=125;
      done = 1;
    }
  }
}

bool moveLeftServoInSteps() {
  if (lServoDir == 0){ // blowing from top to bottom
    if (servoPos == SERVO_TOP_POS){
      if (servoMicroSteps > 500) {
        // delay is complete, start moving down
        servoPos--; 
        servoMicroSteps = 0;
      } 
      servoMicroSteps++;
    } else if (servoMicroSteps == 20 ){
      
      servoMicroSteps=0; // reset to 0
      fanServoL.write(servoPos); // change angle of servo
      servoPos = servoPos-1;
    } else {
      servoMicroSteps++;
    }
    
    if (servoPos == SERVO_BOTTOM_POS) {
      servoDryingCount++;
      if (servoDryingCount < SERVO_DRYING_REPS){
        lServoDir = 1;
        stopOuterFans(); // stop fans when moving up
      } else{
        return true; // servo algo is complete
      }
    }
  } else { // blowing bottom to top. lServoDir == 1
    if (servoPos == SERVO_BOTTOM_POS){
      
      if (servoMicroSteps > 500) {
        // delay is complete, start moving up
        servoPos++; 
        servoMicroSteps = 0;
      }
      servoMicroSteps++;
    } else {
      fanServoL.write(servoPos);
      servoPos++;
    }

    if (servoPos == SERVO_TOP_POS) {
      lServoDir = 0; // change direction to move down
      startOuterFans(); // start fans when moving down
      
    }
  }
  return false;
}

bool moveFanServoInSteps() {
  if (lServoDir == 0){ // blowing from top to bottom
    if (servoPos == SERVO_TOP_POS){
      
      if (servoMicroSteps > 500) {
        // delay is complete, start moving down
        servoPos--; 
        servoMicroSteps = 0;
      } 
      servoMicroSteps++;
    } else if (servoMicroSteps == 20 ){
      
      servoMicroSteps=0; // reset to 0
      fanServoL.write(servoPos); // change angle of servo
      fanServoR.write(servoPos); // change angle of servo
      servoPos = servoPos-1;
    } else {
      servoMicroSteps++;
    }
    
    if (servoPos == SERVO_BOTTOM_POS) {
      servoDryingCount++;
      if (servoDryingCount < SERVO_DRYING_REPS){
        lServoDir = 1;
        stopOuterFans(); // stop fans when moving up
      } else{
        return true; // servo algo is complete
      }
    }
  } else { // blowing bottom to top. lServoDir == 1
    if (servoPos == SERVO_BOTTOM_POS){
      
      if (servoMicroSteps > 500) {
        // delay is complete, start moving up
        servoPos++; 
        servoMicroSteps = 0;
      }
      servoMicroSteps++;
    } else {
      fanServoL.write(servoPos);
      fanServoR.write(servoPos);
      servoPos++;
    }

    if (servoPos == SERVO_TOP_POS) {
      lServoDir = 0; // change direction to move down
      startOuterFans(); // start fans when moving down
    }
  }
  return false;
}



