#include<Servo.h>

Servo x1;
Servo x2;


int xN1 = 180;
int xN2 = 0;

void setup()
{
  x1.attach(3);
  x2.attach(10);
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available() > 0) {
   char a=Serial.read();
   if(a == 'f'){
  x1.write(xN1);
  x2.write(xN2);
 // delay(2000);
   }

  else if(a == 'b'){
  x1.write(xN2);
  x2.write(xN1);
  //delay(2000);
  }
}

}
