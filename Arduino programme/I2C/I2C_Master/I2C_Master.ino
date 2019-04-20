//i2c Master Code

#include<Wire.h>
#define ch2 2
#define ch3 3
#define ch4 4
#define ch5 5
#define ch6 6
#define lf 8
#define lb 7
#define rf 12
#define rb 11
#define enL 9
#define enR 10

void setup() 
{
  pinMode(ch2,INPUT);
  pinMode(ch3,INPUT);
  pinMode(ch4,INPUT);
  pinMode(ch5,INPUT);
  pinMode(ch6,INPUT);

  pinMode(lf,OUTPUT);
  pinMode(lb,OUTPUT);
  pinMode(rf,OUTPUT);
  pinMode(rb,OUTPUT);
  pinMode(enL,OUTPUT);
  pinMode(enR,OUTPUT);

  analogWrite(enL,0);
  analogWrite(enR,0);
  digitalWrite(lf,HIGH);
  digitalWrite(lb,HIGH);
  digitalWrite(rf,HIGH);
  digitalWrite(rb,HIGH);
  
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
    int a,b,c,d,e,val;
    a=pulseIn(ch2, HIGH);
    b=pulseIn(ch3, HIGH);
    c=pulseIn(ch4, HIGH);
    d=pulseIn(ch5, HIGH);
    e=pulseIn(ch6, HIGH);
    
    val=map(e,1000,2005,0,90);

    if(d<1100)
    {
      if(val>0 && val<=10)
      {
         Wire.beginTransmission(9);
         Wire.write(1);
         Wire.endTransmission();
      } 
      else if(val>10 && val<=20)
      {
         Wire.beginTransmission(9);
         Wire.write(2);
         Wire.endTransmission();
      }
      else if(val>20 && val<=30)
      {
         Wire.beginTransmission(9);
         Wire.write(3);
         Wire.endTransmission();
      }
      else if(val>30 && val<=40)
      {
         Wire.beginTransmission(9);
         Wire.write(4);
         Wire.endTransmission();
      }
      else if(val>40 && val<=50)
      {
         Wire.beginTransmission(9);
         Wire.write(5);
         Wire.endTransmission();
      }
      else if(val>50 && val<=60)
      {
         Wire.beginTransmission(9);
         Wire.write(6);
         Wire.endTransmission();
      }
      else if(val>60 && val<=70)
      {
         Wire.beginTransmission(9);
         Wire.write(7);
         Wire.endTransmission();
      }
      else if(val>70 && val<=80)
      {
         Wire.beginTransmission(9);
         Wire.write(8);
         Wire.endTransmission();
      }
      else if(val>80 && val<=90)
      {
         Wire.beginTransmission(9);
         Wire.write(9);
         Wire.endTransmission();
      }
      
    }

    else if(d>1850)
    {
      if(val>0 && val<=10)
      {
         Wire.beginTransmission(9);
         Wire.write(11);
         Wire.endTransmission();
      }
      else if(val>10 && val<=20)
      {
         Wire.beginTransmission(9);
         Wire.write(12);
         Wire.endTransmission();
      }
      else if(val>20 && val<=30)
      {
         Wire.beginTransmission(9);
         Wire.write(13);
         Wire.endTransmission();
      }
      else if(val>30 && val<=40)
      {
         Wire.beginTransmission(9);
         Wire.write(14);
         Wire.endTransmission();
      }
      else if(val>40 && val<=50)
      {
         Wire.beginTransmission(9);
         Wire.write(15);
         Wire.endTransmission();
      }
      else if(val>50 && val<=60)
      {
         Wire.beginTransmission(9);
         Wire.write(16);
         Wire.endTransmission();
      }
      else if(val>60 && val<=70)
      {
         Wire.beginTransmission(9);
         Wire.write(17);
         Wire.endTransmission();
      }
      else if(val>70 && val<=80)
      {
         Wire.beginTransmission(9);
         Wire.write(18);
         Wire.endTransmission();
      }
      else if(val>80 && val<=90)
      {
         Wire.beginTransmission(9);
         Wire.write(19);
         Wire.endTransmission();
      }
    }

   if(a<1260 && a>1000)
  {
    analogWrite(enL,map(b,1170,2020,0,255));
    analogWrite(enR,map(b,1170,2020,0,255));
    forward();
  }
  else if(a>1600)
  {
    analogWrite(enL,map(b,1170,2020,0,255));
    analogWrite(enR,map(b,1170,2020,0,255));
    backward();
  }
  else if(c<1260 && c>1000)
  {
    analogWrite(enL,map(b,1170,2020,0,255));
    analogWrite(enR,map(b,1170,2020,0,255));
    left();
  }
  else if(c>1600)
  {
    analogWrite(enL,map(b,1170,2020,0,255));
    analogWrite(enR,map(b,1170,2020,0,255));
    right();
  }
  else
  {
    analogWrite(enL,map(b,1170,2008,0,255));
    analogWrite(enR,map(b,1170,2008,0,255));
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
