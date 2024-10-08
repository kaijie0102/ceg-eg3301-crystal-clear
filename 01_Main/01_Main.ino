// Import libraries
#include <Stepper.h>
#include <Servo.h>

// Define Arduino Pins
#define BUTTONPIN 2;    // Pin where the push button is connected
#define CUPSERVOPIN = 3; // continuous servo motor
#define FANRELAYPIN = 22; // relay for fan

#define RAIL_ENA_PIN1 = 36; // enable pins for rail stepper motor
#define RAIL_ENA_PIN2 = 37;
#define RAIL_ENB_PIN1 = 34;
#define RAIL_ENB_PIN2 = 35;

#define FAN_ENA_PIN1 = 32; // enable pins for fan stepper motor
#define FAN_ENA_PIN2 = 33;
#define FAN_ENB_PIN1 = 30;
#define FAN_ENB_PIN2 = 31;

// Define 15 states for the finite state machine
enum State {
  STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, STATE_6, STATE_7, STATE_8,
  STATE_9, STATE_10, STATE_11, STATE_12, STATE_13, STATE_14, STATE_15
};

// 02_PowerControl
void setupRelay();

// 03_StepperMotorControl
void setupRailStepperMotor();
void setupFanStepperMotor();
void moveRailStepperMotorBackwards();
void moveRailStepperMotorForward();
void moveFanStepperMotorUp();
void moveFanStepperMotorDown();
Stepper railStepper(stepsPerRevolution, 4, 6, 5, 7); // Create Instance of Stepper library
Stepper fanStepper(stepsPerRevolution, 8, 9, 10, 11); // Create Instance of Stepper library

// 03_ServoMotorControl
Servo cupServo;  // create continuous servo object
unsigned long timer; 
static const unsigned long timeout = 7500; // loop ends after specified duration
int servoCounter = 0;  

// 05_Ui
void setupUi();
void readButtonInput();
int buttonState = 0;        // Variable to hold the state of the button
int lastButtonState = 0;    // Variable to store the last button state  
const int debounceDelay = 50;  // Debouncing time in milliseconds
unsigned long lastDebounceTime = 0;  // Last time the button state changed

// 06_Fan

void setup() {

  setupRelay();
  setupRailStepperMotor();
  setupFanStepperMotor();
  setupServoMotor();
  setupUi(); 
  
  // Initialize the serial port:
  Serial.begin(9600);

}

void loop() {
  readButtonInput();
  // buttonState = digitalRead(BUTTONPIN); // Read the current state of the button (LOW when pressed, HIGH when not pressed)
    
  // // Check if the button state has changed (button press detected)
  // if (buttonState != lastButtonState) {
  //   if (buttonState == LOW) {
  //     buttonState = 0;
  //     // Button is pressed
  //     Serial.println("Button Pressed");

  // Move to wash compartment. step one revolution in one direction:
  Serial.println("h stepper backwards");
  moveRailStepperMotorBackwards();
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
  Serial.println("h stepper forward");
  moveRailStepperMotorForward();
  delay(3000);

  

  Serial.println("v stepper up ");
  moveFanStepperMotorUp();
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
  moveFanStepperMotorDown();
  delay(3000); 

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
