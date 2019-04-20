void setup()
{
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop()
{ 
  analogWrite (9, 225);
  digitalWrite (10, HIGH);
  digitalWrite (11, LOW); 
  delay(2000);
  analogWrite (9, 240);
  digitalWrite (11, HIGH);
  digitalWrite (10, LOW); 
  delay(2000);
}
