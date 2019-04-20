#include <Servo.h>
#include <hid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include "hidjoystickrptparser.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);

Servo elbow,hand,shoulder,gate;
int elbowpos,handpos;
int gateval;
int rightJoy, leftJoy, hat,Button, leftXX, rightXX;
///C   D
///A   B

#define MotorBp A3
#define MotorBn A1
#define MotorB 8

#define MotorAn 10
#define MotorAp 9
#define MotorA 7

#define MotorDp A5
#define MotorDn A6
#define MotorD 6

#define MotorCn 3
#define MotorCp 5
#define MotorC 2

int SpeedL, SpeedR;

void setup()
{
  rightJoy=0; 
  leftJoy=0; 
  hat=20;
  Button=0;
  leftXX=0;
  rightXX=0;
  Serial.begin(9600);

  elbowpos=170;
  handpos=88;
  hand.attach(48);
  hand.write(handpos);
  elbow.attach(11);
  elbow.write(elbowpos); // increase to up
  shoulder.attach(12);
  shoulder.write(88);  
  gate.attach(4);
  gate.write(0);
  
  if (Usb.Init() == -1)
  {
  }
  delay(200);
  if (!Hid.SetReportParser(0, &Joy))  ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);


  pinMode(MotorA, OUTPUT);
  pinMode(MotorB, OUTPUT);
  pinMode(MotorC, OUTPUT);
  pinMode(MotorD, OUTPUT);

  pinMode(MotorAp, OUTPUT);
  pinMode(MotorAn, OUTPUT);
  pinMode(MotorBp, OUTPUT);
  pinMode(MotorBn, OUTPUT);

  pinMode(MotorCp, OUTPUT);
  pinMode(MotorCn, OUTPUT);
  pinMode(MotorDp, OUTPUT);
  pinMode(MotorDn, OUTPUT); 



}

void loop()
{

  // read joystick

  Usb.Task();
  leftJoy=((JoyEvents.get_left())*2)-255;
  rightJoy=((JoyEvents.get_right())*2)-255;
  leftXX=(JoyEvents.get_left_X())-128;
  rightXX=(JoyEvents.get_right_X())-128;
  Button=JoyEvents.get_button();
  hat=JoyEvents.get_hat();
  /////////////////////////////  set speed


  //
  Serial.print(leftJoy);
  Serial.print("  ");
  Serial.print(rightJoy);
  Serial.println("  ");
  Serial.print(leftXX);
  Serial.print("  ");
  Serial.print(rightXX);
  Serial.print("     ");
  Serial.print(Button);
  Serial.print("  ");
  Serial.println(hat);

  if(Button==15)
  {  
    if(leftJoy<-20)
    {
      digitalWrite(MotorBp, HIGH);   
      digitalWrite(MotorBn, LOW);
      digitalWrite(MotorDp, HIGH);   
      digitalWrite(MotorDn, LOW);
    }
    else if(leftJoy>20)
    {
      digitalWrite(MotorBn, HIGH);   
      digitalWrite(MotorBp, LOW);
      digitalWrite(MotorDn, HIGH);   
      digitalWrite(MotorDp, LOW);
    }

    else
    {
      digitalWrite(MotorBp, HIGH);   
      digitalWrite(MotorBn, HIGH);
      digitalWrite(MotorDp, HIGH);   
      digitalWrite(MotorDn, HIGH);
    }



    if(rightJoy<-20)
    {
      digitalWrite(MotorAp, HIGH);   
      digitalWrite(MotorAn, LOW);
      digitalWrite(MotorCp, HIGH);   
      digitalWrite(MotorCn, LOW);
    }
    else if(rightJoy>20)
    {
      digitalWrite(MotorAn, HIGH);   
      digitalWrite(MotorAp, LOW);
      digitalWrite(MotorCn, HIGH);   
      digitalWrite(MotorCp, LOW);
    }

    else
    {
      digitalWrite(MotorAp, HIGH);   
      digitalWrite(MotorAn, HIGH);
      digitalWrite(MotorCp, HIGH);   
      digitalWrite(MotorCn, HIGH);
    }

    analogWrite(MotorA, abs(rightJoy));
    analogWrite(MotorC, abs(rightJoy));
    analogWrite(MotorB, abs(leftJoy));
    analogWrite(MotorD, abs(leftJoy));

  }

  else if(Button==0)
  {
    analogWrite(MotorA, 80);
    analogWrite(MotorC, 80);
    analogWrite(MotorB, 80);
    analogWrite(MotorD, 80);

    digitalWrite(MotorAp, HIGH);   
    digitalWrite(MotorAn, LOW);
    digitalWrite(MotorCp, HIGH);   
    digitalWrite(MotorCn, LOW);

    digitalWrite(MotorBp, HIGH);   
    digitalWrite(MotorBn, LOW);
    digitalWrite(MotorDp, HIGH);   
    digitalWrite(MotorDn, LOW);
  }

  else if(Button==4)
  {
    analogWrite(MotorA, 80);
    analogWrite(MotorC, 80);
    analogWrite(MotorB, 80);
    analogWrite(MotorD, 80);

    digitalWrite(MotorAn, HIGH);   
    digitalWrite(MotorAp, LOW);
    digitalWrite(MotorCn, HIGH);   
    digitalWrite(MotorCp, LOW);

    digitalWrite(MotorBn, HIGH);   
    digitalWrite(MotorBp, LOW);
    digitalWrite(MotorDn, HIGH);   
    digitalWrite(MotorDp, LOW);
  }

  else if(Button==2)
  {
    analogWrite(MotorA, 250);
    analogWrite(MotorC, 250);
    analogWrite(MotorB, 250);
    analogWrite(MotorD, 250);

    digitalWrite(MotorAn, HIGH);   
    digitalWrite(MotorAp, LOW);
    digitalWrite(MotorCn, HIGH);   
    digitalWrite(MotorCp, LOW);

    digitalWrite(MotorBp, HIGH);   
    digitalWrite(MotorBn, LOW);
    digitalWrite(MotorDp, HIGH);   
    digitalWrite(MotorDn, LOW);
    delay(25);
    digitalWrite(MotorAn, HIGH);   
    digitalWrite(MotorAp, HIGH);
    digitalWrite(MotorCn, HIGH);   
    digitalWrite(MotorCp, HIGH);

    digitalWrite(MotorBp, HIGH);   
    digitalWrite(MotorBn, HIGH);
    digitalWrite(MotorDp, HIGH);   
    digitalWrite(MotorDn, HIGH);
    delay(20);

  }

  else if(Button==6)
  {
    analogWrite(MotorA, 250);
    analogWrite(MotorC, 250);
    analogWrite(MotorB, 250);
    analogWrite(MotorD, 250);

    digitalWrite(MotorAp, HIGH);   
    digitalWrite(MotorAn, LOW);
    digitalWrite(MotorCp, HIGH);   
    digitalWrite(MotorCn, LOW);

    digitalWrite(MotorBn, HIGH);   
    digitalWrite(MotorBp, LOW);
    digitalWrite(MotorDn, HIGH);   
    digitalWrite(MotorDp, LOW);
    delay(25);
    digitalWrite(MotorAn, HIGH);   
    digitalWrite(MotorAp, HIGH);
    digitalWrite(MotorCn, HIGH);   
    digitalWrite(MotorCp, HIGH);

    digitalWrite(MotorBp, HIGH);   
    digitalWrite(MotorBn, HIGH);
    digitalWrite(MotorDp, HIGH);   
    digitalWrite(MotorDn, HIGH);
    delay(20);

  }

  if(hat == 2)
  {
    elbowpos=elbowpos+1;
    delay(8);
  } 

  else if(hat == 8)
  {
    elbowpos=elbowpos-1;
    delay(8);
  }

  if(Button==31)
  {
   handpos=handpos+1;
   delay(8);
  } 

  else if(Button==79)
  {
   handpos=handpos-1;
   delay(8);
  }
  
  if (Button==143)
  {
    shoulder.write(98);
  }
  else if (Button == 47)
  {
    shoulder.write(68);
  }
  else shoulder.write(88);
  
  if (hat==1)
  {
    elbowpos = 160;
    elbow.write(160);
    gate.write(90);
    
  }
  else if (hat==4)
  {
    for (gateval=90;gateval>=0;gateval=gateval-3)
    gate.write(gateval);
    delay(10);
  }
  hand.write(handpos);
  elbow.write(constrain(elbowpos,70,175));
}













