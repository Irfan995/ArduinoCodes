#define inA 10
#define inB 9
#define inC 6
#define inD 5
#define ena 11
#define enb 3

int th[5];

int i, sen_1[5], sen_2[5], s[5];

;

void setup()
{
  mot_init();
 
  delay(300);

  wheel(0, 0);
  }

void loop() 
{


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

void wheel(int rm, int lm)
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


int readSensor()
{
  for (i = 0; i < 5; i++)
  {
    sen[i] = analogRead(i); 
  }
}
int calSensor()
{  
  for (i = 0; i < 5; i++)
  {
    sen[i]=th[i];
  }
    
  
}
