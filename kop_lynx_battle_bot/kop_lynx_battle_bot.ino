#include <Servo.h>
#include <hid.h>
#include <hiduniversal.h>
#include <usbhub.h>
#include "hidjoystickrptparser.h"
#define in1D 22
#define in1C 24
#define in1B 26
#define in1A 28
#define en1a 6
#define en1b 7
#define in2A 38
#define in2B 40
#define in2C 42
#define in2D 44
#define en2a 13
#define en2b 12
#include <Servo.h>
Servo myservo;
float base_L=150;
float base_R=150;
float kp=12.0  ;
float kd=0.0 ;
float ki=0.0 ;
int pos=0;
//#include <Stepper.h>
//Stepper pochaMotor(200, 31,33,35,37);  
USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);
Servo elbow,hand,shoulder,gate;
int elbowpos,handpos;
int gateval;
int rightJoy, leftJoy, hat,Button, leftXX, rightXX;
int SpeedL, SpeedR;
void control(){
    if(leftJoy==-255) setspeed(254,254);
    else if(leftJoy==255) setspeed(-254,-254);
    else if(Button==47) setspeed(254,-254);
    else if(Button==143) setspeed(-254,254); 
    else if(hat==4) setspeed(128,254);
    else if(hat==8) setspeed(254,128);
    else if(Button==31 ){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //  z  delay(15);                       // waits 15ms for the servo to reach the position
  } 
     for (pos = 180; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //  z  delay(15);                       // waits 15ms for the servo to reach the position
  }  // waits 15ms for the servo to reach the position
  }
  else if(Button==79 ){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees  
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   // delay(15);                       // waits 15ms for the servo to reach the position
  }                       // waits 15ms for the servo to reach the position
  }
    //  pochaMotor.step(-1);
       // delay(10);
}
void setspeed (int lm,int rm)
{
  /* 
   analogWrite(en1a,l);
   analogWrite(en1b,r);
   digitalWrite(in1C,LOW);
   digitalWrite(in1D,HIGH);
   digitalWrite(in1A,LOW);
   digitalWrite(in1B,HIGH);
   analogWrite(en2a,l);
   analogWrite(en2b,r);
   digitalWrite(in2C,LOW);
   digitalWrite(in2D,HIGH);
   digitalWrite(in2A,LOW);
   digitalWrite(in2B,HIGH);
*/
  analogWrite(en1a,abs(lm));
  analogWrite(en1b,abs(rm));
  analogWrite(en2a,abs(rm));
  analogWrite(en2b,abs(lm));
  if(lm==0) 
  {
    digitalWrite(in1A,HIGH);
    digitalWrite(in1B,HIGH);
    digitalWrite(in2C,HIGH);
    digitalWrite(in2D,HIGH);
  }
  else if(lm>0)
  {
    digitalWrite(in1A,HIGH);
    digitalWrite(in1B,LOW);
    digitalWrite(in2D,LOW);
    digitalWrite(in2C,HIGH);
  }
  else if(lm<0)
  {
    digitalWrite(in1A,LOW);
    digitalWrite(in1B,HIGH);
    digitalWrite(in2D,HIGH);
    digitalWrite(in2C,LOW);
  }
  if(rm==0) 
  {
    digitalWrite(in1C,HIGH);
    digitalWrite(in1D,HIGH);
    digitalWrite(in2A,HIGH);
    digitalWrite(in2B,HIGH);
  }

  else if(rm>0)
  {
    digitalWrite(in1C,LOW);
    digitalWrite(in1D,HIGH);
    digitalWrite(in2A,LOW);
    digitalWrite(in2B,HIGH);
  }

  else if(rm<0)
  {
    digitalWrite(in1C,HIGH);
    digitalWrite(in1D,LOW);
    digitalWrite(in2A,HIGH);
    digitalWrite(in2B,LOW);
  } 
}
void gamepad(){ 
  Usb.Task();
  leftJoy=((JoyEvents.get_left())*2)-255;
  rightJoy=((JoyEvents.get_right())*2)-255;
  leftXX=(JoyEvents.get_left_X())-128;
  rightXX=(JoyEvents.get_right_X())-128;
  Button=JoyEvents.get_button();
  hat=JoyEvents.get_hat();

  Serial.print(leftJoy);
  Serial.print("eitaleftjoy  ");
  Serial.print(rightJoy);
  Serial.print("eitarightjoy  ");
  Serial.print(leftXX);
  Serial.print("leftxx   ");
  Serial.print(rightXX);
  Serial.print("rightxx  ");
  Serial.print(Button);
  Serial.print("button    ");
  Serial.print(hat);
  Serial.println("hat    ");

 
}
void setup()
{
  rightJoy=0; 
  leftJoy=0; 
  hat=20;
  Button=0;
  leftXX=0;
  rightXX=0;
  Serial.begin(9600); 
  //pochaMotor.setSpeed(5);
  
  pinMode(in1A,OUTPUT);
  pinMode(in1B,OUTPUT);
  pinMode(in1C,OUTPUT);
  pinMode(in1D,OUTPUT);
  pinMode(en1a,OUTPUT);
  pinMode(en1b,OUTPUT);

  digitalWrite(in1A,HIGH);
  digitalWrite(in1B,HIGH);
  digitalWrite(in1C,HIGH);
  digitalWrite(in1D,HIGH);
    pinMode(in2A,OUTPUT);
  pinMode(in2B,OUTPUT);
  pinMode(in2C,OUTPUT);
  pinMode(in2D,OUTPUT);
  pinMode(en2a,OUTPUT);
  pinMode(en2b,OUTPUT);
  // pochaMotor.setSpeed(500);
    myservo.attach(9);
  digitalWrite(in2A,HIGH);
  digitalWrite(in2B,HIGH);
  digitalWrite(in2C,HIGH);
  digitalWrite(in2D,HIGH);
   
  if (Usb.Init() == -1)
  {
  }
  delay(200);
  if (!Hid.SetReportParser(0, &Joy))  ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);
//  while(1) setspeed(200,200);                  
  myservo.write( 0 ); 

}

void loop()
{
//   if (Serial.available()) 
//  {
//    int steps = Serial.parseInt();
//      Serial.println(steps);  
//////    steps= (184/360)*steps;
//    pochaMotor.step(steps);
//    Serial.println(steps);
//  }
  gamepad();
  if(Button==15 && leftJoy==1 && hat==0){
    setspeed(0,0);
  }
  else
    control();
}
