Servo cupServoL;  // pin 3 create continuous servo object
Servo cupServoR;  // pin 4 create continuous servo object
Servo fanServoL; // pin 33
Servo fanServoR; // pin 35  

int SPINNING_SPEED = 70; // 90 to stop, 0 fastest
int servoTopPos = 125;
int servoBottomPos = 60;
int servoPos = servoTopPos;
int SERVO_DRYING_REPS = 3;
int servoCount;
int lServoDir = 0; // start with up all the way

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


// void fanServoStart() {
  
//   for (pos = 125; pos >= 60; pos -= 1) {
//     if (pos == 125 || pos == 60){
//       delay(5000);
//     }
//     fanServoL.write(pos);
//     // fanServoR.write(pos);
//     // cupServoL.write(pos);
//     delay(150);
//     if (pos==60 && done!=1){
//       pos=125;
//       done = 1;
//     }
//   }
// }

bool moveLeftServoInSteps() {
  Serial.println("In servo");
  if (lServoDir == 0){ // blowing from top to bottom
    Serial.println("Blowing top down");
    if (servoPos == servoTopPos){
      fanServoL.write(servoPos);
      delay(5000);
      servoPos--;
    } else {
      fanServoL.write(servoPos);
      servoPos = servoPos-1;
    }
    
    if (servoPos == servoBottomPos) {
      if (servoCount < SERVO_DRYING_REPS){
        servoCount++;
        lServoDir = 1;
      } else{
        return true; // stepper algo is complete
      }
    }
  } else { // blowing bottom to top. lServoDir == 1
    Serial.println("Blowing bottom up");
    if (servoPos == servoBottomPos){
      fanServoL.write(servoPos);
      delay(5000);
      servoPos++;
    } else {
      fanServoL.write(servoPos);
      servoPos++;
    }

    if (servoPos == servoTopPos) {
      lServoDir = 0; // if on top, must go down
      
    }
  }
  return false;
}



