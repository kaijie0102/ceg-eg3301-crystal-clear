////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Execute States in Sequence //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void executeState1() {
  ledStandbyMode();
  executeInitialisation();
  // cupServoStart();

  // executeMoveToDryingCompartment();
  // ledWashMode();
  // delay(8000);
  // ledStandbyMode();
  // ledDryMode();
  // executeSetupDryingPhase();
  // executeDryingPhase();
  // ledCompleteMode();
  // executeEndDryingPhase();

  // moveLeftServoInSteps();
  // moveLeftFanStepperMotorDown();
  startInnerFans();
  // startOuterFans();
  // executeDryingOnly();
}

void executeState2() {
    Serial.println("STATE 2 - washing phase");
    // washing cycle 1
    executeWashingCycle();
    // executeWaterRegeneration();
  
    // washing cycle 2
//    executeWashingCycle();
//    executeWaterRegeneration();

    // washing cycle 3
    executeWashingCycle();
    executeEndWashingCycle();
}

void executeState3() {
    Serial.println("STATE 3 - setup drying phase");
    executeMoveToDryingCompartment();
    executeSetupDryingPhase();
  }

void executeState4() {
    Serial.println("STATE 4 - drying phase");
    executeDryingPhase();
    executeEndDryingPhase();
}

void executeWashingOnly() {
  executeInitialisation();
}

void executeDryingOnly() {
  executeInitialisation();
  executeSetupDryingPhase();
  executeDryingPhase();
  executeEndDryingPhase();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Functions for each operation ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

// Initialisation
void executeInitialisation() {
    Serial.println("STATE - Await Button Press");
    readButtonInput();    
    ledOn();
}

// Move to washing compartment
void executeMoveToWashingCompartment() {
    Serial.println("STATE - Wash Cycle Setup");
        
    Serial.println("h stepper backwards");
    moveRailStepperMotorBackwards();
    cupServoStart();  
}


// Washing Cycle 1 
void executeWashingCycle() {
  Serial.println("STATE - First wash cycle");
  
  // openValve1();
  // delay(3000);    
  // closeValve1();

  openValve2();
  onInnerPump();
  
  Serial.println("Washing Starts");
  delay(30000);
    
}

// End wash cycle
void executeEndWashingCycle() {
  cupServoStop();
  Serial.println("Washing Stops");

  offInnerPump();
  Serial.println("Water Pump off");
  closeValve2();
  Serial.println("STATE - End Washing Cycle");
  delay(10000);
  
}
/*
// Water Regeneration 
void executeWaterRegeneration() {
    Serial.println("STATE - Water Regeneration");
    Serial.println("Cup servo stop spinning");
    cupServoStop();

    
    closeValve2();

    
    openValve3();
    delay(3000);

    
    openValve1();
    delay(3000);

    
    closeValve1();

    
    closeValve2();
    delay(3000);

    
    closeValve3();
    delay(3000);
}
*/


// Move to drying compartment
void executeMoveToDryingCompartment() {
  Serial.println("STATE - Move To Drying Compartment");
  // step one revolution in the other direction:
  Serial.println("Move rail stepper to drying compartment");
  moveRailStepperMotorForward();
  delay(3000);
}


// Set up drying phase
void executeSetupDryingPhase() {
  Serial.println("STATE - Set Up Drying Phase");

  // move the 2 fan servos to the starting position
  fanServoL.write(SERVO_TOP_POS);
  fanServoR.write(SERVO_TOP_POS);

  // move fan stepper motors into the right position
  moveFanStepperMotorsUp();

  // activate the fans 
  startInnerFans();
  startOuterFans();
  delay(1000); // delay for fans to start up

  // Serial.println("Cup Servo start spinning");
  cupServoStart();
  Serial.println("Drying Setup Complete");
  delay(1000);
}

// Drying Algorithm
void executeDryingPhase() {
  Serial.println("STATE - Execute Drying Process");
  // continuously loop until all done
  bool servoDone = false;
  bool stepperDone = false;
  digitalWrite(L_FAN_SLEEP_PIN, HIGH); // Activate left stepper motor
  digitalWrite(R_FAN_SLEEP_PIN, HIGH); // Activate right stepper motor
  while (!servoDone || !stepperDone) {
    if (!stepperDone) {
      // stepperDone = moveLeftStepperInSteps();
      stepperDone = moveFanStepperInSteps();
    }
    if (!servoDone) {
      servoDone = moveLeftServoInSteps();
      // servoDone = moveFanServoInSteps();
    }
  }  
  Serial.println("Drying Finished");
}

// End of drying phase
void executeEndDryingPhase() {
  Serial.println("STATE - End of Drying Process");
  // cup stop, fan stop
  cupServoStop();
  stopInnerFans();
  stopOuterFans();
  Serial.println("Fan OFF");
  Serial.print("State Number: ");
  Serial.println(currentState);
  
  // reset all variables
  resetVariables();
}

void executeTeardown() {
  closeValve1();
  closeValve2();
  closeValve3();
  Serial.println("Cleaning finished");
  Serial.println("===============");
}

void resetVariables() {
  // reset stepper variables
  stepperHoldCounter = 0;
  stepperCycleRepCount = 0;
  lStepperDir = 0;
  stepperStepCount = CUP_HEIGHT+1;

  // reset servo variables 
  servoDryingCount = 0; // reset to zero once done
  servoPos = SERVO_TOP_POS; // the next time it will start at the top
  servoMicroSteps = 0;
  lServoDir = 0; // reset direction to start with top down
}
