Servo cupServoL;  // pin 3 create continuous servo object
Servo cupServoR;  // pin 4 create continuous servo object
Servo fanServoL; // pin 33
Servo fanServoR; // pin 35
// unsigned long timer; 
// static const unsigned long timeout = 7500; // loop ends after specified duration
// int servoCounter = 0;  

int SPINNING_SPEED = 70; // 90 to stop, 0 fastest
int servoStartPos = 125;
int servoEndPos = 60;
int servoPos = servoStartPos;
int done;
int SERVO_DRYING_REP = 3;
int servoHold = 0; // start with not holding
const unsigned long servoDelay = 150; // Delay in milliseconds
const unsigned long holdDelay = 5000; // Hold at start and end position in milliseconds
unsigned long previousServoMillis = 0;
unsigned long servoHoldStart = 0;




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

bool leftFanServoDryingMode() {
  // Handle servo motor movement
  SERVO_DRYING_REP -= 1;
  unsigned long currentMillis = millis();
  if (!servoHold) {
    if (currentMillis - previousServoMillis >= servoDelay) {
      previousServoMillis = currentMillis;
      fanServoL.write(servoPos);

      servoPos--; // Move down
      if (servoPos <= servoEndPos) {
        servoHold = true;
        servoHoldStart = currentMillis;
      }
    }
  } else if (servoHold) {
    // Hold at position before reversing
    if (currentMillis - servoHoldStart >= holdDelay) {
      servoPos = servoStartPos; // Reset to start
      servoHold = false;         // Resume movement
      previousServoMillis = currentMillis;
    }
  }  

  if (SERVO_DRYING_REP==0){
    return true;
  }
  return false;
  
}

