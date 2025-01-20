/* The idieal mandatory part: swithcing normaal when after pressing once. */

int switchState;
int previousSwitchState;
int currentMode = 0;

unsigned long previousMillis = 0; 
const long interval = 1000; 
bool isRedAndYellowOn = false;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT_PULLUP); // Enable internal pull-up resistor
  switchState = digitalRead(A0);
  previousSwitchState = switchState;
  
}

void loop() {
  switchState = digitalRead(A0);
  if (previousSwitchState == HIGH && switchState == LOW)
  {
    currentMode++;
    if (currentMode > 1)
      currentMode = 0;
  }
  
  if (currentMode == 0)
  {
    greenLightOn ();
  } 
  if (currentMode == 1)
  { 
    yellowRedOneSecondInterval();
  }
  previousSwitchState = switchState;
}

void greenLightOn (void)
{
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
}

void yellowRedOneSecondInterval()
{
  unsigned long currentMillis = millis(); // Get the current time

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    isRedAndYellowOn = !isRedAndYellowOn;
    if (isRedAndYellowOn)
    {
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH); // Yellow LED on
      digitalWrite(2, HIGH); // Red LED on
    }
    else
    {
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);  // Yellow LED off
      digitalWrite(2, LOW);  // Red LED off
    }
  }
}