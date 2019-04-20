int motorf= 9;
int motorb =10;
int ENA= 8;

//HIGH white
//LOW black

void setup()
{
  pinMode (6, INPUT);
  pinMode (7, INPUT);
  pinMode(motorf , OUTPUT );
  pinMode (motorb , OUTPUT);
  pinMode (ENA , OUTPUT);
}
  
  void loop()
  {
    int lsensorPin = digitalRead(6);
    int rsensorPin = digitalRead (7);
    
    if ((lsensorPin == HIGH) && (rsensorPin== HIGH))
    {
      digitalWrite ( ENA , HIGH);
      digitalWrite (motorf, LOW);
      digitalWrite (motorb, HIGH);
    }
    else
    {
      digitalWrite (ENA, LOW);
      digitalWrite (motorf, LOW);
      digitalWrite (motorb, LOW);
    }
  }
