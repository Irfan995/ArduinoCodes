#define trigPin 4
#define echoPin 2

#define inA 10
#define inB 9
#define inC 6
#define inD 5
#define ena 11
#define enb 3


void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  mot_init();
  delay(500);
  wheel(0, 0);
}

void loop() 
{
  int distance, duration;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println("");
  
  if (distance > 15)
  {
    wheel(40,-40);
  }
  else if(distance <5)
  {
    wheel(-40, 40);
  }
  else
  {
    wheel(70,70);
  }
}

void mot_init()
{
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  digitalWrite(inA, HIGH);
  digitalWrite(inB, HIGH);
  digitalWrite(inC, HIGH);
  digitalWrite(inD, HIGH);
}

void wheel(int lm, int rm)
{
  if (lm == 0)
  {
    digitalWrite(inC, HIGH);
    digitalWrite(inD, HIGH);
  }

  else if (lm > 0)
  {
    digitalWrite(inC, HIGH);
    digitalWrite(inD, LOW);
  }

  else if (lm < 0)
  {
    digitalWrite(inC, LOW);
    digitalWrite(inD, HIGH);
  }



  if (rm == 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, HIGH);
  }

  else if (rm > 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
  }

  else if (rm < 0)
  {
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
  }

  if (lm > 254) lm = 254;
  if (lm < -254) lm = -254;
  if (rm > 254) rm = 254;
  if (rm < -254) rm = -254;

  analogWrite(ena, abs(rm));
  analogWrite(enb, abs(lm));

}


