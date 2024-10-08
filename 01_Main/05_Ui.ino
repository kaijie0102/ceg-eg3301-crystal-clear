// Set up variables
int buttonState = 1;        // Variable to hold the state of the button
int lastButtonState = 1;    // Variable to store the last button state  
const int debounceDelay = 50;  // Debouncing time in milliseconds
unsigned long lastDebounceTime = 0;  // Last time the button state changed

void setupUi() {
  // Button Setup
  pinMode(BUTTONPIN, INPUT_PULLUP);  // Enable the internal pull-up resistor for the button  
}

void readButtonInput() {
  Serial.println("Press Button to Start");

  // Wait until button is pressed and debounced
  while (true) {
    int reading = digitalRead(BUTTONPIN); // Active Low 

    // If the button state has changed (i.e., different from last read)
    if (reading != lastButtonState) { // if reading become 0
      lastDebounceTime = millis();  // Reset the debounce timer
    }

    // Check if enough time has passed since the state change
    if ((millis() - lastDebounceTime) > debounceDelay) {
      // Update the button state
      if (reading != buttonState) {
        buttonState = reading;

        // Button is pressed
        if (buttonState == LOW) {
          Serial.println("Button Pressed. Starting Clean Cycle");
          return;  // Exit the function once the button press is confirmed
        }
      }
    }

    lastButtonState = reading;  // Save the reading for the next loop
  }
  
}

