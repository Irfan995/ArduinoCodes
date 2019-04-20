#include <Servo.h> 
 
Servo servo1;  // create servo object to control a servo 
Servo BLDC;    // twelve servo objects can be created on most boards
 
int pos = 50;    // BLDC
int angle = 90;     // Servo
char p;
void setup() 
{
  Serial.begin(9600);
  servo1.attach(9);
  servo1.write(angle);
   BLDC.attach(10);
  BLDC.write(15);
} 
 
void loop() 
{ 
  while(Serial.available())
  {
   p = Serial.read();
   if(p == 'w')
   {
     if(pos<=160)
     pos+=20;
     BLDC.write(pos);
   }
   else if(p == 's')
   {
     if(pos>20)
     pos-=20;
     BLDC.write(pos);
   }
      else if(p == ' ')
   {
     BLDC.write(0);
   }
   else if(p == 'a')
   {
     if(angle<185)
     angle+=15;
     servo1.write(angle);
   }
   else if(p == 'd')
   {
     if(angle>15)
     angle-=15;
     servo1.write(angle);
   }
   
   else if(p == 'l')
   {
     int a;
     
     for(a=0;a<70;a+=5)
     {
            BLDC.write(a);
            delay(50);

     }
     delay(1000);
          BLDC.write(pos);
   }
   
      else if(p == 'b')
   {
      servo1.write(30);
   }
   
  }
}
