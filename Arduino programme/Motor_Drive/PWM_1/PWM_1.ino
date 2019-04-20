void setup() 
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

}

void loop()
{
  int i;
  for (i=0; i<=200; i++)
  {
  analogWrite(5, 100);
  analogWrite(6, 0);
  
  }
  for (i=200; i>=0; i++)
  {
  analogWrite(5, 0);
  analogWrite(6, 200);
  
  }
}
