// Wash Setup
void executeState1() {
    Serial.println("STATE 1a - Await Button Press");
    readButtonInput();
  
    Serial.println("STATE 1b - Wash Cycle Setup");
        
    Serial.println("h stepper backwards");
    moveRailStepperMotorBackwards();

}


// Wash 
void executeState2() {
    Serial.println("STATE 2a - First wash cycle");
    Serial.println("Solenoid open");
    
    
    Serial.println("Servo start spinning");
    cupServoStart();
    delay(3000);
    cupServoStop();
  
    Serial.println("Solenoid close");
    

    Serial.println("STATE 2b - Second wash cycle");
    

    Serial.println("STATE 2c - Third wash cycle");
    
}

// Dry Setup
void executeState3() {
    Serial.println("STATE 3 - Drying Cycle Setup");
  
    // step one revolution in the other direction:
    Serial.println("Move rail stepper to drying compartment");
    moveRailStepperMotorForward();
    delay(3000);
  
    
  
    Serial.println("Fan stepper move up");
    moveFanStepperMotorUp();
    delay(3000); 
  
}

//Dry
void executeState4() {
    Serial.println("STATE 3a - Drying Process");

    Serial.println("Fan ON");
    startInternalFans();

    Serial.println("Cup servo to rotate");
    cupServoStart();
    delay(3000);
    // cup stop, fan stop
    stopInternalFans();
    Serial.println("Fan OFF");
    cupServoStop();
    
    Serial.println("Fan stepper move down ");
    moveFanStepperMotorDown();
    // delay(3000); 
    // Additional code here

    Serial.println("STATE 3b - End of Drying Process");
    Serial.print("State Number: ");
    Serial.println(currentState);
  
}
