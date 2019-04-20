#define trigPinL 7
#define echoPinL 6
#define trigPinM 2
#define echoPinM 11
#define trigPinR 12
#define echoPinR 13

#define ena 10
#define enb 3
#define rf 8
#define rb 9
#define lf 5
#define lb 4



void setup() {
  Serial.begin(9600);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(trigPinM, OUTPUT);
  pinMode(echoPinM, INPUT);
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(lf,OUTPUT);
  pinMode(lb,OUTPUT);
  pinMode(rf,OUTPUT);
  pinMode(rb,OUTPUT);

  analogWrite(ena, 60);
  analogWrite(enb, 60);
  digitalWrite(lf,HIGH);
  digitalWrite(lb,HIGH);
  digitalWrite(rf,HIGH);
  digitalWrite(rb,HIGH);
  delay(500);

}

void loop() {
  
  int Ldistance, d1;
  digitalWrite(trigPinL, HIGH);
  delay(10);
  digitalWrite(trigPinL, LOW);
  d1 = pulseIn(echoPinL, HIGH);
  Ldistance = (d1/2)/29.1;
  Serial.print("Left:");
  Serial.print(Ldistance);
  Serial.print("    ");

  int Mdistance, d2;
  digitalWrite(trigPinM, HIGH);
  delay(10);
  digitalWrite(trigPinM, LOW);
  d2 = pulseIn(echoPinM, HIGH);
  Mdistance = (d2/2)/29.1;
  Serial.print("Middle:");
  Serial.print(Mdistance);
  Serial.print("    ");

  int Rdistance, d3;
  digitalWrite(trigPinR, HIGH);
  delay(10);
  digitalWrite(trigPinR, LOW);
  d3 = pulseIn(echoPinR, HIGH);
  Rdistance = (d3/2)/29.1;
  Serial.print("Right:");
  Serial.print(Rdistance);
  Serial.println(" ");


  if (Ldistance<15 && Mdistance>15 && Rdistance>15)
  {
    stp();
    delay(100);
    reverse();
    delay(250);
    right();
    delay(500);
  }

  else if(Rdistance<15 && Mdistance>15 && Ldistance>15)
  {
    stp();
    delay(100);
    reverse();
    delay(250);
    left();
    delay(500);
  }

  else if(Mdistance<15 && Ldistance>15 && Rdistance>15)
  {
    stp();
    delay(100);
    reverse();
    delay(250);
    forward();
    delay(750);
  }

  else if(Mdistance<15 && Ldistance<15 && Rdistance>15)
  {
    stp();
    delay(100);
    reverse();
    delay(250);
    right();
    delay(500);
  }

  else if(Mdistance<15 && Ldistance>15 && Rdistance<15)
  {
    stp();
    delay(100);
    reverse();
    delay(250);
    left();
    delay(500);
  }

  else if(Mdistance>15 && Ldistance<15 && Rdistance<15)
  {
    stp();
    delay(100);
    reverse();
    delay(500);
    left();
    delay(500);
  }

  else if(Mdistance>15 && Ldistance>15 && Rdistance>15)
  {
    forward();
  }

  else
  {
    stp();
    delay(100);
    reverse();
  }
}


void forward()
{
    analogWrite(ena,60);
    analogWrite(enb,60);
    digitalWrite(lf,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(rf, HIGH);
    digitalWrite(rb, LOW);
}

void reverse()
{
    analogWrite(ena,60);
    analogWrite(enb,60);
    digitalWrite(lf,LOW);
    digitalWrite(lb,HIGH);
    digitalWrite(rf, LOW);
    digitalWrite(rb, HIGH);
}

void left()
{
    analogWrite(ena,60);
    analogWrite(enb,60);
    digitalWrite(lf,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(rf, LOW);
    digitalWrite(rb, HIGH);
}

void right()
{
    analogWrite(ena,60);
    analogWrite(enb,60);
    digitalWrite(lf,LOW);
    digitalWrite(lb,HIGH);
    digitalWrite(rf, HIGH);
    digitalWrite(rb, LOW);
}

void stp()
{
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  digitalWrite(lf,HIGH);
  digitalWrite(lb,HIGH);
  digitalWrite(rf,HIGH);
  digitalWrite(rb,HIGH);
}

