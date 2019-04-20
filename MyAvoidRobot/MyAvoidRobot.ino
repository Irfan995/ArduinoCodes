
#define inA 13
#define inB 3
#define inC 9
#define inD 8
#define ena 7
#define enb 6

int base_L=75;
int base_R=75;
int trigPin = 12;    //Trig - green Jumper
int echoPin = 5;    //Echo - yellow Jumper
long duration, cm, inches;
long distance=15;
int flag=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  mot_init();
   Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  //wheel(200,200);
  // line_follow();
  
  sonarFollow();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
 // digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  //inches = (duration/2) / 74; 
  
  //Serial.print(inches);
  //Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250); 
  
  if(cm<=distance)
  {
    flag=1;
    //wheel(0,0);
  }
  else if(cm>distance)
  {
    flag=0;
   // wheel(200,200);
  }
  
  //delay(1000);
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
void sonarFollow()
{
  if(flag==1)
  {
    wheel(0,0);
    delay(500);
  }
  else
  {
    wheel(170,130);
  }
}

