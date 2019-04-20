#define dirPin 4
#define speedPin 5

void setup()
{
  mot_init();
  delay(200);
  wheel(0);
}

void loop()
{
  wheel(180);
  delay(1000);
  wheel(-180);
  delay(1000);
}

void mot_init()
{
  pinMode(dirPin,OUTPUT);  
  pinMode(speedPin, OUTPUT);
}
void wheel(int sp)
{
  analogWrite(speedPin,sp);

  if (sp < 0) digitalWrite(dirPin,LOW);
  if (sp >= 0) digitalWrite(dirPin,HIGH);

  if (sp > 254) sp = 250;
  if (sp < -254) sp = -250;
}

