void setupSolenoidValve() {
  // Solenoid valve setup
  pinMode(VALVE_1_PIN, OUTPUT);
  pinMode(VALVE_2_PIN, OUTPUT);
  pinMode(VALVE_3_PIN, OUTPUT);
  pinMode(WATER_PUMP_PIN, OUTPUT);
}

void openValve1() {
  digitalWrite(VALVE_1_PIN, HIGH);
  Serial.println("Valve 1 open");
}

void closeValve1() {
  digitalWrite(VALVE_1_PIN, LOW);
  Serial.println("Valve 1 close");
}

void openValve2() {
  digitalWrite(VALVE_2_PIN, HIGH);
  Serial.println("Valve 2 open");
}

void closeValve2() {
  digitalWrite(VALVE_2_PIN, LOW);
  Serial.println("Valve 2 close");
}

void openValve3() {
  digitalWrite(VALVE_3_PIN, HIGH);
  Serial.println("Valve 3 open");
}

void closeValve3() {
  digitalWrite(VALVE_3_PIN, LOW);
  Serial.println("Valve 3 close");
}

void onInnerPump() {
  digitalWrite(WATER_PUMP_PIN, HIGH);
  Serial.println("Water Pump Open");
  delay(3000);
}

void offInnerPump() {
  digitalWrite(WATER_PUMP_PIN, LOW);
  Serial.println("Water Pump Off");
  delay(3000);
}
