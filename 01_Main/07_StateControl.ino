////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Execute States in Sequence //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void executeState1() {
  executeInitialisation();
  
  executeSetupDryingPhase();
  executeDryingPhase();
  executeEndDryingPhase();

  // moveLeftServoInSteps();
  // moveLeftFanStepperMotorDown();

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
  // Serial.println("Fan stepper move up");
  fanServoL.write(125);
  moveLeftFanStepperMotorUp();
  startInnerFans();
  startOuterFans();
  delay(1000); 

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
  digitalWrite(L_FAN_SLEEP_PIN, HIGH);
  while (!servoDone || !stepperDone) {
    if (!stepperDone) {
      stepperDone = moveLeftStepperInSteps();
    }
    if (!servoDone) {
      servoDone = moveLeftServoInSteps();
    }
    // Serial.print("servoDone: ");
    // Serial.println(servoDone);
    // Serial.print("stepperDone: ");
    // Serial.println(stepperDone);
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
}

void executeTeardown() {
  closeValve1();
  closeValve2();
  closeValve3();
  Serial.println("Cleaning finished");
  Serial.println("===============");
}
