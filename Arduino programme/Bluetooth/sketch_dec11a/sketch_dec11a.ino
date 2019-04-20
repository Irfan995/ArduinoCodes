int fmotorPin = 5;
int bmotorPin = 6;
int enaPin = 3;
int state = 0;
int flag = 0;

void setup()
{
  pinMode (fmotorPin, OUTPUT);
  pinMode (bmotorPin, OUTPUT);
  pinMode(enaPin, OUTPUT);
  analogWrite (enaPin, 250);
  digitalWrite (fmotorPin, LOW);
  digitalWrite (bmotorPin, LOW);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0)
  {
    state = Serial.read();
    flag = 0;
  }
  if(state == '0')
  {
    digitalWrite (fmotorPin, HIGH);
    digitalWrite(bmotorPin, LOW);
    if(flag == 0)
    {
      Serial.println("Forward");
    flag = 1;
    }
  }
  if(state == '1')
  {
    digitalWrite (fmotorPin, LOW);
    digitalWrite(bmotorPin, HIGH);
    if(flag == 0)
    {Serial.println("Backward");
    flag = 1;
    }
  }
}

