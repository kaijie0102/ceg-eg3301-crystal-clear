////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Execute States in Sequence //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void executeState1() {
  // readButtonInput();  
  executeInitialisation();
  executeDryingPhase();
  // moveLeftFanStepperMotorDown();
  
  // moveRailStepperMotorForward();
  // moveRightFanStepperMotorDown();
  // cupServoStart();
  // executeMoveToWashingCompartment();
  // executeWashingCycle();
  // executeEndWashingCycle();

  // fanServoL.write(125);
  // delay(3000);
  // moveFanStepperMotorDown();
  // cupServoStart();
  // startFans();
  // fanServoStart();
  // delay(10000);
  // cupServoStop();
  // stopFans();
  

  // TODO
  // 1) Execute Washing only
  // 2) Execute Drying Only

    // executeSetupDryingPhase();
    // executeDryingPhase();
    // executeEndDryingPhase();

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

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Functions for each operation ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

// Initialisation
void executeInitialisation() {
    Serial.println("STATE - Await Button Press");
    readButtonInput();    
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
  Serial.println("Fan stepper move up");
  fanServoL.write(125);
  moveLeftFanStepperMotorUp();
  delay(3000); 

  Serial.println("Cup Servo start spinning");
  cupServoStart();
  delay(3000);
}

// Drying Algorithm
void executeDryingPhase() {
  // continuously loop until all done
  bool servoDone = false;
  bool stepperDone = false;
  bool stepperDownDone = false;
  int stepperState = 0;
  // int stepperCount = 0;
  digitalWrite(L_FAN_SLEEP_PIN, HIGH);
  while (!servoDone && !stepperDone){
    stepperDone = moveLeftStepperInSteps();
    // servoDone = moveLeftServoInSteps();
  }
}

// // Drying 
// void executeDryingPhase() {
//   Serial.println("STATE - Drying Phase");
  
//   Serial.println("Fan ON");
//   startFans();

//   int dry_timer = 60;
//   // loop to be executed every 0.5s
//   for (int i=dry_timer; i>=0; i--){
//     delay(500); 
//   }

//   // moving the stepper up and down
//   for (int i=0; i<3; i++){
//     moveFanStepperMotorDownSlow();
//     delay(1000*(i+1));
//     moveFanStepperMotorUp();
//   }  
//   moveFanStepperMotorDown();
//   // executeCupDryingMode();
  
//   Serial.println("Fan stepper move down ");
//   // moveFanStepperMotorDown();
  
// }


// End of drying phase
void executeEndDryingPhase() {
  Serial.println("STATE - End of Drying Process");
  // cup stop, fan stop
  cupServoStop();
  stopFans();
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
