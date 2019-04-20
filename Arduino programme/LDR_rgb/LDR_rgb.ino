#define redPin 5
#define bluePin 3
#define greenPin 6


void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
Serial.begin(9600);
}

void loop() {
  int x=0;
  x=analogRead(A0);
  Serial.println(x);
  delay(50);

  if (x>400 && x<800)
  {
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, LOW);
  }
  else if (x<400)
  {
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  }

  else
  {
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, LOW);
  }
}
