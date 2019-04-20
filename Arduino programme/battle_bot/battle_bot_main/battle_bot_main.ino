//i2c Master Code
#include<Servo.h>

#define CH1 8
#define CH2 7
#define CH3 6
#define CH4 5
#define CH5 4

Servo lServo;
Servo rServo;


void setup() 
{
  pinMode(CH1,INPUT);
  pinMode(CH2,INPUT);
  pinMode(CH3,INPUT);
  pinMode(CH4,INPUT);
  pinMode(CH5,INPUT);

  lServo.attach(10);
  rServo.attach(3);
  
}

void loop()
{
    int a,b,c,d,e,f,val;
    a=pulseIn(CH1,HIGH);
    b=pulseIn(CH2,HIGH);
    c=pulseIn(CH3,HIGH);
    d=pulseIn(CH4,HIGH);
    e=pulseIn(CH5,HIGH);
    
    if (a>1600)
    {
      left();
      delay(10);
      //Serial.println("left");
    }

    else if (a<1460)
    {
      right();
      delay(10);
      //Serial.println("right");
    }

    else if (b>1600)
    {
      forward();
      delay(10);
      //Serial.println("forward");
    }

    else if (b<1500)
    {
      backward();
      delay(10);
      //Serial.println("backward");
    }

    else 
    {
      stp();
      delay(10);
      //Serial.println("stop");
    }

  

}


void forward()
{
  
  lServo.write(20);
  rServo.write(20);
  //delay(10);
}

void backward()
{
  lServo.write(160);
  rServo.write(160);
  //delay(10);
}

void left()
{
  lServo.write(160);
  rServo.write(20);
  //delay(10);
}

void right()
{
  lServo.write(20);
  rServo.write(160);
  //delay(10);
}

void stp()
{
  lServo.write(95);
  rServo.write(95);
  //delay(10);
}
