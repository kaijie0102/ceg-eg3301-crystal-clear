void setupUi() {
  // Button Setup
  pinMode(BUTTONPIN, INPUT_PULLUP);  // Enable the internal pull-up resistor for the button  
}

void readButtonInput() {
  Serial.println("Press Button to Start");
  // Wait until button is pressed and debounced
  Serial.print("Button state ");
  Serial.println(buttonState);

  Serial.print("Last Button state ");
  Serial.println(lastButtonState);
  while (true) {
    int reading = digitalRead(BUTTONPIN); // Active Low 

    // If the button state has changed (i.e., different from last read)
    if (reading != lastButtonState) {
      lastDebounceTime = millis();  // Reset the debounce timer
    }

    // Check if enough time has passed since the state change
    if ((millis() - lastDebounceTime) > debounceDelay) {
      // Update the button state
      if (reading != buttonState) {
        buttonState = reading;

        // Button is pressed
        if (buttonState == LOW) {
          Serial.println("Starting Clean Cycle");
          return;  // Exit the function once the button press is confirmed
        }
      }
    }

    lastButtonState = reading;  // Save the reading for the next loop
  }
    /*
  // Check if the button state has changed (button press detected)
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      buttonState = 0;
      // Button is pressed
      Serial.println("Button Pressed");
    }

    // Save the current button state as the last state for the next iteration
    lastButtonState = buttonState;
  }

  // tempalte debouncing
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
  */
}

