
#define inA 10
#define inB 9
#define inC 6
#define inD 5
#define ena 11
#define enb 3


int th[7] = {500, 500, 500, 500, 500, 500, 500};

int i, sen[7], s[7], lastSensor, lastError;

int base_L = 100;
int base_R = 100;
int kp = 4;
int kd = 3;
long long unsigned int c_time;
long long unsigned int flag_time;
/////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  mot_init();
  other_init();
  delay(300);

  wheel(0, 0);
}
int err;
char seq[6];
int seq_val;
bool back_en;
bool right_en;
void loop()
{
  //Serial.println(readSensor());
  //wheel(100,100);
  err = readSensor();
  if(err==111)
  {
    wheel(base_L,base_R);
    delay(50);
    err=readSensor();
    if(err==111)
    {
      if((back_en==false)||(right_en==true))
      {
        wheel(base_L,base_R);
        delay(250);
        wheel(-base_L,-base_R);
        delay(50);
        wheel(base_L,-base_R);
        delay(800);
        
        while(abs(err>15))
        {
          err=readSensor();
          wheel(100,-100);
        }
        wheel(100,-100);
        delay(50);
        wheel(0,0);
        back_en=true;
        lastSensor=0;
      }
    }
    else if((back_en==true)&&(right_en==false))
    {
      wheel(100,-100);
      delay(400);
      wheel(0,0);
      delay(50);
      err=readSensor();
      while(abs(err)>15)
      {
        wheel(100,-100);
        err=readSensor();
      }
      wheel(-base_L,base_R);
      delay(50);
      wheel(0,0);
      delay(80);
      lastSensor=0;
      right_en=true;
    }
    else if((back_en==true)&&(right_en==true))
    {
      wheel(base_L,base_R);
      delay(50);
    }
  }
  else if (err == 222)
  {
    right_en=0;
    back_en=0;
    c_time=millis();
    if(abs(c_time-flag_time)>700){ c_time=0; flag_time=0; lastSensor=0;}
    if (lastSensor == 0)
    {
      wheel(base_L, base_R);
      delay(550);
      err = readSensor();
      if (err == 222) wheel(0, 0);
      else if (err < 100) line_follow(err);
    }
    else if(lastSensor==1)
    {
      wheel(-base_L,-base_R);
      delay(50);
      wheel(0,0);
      delay(50);
      err=readSensor();
      while(abs(err)>15)
      {
        wheel(-100,100);
        err=readSensor();
      }
      wheel(base_L,-base_R);
      delay(50);
      wheel(0,0);
      delay(80);
      lastSensor=0;
    }
    else if(lastSensor==2)
    {
      wheel(-base_L,-base_R);
      delay(50);
      wheel(0,0);
      delay(50);
      err=readSensor();
      while(abs(err)>15)
      {
        wheel(100,-100);
        err=readSensor();
      }
      wheel(-base_L,base_R);
      delay(50);
      wheel(0,0);
      delay(80);
      lastSensor=0;
    }
  }
  else line_follow(err);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void other_init()
{
  for(uint8_t i=0;i<6;i++) seq[i]='a';
  seq_val=0;
  lastSensor = 0;
  lastError = 0;
  
  
  Serial.begin(9600);
  right_en=false;
  back_en=false;
}

void mot_init()
{
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  digitalWrite(inA, HIGH);
  digitalWrite(inB, HIGH);
  digitalWrite(inC, HIGH);
  digitalWrite(inD, HIGH);
}

void wheel(int rm, int lm)
{
  if (lm == 0)
  {
    digitalWrite(inC, HIGH);
    digitalWrite(inD, HIGH);
  }

  else if (lm > 0)
  {
    digitalWrite(inC, HIGH);
    digitalWrite(inD, LOW);
  }

  else if (lm < 0)
  {
    digitalWrite(inC, LOW);
    digitalWrite(inD, HIGH);
  }



  if (rm == 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, HIGH);
  }

  else if (rm > 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
  }

  else if (rm < 0)
  {
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
  }

  if (lm > 254) lm = 254;
  if (lm < -254) lm = -254;
  if (rm > 254) rm = 254;
  if (rm < -254) rm = -254;

  analogWrite(ena, abs(rm));
  analogWrite(enb, abs(lm));

}


int readSensor()
{
  for (i = 0; i < 7; i++)
  {
    sen[i] = analogRead(i);  //taking reading from sensors
    Serial.print(sen[i]);
    Serial.print("  ");
  }
  Serial.println();
  
  for (i = 0; i < 7; i++)
  {
    if (sen[i] < th[i])
    {
      s[i] = 0;
    }
    else
    {
      s[i] = 1 ;
    }                //if black then set 1 else 0
  }
  int error, sum ;
  if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0) return 222;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 ) return 111;
  sum = s[0] + s[1] + s[2] + s[3] + s[4] + s[5] + s[6];
  if (sum != 0) error = (s[0] * 10 + s[1] * 20 + s[2] * 30 + s[3] * 40 + s[4] * 50 + s[5] * 60 + s[6] * 70) / sum - 30;
  else error = 420; // line lost

  if (s[0] == 1){flag_time=millis(); lastSensor = 1;}
  else if (s[6] == 1){flag_time=millis(); lastSensor = 2;}
  if (s[0] == 1 && s[6] == 1){flag_time=millis(); lastSensor = 7;}

  return error;
}


void line_follow(int error)
{
  int p, d, corr;
  p = kp * error;
  d = kd * (error - lastError);
  corr = p + d;
  wheel(base_L + corr, base_R - corr);
  lastError = error;
}



