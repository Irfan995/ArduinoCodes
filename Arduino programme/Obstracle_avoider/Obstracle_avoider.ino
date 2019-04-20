#define fmotorPin 5
#define bmotorPin 6
#define trigPin 11
#define echoPin 12
#define ena 7

void setup()
{
  Serial.begin(9600);
  pinMode(fmotorPin, OUTPUT);
  pinMode(bmotorPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(fmotorPin, LOW);
  digitalWrite(bmotorPin, LOW);
}

void loop() 
{
  
  int distance, duration;
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println("");

  if(distance < 10)
  {
    analogWrite(ena, 240);
    digitalWrite(fmotorPin, LOW);
    digitalWrite(bmotorPin, HIGH);
  }
  else
  {
    analogWrite(ena, 240);
    digitalWrite(fmotorPin, HIGH);
    digitalWrite(bmotorPin, LOW);
  }

}
