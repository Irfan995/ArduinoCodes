int r1 = 13; // relay ch 1
int r2 = 14;// relay ch 1
int rc = 8; //RC pin
int x = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(rc, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  x = pulseIn(rc);
  if (x >= 1500) {
    digitalWrite(r1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(r2, HIGH);
  }// turn the LED off by making the voltage LOW
  else {
    digitalWrite(r1, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(r2, LOW);
  }
}
