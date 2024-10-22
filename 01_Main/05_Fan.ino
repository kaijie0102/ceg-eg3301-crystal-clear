const int INTERNAL_FAN_ON_TIME = 3000;

void setupFanRelay() {
  // Relays setup 
  pinMode(INNERFANRELAYPIN, OUTPUT);
  pinMode(INNERFAN2RELAYPIN, OUTPUT);
  pinMode(OUTERFANRELAYPIN, OUTPUT);
  pinMode(OUTERFAN2RELAYPIN, OUTPUT);
}

void startInternalFans() {
  // digitalWrite(INNERFANRELAYPIN, HIGH);
  digitalWrite(INNERFAN2RELAYPIN, HIGH);
  // digitalWrite(OUTERFANRELAYPIN, HIGH);
  digitalWrite(OUTERFAN2RELAYPIN, HIGH);
}

void stopInternalFans() {
  digitalWrite(INNERFANRELAYPIN, LOW);
  digitalWrite(INNERFAN2RELAYPIN, LOW);
} 

