
#define inA 10
#define inB 5
#define inC 9
#define inD 8
int ena=7;
int enb=6;
void setup() {
  pinMode(inA,OUTPUT);
  pinMode(inD,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
 
  
  // put your setup code here, to run once:

}

void loop() {  // analogWrite(leftenabler,100);
  // analogWrite(rightenabler,100);
  digitalWrite(inA,HIGH); 
  digitalWrite(inD,LOW);
  digitalWrite(inC,HIGH);
  digitalWrite(inB,LOW);
  delay(1000);
   analogWrite(ena,80);
   analogWrite(enb,80);
  // put your main code here, to run repeatedly:

}
