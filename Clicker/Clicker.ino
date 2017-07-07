int touch1 = 13;
int touch2 = 11;

void setup() {
  pinMode(touch1, OUTPUT);
  digitalWrite(touch1, LOW);
  
  pinMode(touch2, OUTPUT);
  digitalWrite(touch2, LOW);
}

void tap(int pin)
{
  digitalWrite(pin, HIGH);
  delay(50); // 50ms
  digitalWrite(pin, LOW);
}

void loop() {

  // TODO:  Put your tap pattern below.
  // For now we tap driver 1 three times, 0.5 seconds apart (+50ms for tap), then we tap drive 2 one time.
  // then the pattern repeats.
  
  tap(touch1);
  delay(500); // 0.5 seconds

  tap(touch1); 
  delay(500); // 0.5 seconds
  
  tap(touch1);
  delay(500); // 0.5 seconds
  
  tap(touch2);
  delay(500); // 0.5 seconds
}
