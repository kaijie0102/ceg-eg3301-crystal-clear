// Nano pin 0(Rx) - Mega Pin 43 (Tx)
// Nano pin 1(Tx) - Mega Pin 41 (Rx)

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
int ledState = 1;
unsigned long currentMillis;

int zeroCounter;

#define STANDBY 1
#define WASH 2
#define DRY 3
#define COMPLETE 4

// Time variables
unsigned long previousMillis = 0;
const long interval = 20; // Delay between updates (20ms for smoother effect)

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);   // Set brightness for red
  analogWrite(greenPin, green); // Set brightness for green
  analogWrite(bluePin, blue);  // Set brightness for blue
}

void ledStripStandby() {
  // do one full cycle before breaking   
  while(zeroCounter < 9) {
    // setColor(0,255,0); // purple
    // setColor(0,0,0); // white
    currentMillis = millis();
    
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Get a "ripple" pattern using sin() for smooth wave-like effect
      float brightnessFactor = (sin(currentMillis / 200.0) + 1) / 2; // Range from 0 to 1

      // Serial.println(brightnessFactor);
      if (String(brightnessFactor) == "0.00") {
        zeroCounter++;        
      }

      // Set each color to the same brightness to make a white ripple
      int brightness = brightnessFactor * 255;
      setColor(brightness,brightness,brightness); // white
    }
  }

  zeroCounter = 0; // reset zero counter
}

void ledStripWash() {
  // setColor(0,0,0); // white
  setColor(54, 20, 203); 
}

void ledStripDry() {
  // setColor(255, 255, 255); // dim
  setColor(0, 0, 0); // bluish
}

void ledStripComplete() {
  // setColor(255,0,255); // green
  // setColor(0,200,255); // purple
  setColor(0, 255, 0); // purple
  
}

void loop() {
  // while(1){
  // setColor(0, 0, 0); // bluish
  // // setColor(255, 0, 230); // green
  // }

  // Check if data is available on Serial
  if (Serial.available()) {
    String messageFromMega = Serial.readStringUntil('\n');
        
    Serial.print("Received from Arduino Mega: ");
    Serial.println(messageFromMega);
    ledState = messageFromMega.toInt();
    switch (ledState) {
      case STANDBY:
        Serial.println("In standby... pulsing");
        break;
      case WASH: 
        Serial.println("In washing mode");
        ledStripWash();
        break;
      case DRY:
        Serial.println("In drying mode");  
        ledStripDry();
        break;
      case COMPLETE:
        Serial.println("Finished! ");  
        ledStripComplete();
        break;
      default:
        // Code to execute if variable does not match any case
        setColor(0,255,255); // red
        break;
    }
    delay(500); // A short delay to avoid overwhelming the serial buffer

  }

  switch (ledState) {
    case STANDBY:
      ledStripStandby();
      break;
    case WASH: 
      ledStripWash();
      break;
    case DRY:
      ledStripDry();
      break;
    case COMPLETE:
      ledStripComplete();
      break;
    default:
      // Code to execute if variable does not match any case
      setColor(0,255,255); // red
      break;
  }
  

  //   // analogWrite(redPin, brightness);
  //   analogWrite(greenPin, brightness);
  //   // analogWrite(bluePin, brightness);

}


