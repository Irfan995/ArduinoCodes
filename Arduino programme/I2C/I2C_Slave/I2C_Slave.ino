//i2c Slave Code

#include<Wire.h>
#include<Servo.h>
Servo verServo;
Servo horServo;

void setup() 
{
  Wire.begin(9);
  horServo.attach(3);
  horServo.write(10);
  verServo.attach(10);
  verServo.write(0);
  
  Wire.onReceive(receiveEvent);
}

void loop() 
{
}

void receiveEvent(int byets)
{
 while(Wire.available())
 {
  int a=Wire.read();

  if(a==1)
  {
    verServo.write(0);
    horServo.write(10);
    delay(10);
  }
  else if(a==2)
  {
    verServo.write(0);
    horServo.write(20);
    delay(10);
  }
  else if(a==3)
  {
    verServo.write(0);
    horServo.write(30);
    delay(10);
  }
  else if(a==4)
  {
    verServo.write(0);
    horServo.write(40);
    delay(10);
  }
  else if(a==5)
  {
    verServo.write(0);
    horServo.write(50);
    delay(10);
  }
  else if(a==6)
  {
    verServo.write(0);
    horServo.write(60);
    delay(10);
  }
  else if(a==7)
  {
    verServo.write(0);
    horServo.write(70);
    delay(10);
  }
  else if(a==8)
  {
    verServo.write(0);
    horServo.write(80);
    delay(10);
  }
  else if(a==9)
  {
    verServo.write(0);
    horServo.write(90);
    delay(10);
  }
  else if(a==11)
  {
    verServo.write(80);
    horServo.write(10);
    delay(10);
  }
  else if(a==12)
  {
    verServo.write(80);
    horServo.write(20);
    delay(10);
  }
  else if(a==13)
  {
    verServo.write(80);
    horServo.write(30);
    delay(10);
  }
  else if(a==14)
  {
    verServo.write(80);
    horServo.write(40);
    delay(10);
  }
  else if(a==15)
  {
    verServo.write(80);
    horServo.write(50);
    delay(10);
  }
  else if(a==16)
  {
    verServo.write(80);
    horServo.write(60);
    delay(10);
  }
  else if(a==17)
  {
    verServo.write(80);
    horServo.write(70);
    delay(10);
  }
  else if(a==18)
  {
    verServo.write(80);
    horServo.write(80);
    delay(10);
  }
  else if(a==19)
  {
    verServo.write(80);
    horServo.write(90);
    delay(10);
  }
 }
  
}

