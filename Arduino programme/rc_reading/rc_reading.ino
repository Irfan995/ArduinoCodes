#define ch1 2
#define ch2 3
#define ch3 4
#define ch4 5
#define ch5 6
#define ch6 7
#define lf 8
#define lb 7
#define rf 12
#define rb 11
#define ena 9
#define enb 10

void setup() {
  pinMode(lf,OUTPUT);
  pinMode(lb,OUTPUT);
  pinMode(rf,OUTPUT);
  pinMode(rb,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  pinMode(ch3,INPUT);
  pinMode(ch4,INPUT);
  pinMode(ch5,INPUT);
  pinMode(ch6,INPUT);

  analogWrite(ena,0);
  analogWrite(enb,0);
  digitalWrite(lf,HIGH);
  digitalWrite(lb,HIGH);
  digitalWrite(rf,HIGH);
  digitalWrite(rb,HIGH);
  
  Serial.begin(9600);
}

void loop() {
  int a,b,c,d,e,f;
  a=pulseIn(ch1, HIGH);
  b=pulseIn(ch2, HIGH);
  c=pulseIn(ch3, HIGH);
  d=pulseIn(ch4, HIGH);
  e=pulseIn(ch5, HIGH);
  f=pulseIn(ch6, HIGH);

   if(b<1260)
  {
    analogWrite(ena,map(c,1156,2008,0,255));
    analogWrite(enb,map(c,1156,2008,0,255));
    forward();
  }
  else if(b>1700)
  {
    analogWrite(ena,map(c,1156,2008,0,255));
    analogWrite(enb,map(c,1156,2008,0,255));
    backward();
  }
  else if(d<1250)
  {
    analogWrite(ena,map(c,1156,2008,0,255));
    analogWrite(enb,map(c,1156,2008,0,255));
    left();
  }
  else if(d>1680)
  {
    analogWrite(ena,map(c,1156,2008,0,255));
    analogWrite(enb,map(c,1156,2008,0,255));
    right();
  }
  else
  {
    analogWrite(ena,map(c,1156,2008,0,255));
    analogWrite(enb,map(c,1156,2008,0,255));
    stp();
  }

  

}


void forward()
{
  digitalWrite(lf,HIGH);
  digitalWrite(lb,LOW);
  digitalWrite(rf,HIGH);
  digitalWrite(rb,LOW);
}

void backward()
{
  digitalWrite(lf,LOW);
  digitalWrite(lb,HIGH);
  digitalWrite(rf,LOW);
  digitalWrite(rb,HIGH);
}

void left()
{
  digitalWrite(lf,LOW);
  digitalWrite(lb,HIGH);
  digitalWrite(rf,HIGH);
  digitalWrite(rb,LOW);
}

void right()
{
  digitalWrite(lf,HIGH);
  digitalWrite(lb,LOW);
  digitalWrite(rf,LOW);
  digitalWrite(rb,HIGH);
}

void stp()
{
  digitalWrite(lf,LOW);
  digitalWrite(lb,LOW);
  digitalWrite(rf,LOW);
  digitalWrite(rb,LOW);
}
