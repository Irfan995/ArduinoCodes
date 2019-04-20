#define trigPin 2
#define echoPin 3
#define sensorPin1 A0
#define sensorPin2 A1
#define ledPin 13


void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  int distance, duration, val1, val2;
  digitalWrite(trigPin, HIGH);
  delay(50);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  val1 = analogRead(sensorPin1);
  val2 = analogRead(sensorPin2);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("\tValue_1: ");
  Serial.print(val1);
   Serial.print("\tValue_2: ");
  Serial.print(val2);
  Serial.println("");
  

  if(distance<30)
  {
    digitalWrite(ledPin, HIGH);
  }
  else if(val1<100 || val2<100)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  else if((val1<100 || val2<100) && distance<30)
  {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

}
