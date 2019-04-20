#define S0 7
#define S1 6
#define S2 3
#define S3 4
#define output 2

int frequency = 0;

void setup()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(output, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  frequency = pulseIn(output, LOW);
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("    ");
  delay(10);


  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  frequency = pulseIn(output, LOW);
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("    ");
  delay(10);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  frequency = pulseIn(output, LOW);
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("    ");
  delay(250);
  
}

