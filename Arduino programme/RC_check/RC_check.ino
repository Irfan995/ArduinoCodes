#define ch1 2
#define ch2 3
#define ch4 4
#define ch5 5
#define ch6 6 
void setup() {
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  pinMode(ch4,INPUT);
  pinMode(ch5,INPUT);
  pinMode(ch6,INPUT);

  Serial.begin(9600);
}

void loop() {
  int a,b,c,d,e;
  a=pulseIn(ch1,HIGH);
  b=pulseIn(ch2,HIGH);
  c=pulseIn(ch4,HIGH);
  d=pulseIn(ch5,HIGH);
  e=pulseIn(ch6,HIGH);

  Serial.print("CH_1: ");
  Serial.print(a);
  Serial.print("    ");
  Serial.print("CH_2: ");
  Serial.print(b);
  Serial.print("    ");
  Serial.print("CH_4: ");
  Serial.print(c);
  Serial.print("    ");
  Serial.print("CH_5: ");
  Serial.print(d);
  Serial.print("    ");
  Serial.print("CH_6: ");
  Serial.println(e);
  
}
