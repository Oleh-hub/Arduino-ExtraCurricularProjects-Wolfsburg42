/* the modes are switched only switche being pressed and hold all the time  */

int switchState;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT_PULLUP); // Enable internal pull-up resistor
  switchState = LOW;
}

void loop() {
  switchState = digitalRead(A0); // Read the state of the switch
  
  if (switchState == HIGH)
  {
    greenLightOn ();
  } 
  else if (switchState == LOW)
  { 
    yellowRedOneSecondInterval();
  }
}

void greenLightOn (void)
{
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
}

void yellowRedOneSecondInterval()
{
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay (1000);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay (1000);
}