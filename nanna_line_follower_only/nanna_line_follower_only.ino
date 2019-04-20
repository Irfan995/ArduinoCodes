#define inA 10
#define inB 5
#define inC 9
#define inD 8
#define ena 7
#define enb 6
#define ays 500
int th[5]={ays,ays,ays,ays,ays};
int led[5]={2,3,4,5,12};

int i,sen[5],s[5],lastSensor,lastError; 

float base_L=200;
float base_R=200;
float kp=9.8;
float kd=7;
float ki=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  mot_init();
  other_init();
}

void loop()
{
  Serial.println(readSensor());
  wheel(75,75);
  line_follow();
  readSensor();
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
  if(lm>0&&rm>0)
  {
  digitalWrite(inA,HIGH);
  digitalWrite(inB,LOW);
  digitalWrite(inC,HIGH);
  digitalWrite(inD,LOW);    
  }
  else
  {
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
  }
  if(lm>254) lm=175;
  if(lm<-254) lm=-175;
  if(rm>254) rm=175;
  if(rm<-254) rm=-175;
  lm=abs(lm);
  rm=abs(rm);
  if(lm>0 && lm<70) lm=175;
  if(rm>0 &&rm<70) rm=175;

  analogWrite(ena,abs(rm));
  analogWrite(enb,abs(lm));

}


int readSensor()
{
  for(i=0;i<5;i++) 
  {
    sen[i]=analogRead(i);    //taking reading from sensors
    Serial.print(sen[i]);
    Serial.print(" ");
    Serial.print(i); 
    Serial.print(" ");
  }
  Serial.println("");
  for(i=0;i<5;i++)
  {
    if(sen[i]<th[i]) 
    {
      s[i]=0;
      digitalWrite(led[i],LOW);
    }      
    else 
    {
      s[i]=1;
      digitalWrite(led[i],HIGH);
    }                //if black then set 1 else 0
  }
  int error,sum;
  sum=s[0]+s[1]+s[2]+s[3]+s[4];
  if(sum!=0) error=(s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50)/sum-30;
  else error=420;  // line lost

  if(s[0]==1 && sum<3) lastSensor=1;
  else if(s[4]==1 && sum<3 ) lastSensor=2;
  else if(s[0]==1 && s[1]==1 && sum>=3) lastSensor=30;
  else if(s[4]==1 && s[3]==1 && sum>=3) lastSensor=40;
  
 // Serial.println("...........error............");
 /// Serial.println(error);

  return error;
}


void line_follow()
{
  int error;
  float p=0,d=0,I=0,corr=0;
  error=readSensor();
  if(error==420)
  {
    if(lastSensor==1) wheel(-250,250);
    else if(lastSensor==2) wheel(250,-250);
    //else if(lastSensor==30)
    {
      //delay(1000);
      //wheel(-90,90);
    //}
    //else if(lastSensor==40)
    //{
      //delay(1000);
      //wheel(90,-90);
    //}
  }}

  else 
  {
    p=kp*error;
    d=kd*(error-lastError);
    I=ki*(error+lastError);
    corr=p+d+I;
    //Serial.println(base_L+corr);
   // Serial.println("         ");
    //Serial.println(base_R-corr);
    wheel(base_L+corr,base_R-corr);
     if((error-lastError)!=0) delay(5);  // so that kd can work
    lastError=error;
  }
}



