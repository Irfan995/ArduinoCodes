int leftmotorf = 7;
int leftmotorb = 6;
int rightmotorf = 3;
int rightmotorb = 5;
int ena = 9;
int enb = 10;
int buzzerPin = 2;
int state = 0;
int flag = 0;


void setup() {
  pinMode(leftmotorf, OUTPUT);
  pinMode(leftmotorb, OUTPUT);
  pinMode(rightmotorf, OUTPUT);
  pinMode(rightmotorb, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  analogWrite(ena, 180);
  analogWrite(enb, 200);
  digitalWrite(buzzerPin, LOW);
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
    
    digitalWrite (leftmotorf, HIGH);
    digitalWrite (leftmotorb, LOW);
    digitalWrite (rightmotorf, HIGH);
    digitalWrite (rightmotorb, LOW);
    digitalWrite(buzzerPin, LOW);
    if(flag == 0)
    {
      Serial.println("Forward");
    flag = 1;
    }
   
  }
  if(state == '1')
  {
    
    digitalWrite (leftmotorf, LOW);
    digitalWrite (leftmotorb, LOW);
    analogWrite (rightmotorf, 125);
    digitalWrite (rightmotorb, LOW);
    digitalWrite(buzzerPin, LOW);
    if(flag == 0)
    {
      Serial.println("Left");
    flag = 1;
    }
   
  }
  if(state == '2')
  {
    
    digitalWrite (leftmotorf, LOW);
    digitalWrite (leftmotorb, LOW);
    digitalWrite (rightmotorf, LOW);
    digitalWrite (rightmotorb, LOW);
    digitalWrite(buzzerPin, LOW);
    if(flag == 0)
    {
      Serial.println("Stop");
    flag = 1;
    }
    
  }
  if(state == '3')
  {
    
    analogWrite (leftmotorf, 155);
    digitalWrite (leftmotorb, LOW);
    digitalWrite (rightmotorf, LOW);
    digitalWrite (rightmotorb, LOW);
    digitalWrite(buzzerPin, LOW);
    if(flag == 0)
    {
      Serial.println("Right");
    flag = 1;
    }
  }
  
  if(state == '4')
  {
    
    digitalWrite (leftmotorf, LOW);
    digitalWrite (leftmotorb, HIGH);
    digitalWrite (rightmotorf, LOW);
    digitalWrite (rightmotorb, HIGH);
    digitalWrite(buzzerPin, LOW);
    if(flag == 0)
    {
      Serial.println("Reverse");
    flag = 1;
    }
   
  }

   if(state == '5')
  {
    digitalWrite(buzzerPin, HIGH);
  }
  else if(state == '6')
  {
    digitalWrite(buzzerPin, LOW);
  }

}
  

