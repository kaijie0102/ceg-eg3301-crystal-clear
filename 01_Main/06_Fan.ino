const int INTERNAL_FAN_ON_TIME = 3000;

void startInternalFans() {
  digitalWrite(FANRELAYPIN, HIGH);
  digitalWrite(FAN2RELAYPIN, HIGH);
  // delay(INTERNAL_FAN_ON_TIME);
}

void stopInternalFans() {
  digitalWrite(FANRELAYPIN, LOW);
  digitalWrite(FAN2RELAYPIN, LOW);
}

