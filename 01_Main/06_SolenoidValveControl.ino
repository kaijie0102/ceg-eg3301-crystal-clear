void setupSolenoidValve() {
  // Solenoid valve setup
  pinMode(VALVE1RELAYPIN, OUTPUT);
  pinMode(VALVE2RELAYPIN, OUTPUT);
  pinMode(VALVE3RELAYPIN, OUTPUT);
}

void openValve1() {
  digitalWrite(VALVE1RELAYPIN, HIGH);
  Serial.println("Valve 1 open");
}

void closeValve1() {
  digitalWrite(VALVE1RELAYPIN, LOW);
  Serial.println("Valve 1 close");
}

void openValve2() {
  digitalWrite(VALVE2RELAYPIN, HIGH);
  Serial.println("Valve 2 open");
}

void closeValve2() {
  digitalWrite(VALVE2RELAYPIN, LOW);
  Serial.println("Valve 2 close");
}

void openValve3() {
  digitalWrite(VALVE3RELAYPIN, HIGH);
  Serial.println("Valve 3 open");
}

void closeValve3() {
  digitalWrite(VALVE3RELAYPIN, LOW);
  Serial.println("Valve 3 close");
}
