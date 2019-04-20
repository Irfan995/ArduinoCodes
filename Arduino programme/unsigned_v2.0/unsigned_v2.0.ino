#define lf  8
#define lb  7
#define rf  12
#define rb  11
#define ena  9
#define enb  10

int state = 0;
int flag = 0;


void setup() 
{
  mot_init();
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()>0)
  {
    state = Serial.read();
    flag = 0;
  }
  
  if(state == '0')
  {
    analogWrite(ena, 250);
    analogWrite(enb, 250);
    digitalWrite(lf, LOW);
    digitalWrite(lb, HIGH);
    digitalWrite(rf, HIGH);
    digitalWrite(rb, LOW);
    
    if(flag == 0)
    {
      Serial.println("Left");
    flag = 1;
    }
   
  }
  if(state == '1')
  {
    
    analogWrite(ena, 250);
    analogWrite(enb, 250);
    digitalWrite(lf, HIGH);
    digitalWrite(lb, LOW);
    digitalWrite(rf, LOW);
    digitalWrite(rb, HIGH);

     if(flag == 0)
    {
      Serial.println("Right");
    flag = 1;
    }

  }
  if(state == '2')
  {
    analogWrite(ena, 0);
    analogWrite(enb, 0);
    digitalWrite(lf, HIGH);
    digitalWrite(lb, HIGH);
    digitalWrite(rf, HIGH);
    digitalWrite(rb, HIGH);

    if(flag == 0)
    {
      Serial.println("Nutral");
    flag = 1;
    }
  }
    
  if(state == '3')
  {
    analogWrite(ena, 100);
    analogWrite(enb, 100);
    digitalWrite(lf, HIGH);
    digitalWrite(lb, LOW);
    digitalWrite(rf, HIGH);
    digitalWrite(rb, LOW);

    
    if(flag == 0)
    {
      Serial.println("1st Gear Forward");
    flag = 1;
    }
  }

  if(state == '4')
  {
    analogWrite(ena, 180);
    analogWrite(enb, 180);
    digitalWrite(lf, HIGH);
    digitalWrite(lb, LOW);
    digitalWrite(rf, HIGH);
    digitalWrite(rb, LOW);

    
    if(flag == 0)
    {
      Serial.println("2nd Gear Forward");
    flag = 1;
    }
  }

   if(state == '5')
  {
    analogWrite(ena, 240);
    analogWrite(enb, 255);
    digitalWrite(lf, HIGH);
    digitalWrite(lb, LOW);
    digitalWrite(rf, HIGH);
    digitalWrite(rb, LOW);

    
    if(flag == 0)
    {
      Serial.println("3rd Gear Forward");
    flag = 1;
    }
  }

    if(state == '6')
  {
    analogWrite(ena, 200);
    analogWrite(enb, 200);
    digitalWrite(lf, LOW);
    digitalWrite(lb, HIGH);
    digitalWrite(rf, LOW);
    digitalWrite(rb, HIGH);

    
    if(flag == 0)
    {
      Serial.println("Reverse");
    flag = 1;
    }
  }

  if(state == '7')
  {
    analogWrite(ena, 0);
    analogWrite(enb, 0);
    digitalWrite(lf, HIGH);
    digitalWrite(lb, HIGH);
    digitalWrite(rf, HIGH);
    digitalWrite(rb, HIGH);

    
    if(flag == 0)
    {
      Serial.println("");
    flag = 1;
    }
  }
  

}



void mot_init()
{
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  digitalWrite(lf, HIGH);
  digitalWrite(lb, HIGH);
  digitalWrite(rf, HIGH);
  digitalWrite(rb, HIGH);
}
  

