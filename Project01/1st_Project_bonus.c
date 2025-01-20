/* project with bonus part */

int switchState;
int previousSwitchState;
int currentMode = 0;

unsigned long previousMillis = 0;
unsigned long previousMillis_Yellow = 0;
const long interval = 1000; 
bool isRedAndYellowOn = false;
bool redOnYellowOff = true;

bool yellowTwoSecInterval = true;
bool redHalfSecInterval = true;

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
    if (currentMode > 3)
      currentMode = 0;
  }
  
  if (currentMode == 0)
  {
    greenLightOn ();
  } 
  else if (currentMode == 1)
  { 
    yellowRedOneSecondInterval();
  }
  else if (currentMode == 2)
  { 
    redYellowAlternate();
  }
  else if (currentMode == 3)
  {
    redHalfSecYellowTwoSec();
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

void redYellowAlternate()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 2 * interval)
  {
    previousMillis = currentMillis;
    redOnYellowOff = !redOnYellowOff;
    if (redOnYellowOff)
    {
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);
    }
    else
    {
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH); 
      digitalWrite(2, LOW);  
    }
  }
}

void redHalfSecYellowTwoSec (void)
{

  digitalWrite(4, LOW);
  unsigned long currentMillis = millis();
  unsigned long currentMillis_Yellow = millis();
  
  if (currentMillis_Yellow - previousMillis_Yellow >= 2 * interval)
  {
    previousMillis_Yellow = currentMillis_Yellow;
    yellowTwoSecInterval = !yellowTwoSecInterval;
    if (yellowTwoSecInterval)
    {
      digitalWrite(2, HIGH);
    }
    else
    {
      digitalWrite(2, LOW);
    }
  }
  if ((currentMillis - previousMillis) >= interval / 2)
  {
    previousMillis = currentMillis;
    redHalfSecInterval = !redHalfSecInterval;
    if (redHalfSecInterval)
    {
      digitalWrite(3, HIGH);
    }
    else
    {
      digitalWrite(3, LOW);  // Red LED on
    }
  }

}