

#define inA 11
#define inB 2
#define inC 9
#define inD 8
#define ena 7
#define enb 6

int th[5]={900,900,900,900,900};
int led[5]={8,9,10,11,12};

int i,sen[5],s[5],lastSensor,lastError;

int base_L=75;
int base_R=75;
int kp=12;
int kd=10;
int ki=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  mot_init();
  other_init();
}

void loop()
{
  Serial.println(readSensor());
  wheel(200,200);
  // line_follow();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


void other_init()
{
  for(i=0;i<5;i++) pinMode(led[i],OUTPUT);
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

  else if(lm>0)
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

  else if(rm>0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }

  else if(rm<0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
  }
  if(lm>254) lm=254;
  if(lm<-254) lm=-254;
  if(rm>254) rm=254;
  if(rm<-254) rm=-254;
  analogWrite(ena,abs(rm));
  analogWrite(enb,abs(lm));
}
int readSensor()
{
  for(i=0;i<5;i++) 
  {
    sen[i]=analogRead(i);    //taking reading from sensors
    Serial.print(sen[i]);
    Serial.print("  ");
  }
  Serial.println("");
  for(i=0;i<5;i++)
  {
    if(sen[i]<th[i]) 
    {
      s[i]=0;
    }      
    else 
    {
      s[i]=1;
    }//if black then set 1 else 0
  }
  int error,sum;
  sum=s[0]+s[1]+s[2]+s[3]+s[4];
  if(sum!=0) error=(s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50)/sum-30;
  else error=420;  // line lost
  if(s[0]==1) lastSensor=1;
  else if(s[4]==1) lastSensor=2;
  return error;
}
void line_follow()
{
  int error,p,d,I,corr;
  error=readSensor();
  if(error==420)
  {
    if(lastSensor==1) wheel(-100,100);
    else if(lastSensor==2) wheel(100,-100);
  }

  else 
  {
    p=kp*error;
    d=kd*(error-lastError);
    I=ki*(error+lastError);
    corr=p+d+I;

   wheel(base_L+corr,base_R-corr);
    if((error-lastError)!=0) delay(5);  // so that kd can work
    lastError=error;
  }
}

