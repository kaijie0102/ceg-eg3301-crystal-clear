void setupSolenoidValve() {
  // Solenoid valve setup
  pinMode(VALVE1RELAYPIN, OUTPUT);
  pinMode(VALVE2RELAYPIN, OUTPUT);
  pinMode(VALVE3RELAYPIN, OUTPUT);
}

void openValve1() {
  digitalWrite(VALVE1RELAYPIN, HIGH);
}

void closeValve1() {
  digitalWrite(VALVE1RELAYPIN, LOW);
}

void openValve2() {
  digitalWrite(VALVE2RELAYPIN, HIGH);
}

void closeValve2() {
  digitalWrite(VALVE2RELAYPIN, LOW);
}

void openValve3() {
  digitalWrite(VALVE3RELAYPIN, HIGH);
}

void closeValve3() {
  digitalWrite(VALVE3RELAYPIN, LOW);
}
