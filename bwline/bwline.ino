#define inA 11
#define inB 10
#define inC 9
#define inD 8
#define ena 7
#define enb 6
#define ays 500
#define spd 150
int th[5]={ays,ays,ays,ays,ays};
int led[5]={2,3,4,5,12};
float base_L=spd;
float base_R=spd;
float kp=14;
float kd=9;
float ki=0; 
int flagwb=1;


int i,sen[5],s[5],lastSensor,lastError; 


/////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  mot_init();
  other_init();
}

void loop()
{
 // Serial.println(readSensor());
  //readSensor();
  //wheel(spd,spd);
  //line_follow();
  
    if(flagwb==1)
    {
    while(!((analogRead(1)<ays || analogRead(2)<ays || analogRead(3)<ays) && analogRead(0)>ays && analogRead(4)>ays))
    {
      
         if(analogRead(0)>ays && analogRead(1)>ays && analogRead(4)<ays)
         {
            wheel(0,0);
            delay(10);
            wheel(-200,200);
            delay(50);
            while(analogRead(2)>ays)
            {
              wheel(-200,200);
            }
         }
         else if(analogRead(4)>ays && analogRead(3)>ays && analogRead(0)<ays)
         {
            wheel(0,0);
            delay(10);
            wheel(200,-200);
            delay(50);
            while(analogRead(2)>ays)
            {
              wheel(200,-200);
            }
         }
        readSensorWline();
        wheel(spd,spd);
        line_followWline();
       //if(analogRead(sensor[2])<midVal[2] && (analogRead(sensor[0])>midVal[0] && analogRead(sensor[1])>midVal[1] && analogRead(sensor[3])>midVal[3] && analogRead(sensor[4])>midVal[4]))break;
       //if(analogRead(2)<ays && (analogRead(0)>ays && analogRead(1)>ays && analogRead(3)>ays && analogRead(4)>ays))break;
    }
    flagwb=0;
    }
    else
    {
    // while(!(analogRead(sensor[2])>midVal[2] && (analogRead(sensor[0])<midVal[0] && analogRead(sensor[1])<midVal[1] && analogRead(sensor[3])<midVal[3] && analogRead(sensor[4])<midVal[4]))){
      
     while(!((analogRead(1)>ays || analogRead(2)>ays || analogRead(3)>ays) && analogRead(0)<ays && analogRead(4)<ays))
      {
        /*if(analogRead(0)<ays && analogRead(1)<ays && analogRead(2)<ays && analogRead(3)<ays && analogRead(4)<ays)
        {
          wheel(200,200);
          delay(20);
          if(analogRead(0)<ays && analogRead(1)<ays && analogRead(2)<ays && analogRead(3)<ays && analogRead(4)<ays)
          {
            while(1)
            {
              wheel(0,0);
            }
          }*/
          
        
        if(analogRead(0)<ays && analogRead(1)<ays && analogRead(4)>ays)
         {
            wheel(0,0);
            delay(10);
            wheel(-200,200);
            delay(50);
            while(analogRead(2)>ays)
            {
              wheel(-200,200);
            }
         }
         else if(analogRead(4)<ays && analogRead(3)<ays && analogRead(0)>ays)
         {
            wheel(0,0);
            delay(10);
            wheel(200,-200);
            delay(50);
            while(analogRead(2)>ays)
            {
              wheel(200,-200);
            }
         }
      
          readSensorBline();
          wheel(spd,spd);
          line_followBline(); 
      }
     flagwb=1;
  }
  
  
  /*if((analogRead(1)>ays || analogRead(2)>ays || analogRead(3)>ays) && analogRead(0)<ays && analogRead(4)<ays)
  {      
      readSensorWline();
      wheel(spd,spd);
      line_followWline();
  }
  
  
  
   else if((analogRead(1)<ays || analogRead(2)<ays || analogRead(3)<ays) && analogRead(0)>ays && analogRead(4)>ays)
    {
      readSensorBline();
      wheel(spd,spd);
      line_followBline(); 
    }
    else
    {
     if(lastSensor==1) {wheel(-195,195); }
      else if(lastSensor==2) {wheel(195,-195);}
    }
*/

}

//////////////////////////////////////////////////////////////////////////////////////////////////////


void other_init()
{
  //for(i=0;i<5;i++) //pinMode(led[i],OUTPUT);
  lastSensor=0;
  lastError=0;
  Serial.begin(9600);
}

void mot_init()
{
  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inD,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);

  digitalWrite(inA,HIGH);
  digitalWrite(inB,HIGH);
  digitalWrite(inC,HIGH);
  digitalWrite(inD,HIGH);
}

void wheel(int lm, int rm)
{   //analogWrite(ena,abs(rm));
  //analogWrite(enb,abs(lm));
  
  if(lm==0) 
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,HIGH);
  }

  else if(lm<0)
  {
    digitalWrite(inC,LOW);
    digitalWrite(inD,HIGH);
  }

  else if(lm>0)
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,LOW);
  }



  if(rm==0) 
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,HIGH);
  }

  else if(rm<0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
  }

  else if(rm>0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }
  
  if(lm>254) lm=spd;
  if(lm<-254) lm=-spd;
  if(rm>254) rm=spd;
  if(rm<-254) rm=-spd;
  lm=abs(lm);
  rm=abs(rm);
//  if(lm>0 && lm<70) lm=200;
//  if(rm>0 &&rm<70) rm=200;

  analogWrite(ena,abs(rm));
  analogWrite(enb,abs(lm));

}


int readSensorWline()
{
  for(i=0;i<5;i++) 
  {
    sen[i]=analogRead(i);
   if(sen[i]<th[i]) 
    {
      s[i]=0;
      digitalWrite(led[i],LOW);
    }      
    else 
    {
      s[i]=1;
      digitalWrite(led[i],HIGH);
    }     //taking reading from sensors
    Serial.print(sen[i]);
    Serial.print(" ");
    Serial.print(i); 
    Serial.print(" ");
  }
   Serial.println(" ");
     int error,sum;
  sum=s[0]+s[1]+s[2]+s[3]+s[4];
  if(sum!=0) error=(s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50)/sum-30;
  else error=420;  // line lost
 
  if(s[0]==1 ) lastSensor=1;
  else if(s[4]==1 ) lastSensor=2;
  
 
  
 // Serial.println("...........error............");
 /// Serial.println(error);

  return error;
}


int readSensorBline()
{
  for(i=0;i<5;i++) 
  {
    sen[i]=analogRead(i);
   if(sen[i]>th[i]) 
    {
      s[i]=0;
      digitalWrite(led[i],LOW);
    }      
    else 
    {
      s[i]=1;
      digitalWrite(led[i],HIGH);
    }     //taking reading from sensors
    Serial.print(sen[i]);
    Serial.print(" ");
    Serial.print(i); 
    Serial.print(" ");
  }
   Serial.println(" ");
   int error,sum;
   sum=s[0]+s[1]+s[2]+s[3]+s[4];
  if(sum!=0) error=(s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50)/sum-30;
  else error=420;  // line lost
 
 /* if(s[0]==1 ) lastSensor=1;
  else if(s[4]==1 ) lastSensor=2;
  */
  
  if(s[0]==1 ) lastSensor=1;
  if(s[4]==1 ) lastSensor=2;
  else if(s[0]==1 && s[1]==1 && sum>=3) lastSensor=30;
  else if(s[4]==1 && s[3]==1 && sum>=3) lastSensor=40;
  
 
  
 // Serial.println("...........error............");
 /// Serial.println(error);

  return error;
}


void line_followBline()
{
  int error;
  float p=0.0,d=0.0,I=0.0,corr=0.0;
  error=readSensorBline();
  if(error==420)
  {
    if(lastSensor==1) {wheel(-195,195); }
    else if(lastSensor==2) {wheel(195,-195);}
 
  }
  

  else  
  {
    p=kp*error;
    d=kd*(error-lastError);
    I=ki*(error+lastError);
    corr=p+d+I;
    Serial.println(base_L+corr);
    Serial.println(base_R-corr);
    //if(lastSensor==30){ wheel(-175,175); delay(3);}
   //else if(lastSensor==40) { wheel(175,-175); delay(3);}
    //else 
    //{
    
      wheel(base_L+corr,base_R-corr);
    
     if((error-lastError)!=0) delay(5);  // so that kd can work
    lastError=error;
      //}
  }
}


void line_followWline()
{
  int error;
  float p=0.0,d=0.0,I=0.0,corr=0.0;
  error=readSensorWline();
  if(error==420)
  {
    if(lastSensor==1) {wheel(-195,195); }
    else if(lastSensor==2) {wheel(195,-195);}
 
  }

  else  
  {
    p=kp*error;
    d=kd*(error-lastError);
    I=ki*(error+lastError);
    corr=p+d+I;
    Serial.println(base_L+corr);
    Serial.println(base_R-corr);
    //if(lastSensor==30){ wheel(-175,175); delay(3);}
   //else if(lastSensor==40) { wheel(175,-175); delay(3);}
  // else 
    //{
    
      wheel(base_L+corr,base_R-corr);
    
     if((error-lastError)!=0) delay(5);  // so that kd can work
    lastError=error;
    //}
   }
}
