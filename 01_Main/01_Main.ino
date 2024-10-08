// Import libraries
#include <Stepper.h>
#include <Servo.h>

// Define Arduino Pins
#define BUTTONPIN 2    // Pin where the push button is connected
#define CUPSERVOPIN 3 // continuous servo motor
#define FANRELAYPIN 22 // relay for fan

// Define 15 states for the finite state machine
enum State {
  STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, STATE_6, STATE_7, STATE_8,
  STATE_9, STATE_10, STATE_11, STATE_12, STATE_13, STATE_14, STATE_15
};  
State currentState = STATE_1;

// 02_PowerControl
void setupRelay();

// 03_StepperMotorControl
void setupStepperMotor();
const int totalRevolutionsForMovement = 5; // Modify to increase duration of stepper movement
const int stepsPerRevolution = 200; // Do not modify. Number of steps per output rotation
Stepper railStepper(stepsPerRevolution, 4, 6, 5, 7); // Create Instance of Stepper library
Stepper fanStepper(stepsPerRevolution, 8, 9, 10, 11); // Create Instance of Stepper library

// 03_ServoMotorControl
void setupServoMotor();
Servo cupServo;  // create continuous servo object
unsigned long timer; 
static const unsigned long timeout = 7500; // loop ends after specified duration
int servoCounter = 0;  

// 05_Ui
void setupUi();
void readButtonInput();
int buttonReading = 1;      // Reading of button
int buttonState = 1;        // Variable to hold the state of the button
int lastButtonState = 1;    // Variable to store the last button state  
const int debounceDelay = 50;  // Debouncing time in milliseconds
unsigned long lastDebounceTime = 0;  // Last time the button state changed

// 06_Fan

void setup() {

  setupRelay();
  setupStepperMotor();
  setupServoMotor();
  setupUi(); 
  
  // Initialize the serial port:
  Serial.begin(9600);

  Serial.println("Set up complete");

}

void loop() {
  // Handle the current state
  handleState();
  // readButtonInput();
  // buttonState = digitalRead(BUTTONPIN); // Read the current state of the button (LOW when pressed, HIGH when not pressed)
    
  // // Check if the button state has changed (button press detected)
  // if (buttonState != lastButtonState) {
  //   if (buttonState == LOW) {
  //     buttonState = 0;
  //     // Button is pressed
  //     Serial.println("Button Pressed");

  // Move to wash compartment. step one revolution in one direction:
  
}

// Function to handle the logic for each state
void handleState() {
  switch (currentState) {
    case STATE_1:
      // Handle logic for STATE_1
      Serial.println("State 1 - Await Button Press");
  
      readButtonInput();
      // digitalWrite(ledPin, LOW);
      break;
    case STATE_2:
      // Handle logic for STATE_2
      Serial.println("State 2 - Wash Cycle Setup");
      
      Serial.println("h stepper right");
      railStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
      // delay(3000);

      Serial.println("Servo start spinning");
      timer = millis();
      // while ((millis()-timer) < timeout) {
      //   // Serial.println(servoCounter);
      //   cupServo.write(60);
      // }
      cupServo.write(90);
      
      // digitalWrite(ledPin, HIGH);
      break;
    case STATE_3:
      Serial.println("State 3 - Start Wash");
      delay(3000); // washing starts
    
      // Additional code here
      break;
    case STATE_4:
      Serial.println("State 4 - Drying Cycle Setup");

      // step one revolution in the other direction:
      Serial.println("h stepper left");
      railStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
      delay(3000);

      

      Serial.println("v stepper up ");
      fanStepper.step(-stepsPerRevolution * totalRevolutionsForMovement);
      delay(3000); 

      Serial.println("Servo start spinning");
      timer = millis();
      // while ((millis()-timer) < timeout) {
      //   // Serial.println(servoCounter);
      //   cupServo.write(60);
      // }
      
     

      Serial.println("v stepper down ");
      fanStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
      // delay(3000); 
      // Additional code here
      
      break;
    // Add more cases for STATE_5 to STATE_15
    case STATE_5:
      Serial.println("State 5 - Drying Cycle");
      // fan start
      Serial.println("Fan ON");
      digitalWrite(FANRELAYPIN, HIGH);
      // delay(5000); // fan blows for 5 seconds

      cupServo.write(90);


      // cup stop, fan stop
      digitalWrite(FANRELAYPIN, LOW);
      Serial.println("Fan OFF");
      Serial.print("State Number: ");
      Serial.println(currentState);
      // Handle logic for STATE_15
      // Additional code here
      currentState = STATE_15;  // Reset to initial state
      break;
    case STATE_6:
      // Handle logic for STATE_15
      // Additional code here
      currentState = STATE_15;  // Reset to initial state
      break;
    case STATE_7:
      // Handle logic for STATE_15
      // Additional code here
      currentState = STATE_15;  // Reset to initial state
      break;
    case STATE_15:
      // Handle logic for STATE_15
      // Additional code here
      currentState = STATE_15;  // Reset to initial state
      break;
    default:
      // Handle unknown state
      currentState = STATE_15;  // Reset to initial state
      break;
  }
  changeState();
}

// Function to change the state
void changeState() {
  // Cycle through states: STATE_1 -> STATE_2 -> STATE_3 -> ... -> STATE_15 -> STATE_1
  switch (currentState) {
    case STATE_1:
      currentState = STATE_2;
      break;
    case STATE_2:
      currentState = STATE_3;
      break;
    case STATE_3:
      currentState = STATE_4;
      break;
    case STATE_4:
      currentState = STATE_5;
      break;
    case STATE_5:
      currentState = STATE_6;
      break;
    case STATE_6:
      currentState = STATE_7;
      break;
    case STATE_7:
      currentState = STATE_8;
      break;
    case STATE_8:
      currentState = STATE_9;
      break;
    case STATE_9:
      currentState = STATE_10;
      break;
    case STATE_10:
      currentState = STATE_11;
      break;
    case STATE_11:
      currentState = STATE_12;
      break;
    case STATE_12:
      currentState = STATE_13;
      break;
    case STATE_13:
      currentState = STATE_14;
      break;
    case STATE_14:
      currentState = STATE_15;
      break;
    case STATE_15:
      currentState = STATE_1;
      break;
  }
}



  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*

  void loop() 
  {
    buttonState = digitalRead(BUTTONPIN); // Read the current state of the button (LOW when pressed, HIGH when not pressed)
    
    // Check if the button state has changed (button press detected)
    if (buttonState != lastButtonState) {
      if (buttonState == LOW) {
        buttonState = 0;
        // Button is pressed
        Serial.println("Button Pressed");

        // Move to wash compartment. step one revolution in one direction:
        Serial.println("h stepper right");
        railStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
        delay(3000);

        Serial.println("Servo start spinning");
        timer = millis();
        while ((millis()-timer) < timeout) {
          // Serial.println(servoCounter);
          cupServo.write(60);
        }
        cupServo.write(90);
        delay(3000); // washing starts


        // step one revolution in the other direction:
        Serial.println("h stepper left");
        railStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
        delay(3000);

        
      
        Serial.println("v stepper up ");
        fanStepper.step(-stepsPerRevolution * totalRevolutionsForMovement);
        delay(3000); 

        Serial.println("Servo start spinning");
        timer = millis();
        while ((millis()-timer) < timeout) {
          // Serial.println(servoCounter);
          cupServo.write(60);
        }
        
        cupServo.write(90);
        delay(3000); // washing starts

        // fan start
        digitalWrite(FANRELAYPIN, HIGH);
        delay(5000); // fan blows for 5 seconds

        // cup stop, fan stop
        digitalWrite(FANRELAYPIN, LOW);

        Serial.println("v stepper down ");
        fanStepper.step(stepsPerRevolution * totalRevolutionsForMovement);
        delay(3000); 

      } else {
        Serial.println("Button Not Pressed");
      }
      // Small delay to debounce the button
      delay(50);
    }

    // Save the current button state as the last state for the next iteration
    lastButtonState = buttonState;
  }
*/

/*
// Pin definitions
const int buttonPin = 7;  // Button input
const int ledPin = 13;    // LED output

// Define 15 states for the finite state machine
enum State {
  STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, STATE_6, STATE_7, STATE_8,
  STATE_9, STATE_10, STATE_11, STATE_12, STATE_13, STATE_14, STATE_15
};

// Initial state
State currentState = STATE_1;

// Variables for button press
int buttonState = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;  // Debounce delay for button

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Initially turn off the LED
}

void loop() {
  // Read the button state
  int reading = digitalRead(buttonPin);

  // Debounce the button input
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      // If the button is pressed, change state
      if (buttonState == HIGH) {
        changeState();
      }
    }
  }

  lastButtonState = reading;

  // Handle the current state
  handleState();
}

// Function to handle the logic for each state
void handleState() {
  switch (currentState) {
    case STATE_1:
      // Handle logic for STATE_1
      digitalWrite(ledPin, LOW);
      break;
    case STATE_2:
      // Handle logic for STATE_2
      digitalWrite(ledPin, HIGH);
      break;
    case STATE_3:
      // Handle logic for STATE_3
      // Additional code here
      break;
    case STATE_4:
      // Handle logic for STATE_4
      // Additional code here
      break;
    // Add more cases for STATE_5 to STATE_15
    case STATE_15:
      // Handle logic for STATE_15
      // Additional code here
      break;
    default:
      // Handle unknown state
      currentState = STATE_1;  // Reset to initial state
      break;
  }
}

// Function to change the state
void changeState() {
  // Cycle through states: STATE_1 -> STATE_2 -> STATE_3 -> ... -> STATE_15 -> STATE_1
  switch (currentState) {
    case STATE_1:
      currentState = STATE_2;
      break;
    case STATE_2:
      currentState = STATE_3;
      break;
    case STATE_3:
      currentState = STATE_4;
      break;
    case STATE_4:
      currentState = STATE_5;
      break;
    case STATE_5:
      currentState = STATE_6;
      break;
    case STATE_6:
      currentState = STATE_7;
      break;
    case STATE_7:
      currentState = STATE_8;
      break;
    case STATE_8:
      currentState = STATE_9;
      break;
    case STATE_9:
      currentState = STATE_10;
      break;
    case STATE_10:
      currentState = STATE_11;
      break;
    case STATE_11:
      currentState = STATE_12;
      break;
    case STATE_12:
      currentState = STATE_13;
      break;
    case STATE_13:
      currentState = STATE_14;
      break;
    case STATE_14:
      currentState = STATE_15;
      break;
    case STATE_15:
      currentState = STATE_1;
      break;
  }
}


*/