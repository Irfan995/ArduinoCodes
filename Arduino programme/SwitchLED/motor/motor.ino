int motorPin = 9;
void setup() 
{
 pinMode (motorPin, OUTPUT); // put your setup code here, to run once:

}

void loop() 
{
  for (int i = 0; i<=255; i++)
  {
    analogWrite (motorPin, i);
    delay(10);
  }
  delay(100);
  for (int i=255; i>=0; i--)
  {
    analogWrite(motorPin, i);
    delay(10);
  }
  delay(100);
}
