const int INTERNAL_FAN_ON_TIME = 3000;

void setupFanRelay() {
  // Inner fans relay set up
  pinMode(L_INNER_FAN_PIN, OUTPUT);
  pinMode(R_INNER_FAN_PIN, OUTPUT);

  // Outer fans relay set up
  pinMode(L_OUTER_FAN_PIN, OUTPUT);
  pinMode(R_OUTER_FAN_PIN, OUTPUT);
}

void startInnerFans() {
  digitalWrite(L_INNER_FAN_PIN, HIGH);
  digitalWrite(R_INNER_FAN_PIN, HIGH); 
}

void stopInnerFans() {
  digitalWrite(L_INNER_FAN_PIN, LOW);
  digitalWrite(R_INNER_FAN_PIN, LOW); 
}

void startOuterFans() {
  digitalWrite(L_OUTER_FAN_PIN, HIGH);
  digitalWrite(R_OUTER_FAN_PIN, HIGH);
}

void stopOuterFans() {
  digitalWrite(L_OUTER_FAN_PIN, LOW);
  digitalWrite(R_OUTER_FAN_PIN, LOW); 
}
