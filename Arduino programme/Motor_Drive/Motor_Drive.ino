#define rf 4
#define rb 5
#define ena 3

void setup() 
{
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(ena, OUTPUT);

  analogWrite(ena, 200);

  
  
}

void loop() 
{
  digitalWrite(rf, HIGH);
  digitalWrite(rb, LOW);

  delay(1000);

  digitalWrite(rf, LOW);
  digitalWrite(rb, HIGH);

  delay(1000);
}
