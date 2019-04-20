#define ch3 3
#define ena 10
#define enb 11

void setup() {
  pinMode(ch3,INPUT);
  pinMode(ena ,OUTPUT);
  pinMode(enb,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int a,b;
  a=pulseIn(ch3, HIGH);
  Serial.print("CH-3: ");
  Serial.println(a);
  b=map(a,1156,2008,0,255);
  Serial.print("Mapped: ");
  Serial.println(b);
  analogWrite(10,b);
  analogWrite(11,b);

  delay(1000);
}
