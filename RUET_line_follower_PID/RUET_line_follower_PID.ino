/*************************************
---------- Code Written by -----------
-------------- Shimanto --------------
---------------- BUET ----------------
**************************************/

#define inA 10
#define inB 9
#define inC 6
#define inD 5
#define ena 11
#define enb 3

int th[7]={295,295,295,295,295,295,295};
void wheel(int lm, int rm);

int i, sen[7],s[7], lastSensor,lastError;

int base_L=100;
int base_R=100;
int kp=15;
int kd=8;
void setup()
{
  mot_init();
  other_init();
}
void loop()
{
  line_follow();
}

void other_init()
{
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
{
  if(lm==0)
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,HIGH);
  }
  if(lm>0)
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,LOW);
  }
  else if(lm<0)
  {
    digitalWrite(inC,LOW);
    digitalWrite(inD,HIGH);
  }


  if(rm==0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,HIGH);
  }
  if(rm>0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }
  else if(rm<0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
  }
  if(lm>254) lm=45;
  if(lm<-254) lm=-45;
  if(rm>254) rm=45;
  if(rm<-254) rm=-45;
  
  analogWrite(ena,abs(rm));
  analogWrite(enb,abs(lm));
  
}

int readSensor()
{
  for(i=0;i<7;i++)
  { 
    sen[i]=analogRead(i);
    //Serial.println(analogRead(i));
    //delay(200);
    if(sen[i]<th[i])
    {
      s[i]=0;
    }
    else { 
      s[i]=1;
    }
  }
  
  int error,sum;
  sum=s[0]+s[1]+s[2]+s[3]+s[4]+s[5]+s[6];
  if(sum!=0)
  {
    error=(s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50+s[5]*60+s[6]*70)/sum-40;
  }
  else
  {
     error=420;
  }
  
  if(s[0]==1) lastSensor=1;
  else if(s[6]==1) lastSensor =2;
//  Serial.println(error);
  return error;
}
 

void line_follow()
{
  int error,p,d,corr;
 error=readSensor();
 if(error==420)
 {
   if(lastSensor==1) 
   {
    wheel(-45, 45);
    delay(10);
    wheel(0, 180);
   }
   
   else if(lastSensor==2) 
   {
    delay(100);
    wheel(180, 0);
   }
 }
 else 
 { 
   p=kp*error;
   d=kd*(error-lastError);
   corr=p+d;
//   Serial.println(corr);
   wheel(base_L+corr,base_R-corr);
   if((error-lastError)!=0) delay(5);
   lastError=error;
 }
 

}
