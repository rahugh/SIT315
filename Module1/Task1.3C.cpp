// Define pins
const uint8_t MOTION_PIN = 2;
const uint8_t BUTTON_PIN = 3;
const uint8_t BLUELED_PIN = 12;

void setup()
{
  // Intialise IO
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BLUELED_PIN, OUTPUT);
  pinMode(MOTION_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT);

  // Call onMotion when motion is detected
  attachInterrupt(digitalPinToInterrupt(MOTION_PIN), onMotion, CHANGE);

  // Call onButton when the button is pressed
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButton, CHANGE);

  Serial.begin(9600);
}

void loop()
{
}

void onMotion()
{
  // Get current motion state
  uint8_t motionState = digitalRead(MOTION_PIN);

  Serial.print("MOTION: ");
  Serial.print(motionState);
  Serial.println("");

  // Toggle built-in LED
  digitalWrite(LED_BUILTIN, motionState);
}

void onButton()
{
  // Get button state
  uint8_t buttonState = digitalRead(BUTTON_PIN);

  Serial.print("BUTTON: ");
  Serial.print(buttonState);
  Serial.println("");

  // Toggle blue LED
  digitalWrite(BLUELED_PIN, buttonState);
}