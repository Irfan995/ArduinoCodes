#define ledPin 12
#define switchPin 11
#define lPot A1
#define tPot A2

int switchState = 0;

int val1 = 0;
int val2 = 0;

int lastVal1 = 0;
int lastVal2 = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(lPot, INPUT);
  pinMode(tPot, INPUT);

  Serial.begin(9600);
}

void loop()
{
  switchState = digitalRead(switchPin);

  if(switchState == 1)
  {
    digitalWrite(ledPin, HIGH);
    val1 = analogRead(lPot);
    val2 = analogRead(tPot);
    lastVal1 = val1;
    lastVal2 = val2;
    Serial.print(val1);
    Serial.print("    ");
    Serial.println(val2);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.print(lastVal1);
    Serial.print("    ");
    Serial.println(lastVal2);
  }
}

