////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Execute States in Sequence //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void executeState1() {
    Serial.println("STATE 1 - setup washing phase");
    executeInitialisation();
    executeMoveToWashingCompartment();
}

void executeState2() {
    Serial.println("STATE 2 - washing phase");
    // washing cycle 1
    executeWashingCycle();
    executeWaterRegeneration();
  
    // washing cycle 2
    executeWashingCycle();
    executeWaterRegeneration();

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
}


// Washing Cycle 1 
void executeWashingCycle() {
    Serial.println("STATE - First wash cycle");
    Serial.println("Valve 1 open");
    openValve1();
    delay(3000);
    
    Serial.println("Valve 1 close");
    closeValve1();

    Serial.println("Valve 2 open");
    openValve2();
    delay(3000);
    
    Serial.println("Servo start spinning");
    cupServoStart();
    delay(3000);

    Serial.println("Water pump on");
    // TODO
}

// Water Regeneration 
void executeWaterRegeneration() {
    Serial.println("STATE - Water Regeneration");
    Serial.println("Cup servo stop spinning");
    cupServoStop();

    Serial.println("Valve 2 close");
    closeValve2();
    delay(3000);

    Serial.println("Valve 3 open");
    openValve3();
    delay(3000);

    Serial.println("Valve 1 open");
    openValve1();
    delay(3000);

    Serial.println("Valve 1 close");
    closeValve1();
}

// End wash cycle
void executeEndWashingCycle() {
  Serial.println("STATE - End Washing Cycle");
  Serial.println("Water Pump off");
  // TODO
  
  Serial.println("Cup servo actuator off");
  cupServoStop();
}

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
    moveFanStepperMotorUp();
    delay(3000); 
  
    Serial.println("Cup Servo start spinning");
    cupServoStart();
    delay(3000);
}



// Drying 
void executeDryingPhase() {
    Serial.println("STATE - Drying Phase");
    

    Serial.println("Fan ON");
    digitalWrite(FANRELAYPIN, HIGH);
    // delay(5000); // fan blows for 5 seconds

    Serial.println("Cup servo to rotate");
    cupServoStart();
    delay(3000);
    //cupServo.write(90);
    
    Serial.println("Fan stepper move down ");
    moveFanStepperMotorDown();
    delay(3000); 
    // Additional code here
}


// End of drying phase
void executeEndDryingPhase() {
    Serial.println("STATE - End of Drying Process");
    // cup stop, fan stop
    digitalWrite(FANRELAYPIN, LOW);
    Serial.println("Fan OFF");
    Serial.print("State Number: ");
    Serial.println(currentState);
}
