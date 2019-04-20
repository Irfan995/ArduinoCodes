#define CH1 11
#define CH2 6
#define CH3 10
#define CH4 5

int state = 0;
int flag = 0;


void setup()
{
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0)
  {
    state = Serial.read();
    flag = 0;
  }

  if (state == '0')
  {
    analogWrite(CH4, 200);
    analogWrite(CH2, 100);
    analogWrite(CH3, 100);
    analogWrite(CH1, 100);

    if (flag == 0)
    {
      Serial.println("Left");
      flag = 1;
    }

  }
  else if (state == '1')
  {
    analogWrite(CH4, 150);
    analogWrite(CH2, 100);
    analogWrite(CH3, 100);
    analogWrite(CH1, 100);

    if (flag == 0)
    {
      Serial.println("Right");
      flag = 1;
    }

  }
  else if (state == '2')
  {
    analogWrite(CH4, 100);
    analogWrite(CH2, 200);
    analogWrite(CH3, 100);
    analogWrite(CH1, 100);

    if (flag == 0)
    {
      Serial.println("Forward");
      flag = 1;
    }

  }
  else if (state == '3')
  {
    analogWrite(CH4, 100);
    analogWrite(CH2, 150);
    analogWrite(CH3, 100);
    analogWrite(CH1, 100);

    if (flag == 0)
    {
      Serial.println("Reverse");
      flag = 1;
    }

  }
  else if (state == '7')
  {
    analogWrite(CH4, 100);
    analogWrite(CH2, 100);
    analogWrite(CH3, 100);
    analogWrite(CH1, 100);

    if (flag == 0)
    {
      Serial.println("Fuck u!!!");
      flag = 1;
    }

  }
}

