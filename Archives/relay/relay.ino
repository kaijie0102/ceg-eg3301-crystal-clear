//////// WIRING /////////////
// red to 5v pin ////////////
// black to ground //////////
// yellow to digital 7 pin //
/////////////////////////////

/////////////// TEST ////////////////////
// when on, LED will light up on relay //
// when off, LED will be off on relay  //
/////////////////////////////////////////

void setup()
{
  pinMode(7, OUTPUT);
}

void loop()
{
  // digitalWrite(7, HIGH);
  // delay(1000); // on for 1 second
  digitalWrite(7, LOW);
  delay(5000); // off for 5 seconds

}