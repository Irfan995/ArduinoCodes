#define lmotorf 8 
#define lmotorb 9
#define rmotorf 10
#define rmotorb 11
#define ENA 5
#define ENB 3

void setup() 
{
  pinMode(lmotorf,OUTPUT);
  pinMode(rmotorf,OUTPUT);
  pinMode(lmotorb,OUTPUT);
  pinMode(rmotorb,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
}

void loop() 
{
  digitalWrite (lmotorf, LOW);
  digitalWrite (lmotorb, LOW);
  digitalWrite (rmotorf, LOW);
  digitalWrite (rmotorb, LOW);
  
  int lsensor=digitalRead(6);
int rsensor=digitalRead(7);
if((lsensor==HIGH)&&(rsensor==HIGH))
{
//both sensors on white
// go forward
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((lsensor==HIGH)&& (rsensor==LOW))
{
//right sensor on black line
// turn right
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,HIGH);
}
else if((lsensor==LOW)&&(rsensor==HIGH))
{
//left sensor on black line
// turn left
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,HIGH);
digitalWrite(rmotorb,LOW);
}
else
{
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
}
