const uint8_t MOTION_PIN = 2;

void setup()
{
  // Intialise IO
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOTION_PIN, INPUT);
  
  // Sense: Call onChange when motion is detected
  attachInterrupt(digitalPinToInterrupt(MOTION_PIN), onChange, CHANGE);
  
  Serial.begin(9600);
}

void loop()
{
}

void onChange()
{
  // Sense: Get current motion state
  uint8_t motionState = digitalRead(MOTION_PIN);
  
  Serial.print(motionState);
  Serial.println(""); 
  
  // Act: Match LED to motion state
  digitalWrite(LED_BUILTIN, motionState);
}